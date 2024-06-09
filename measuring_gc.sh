#!/bin/bash

get_idle_power_consumption1() {
    local l_idle_power_consumption=-1
    local sleep_time="$1"
    # Sla de electricity_consumed_total op.
    data_before=$(curl $ENERGY_STATS | grep -o '"electricity_consumed_total":[0-9.]*' | awk -F ':' '{print $2}')
    # echo "data before: $data_before"
    # Slaap voor 60 seconden.
    sleep $sleep_time
    # Sla de electricity_consumed_total weer op.
    data_after=$(curl $ENERGY_STATS | grep -o '"electricity_consumed_total":[0-9.]*' | awk -F ':' '{print $2}')
    # echo "data after: $data_after"
    # Doe after-before energy 
    local idle_energy_consumed=$(echo "$data_after - $data_before" | bc)
    # deel dat door 60. Dan heb je de idle energie per seconde.
    l_idle_power_consumption=$(echo "$idle_energy_consumed / $sleep_time" | bc -l)
    echo "$l_idle_power_consumption"
}

do_measurement () {
    local executable_path="$1"
    local num_execute="$2"
    data_before=$(curl $ENERGY_STATS | grep -o '"electricity_consumed_total":[0-9.]*' | awk -F ':' '{print $2}')
    # Run je programma.
    # elapsed_time=$( { time $executable_path; } 2>&1 )
    elapsed_time=$( { time seq $num_execute | xargs -I{} $executable_path; } 2>&1 )
    # En sla de electricity_consumed_total weer op.
    data_after=$(curl $ENERGY_STATS | grep -o '"electricity_consumed_total":[0-9.]*' | awk -F ':' '{print $2}')
    # echo "elapsed time: $elapsed_time"
    # Haal de electricity_consumed_total's weer van elkaar af. Dan heb je het totale energieverbruik inclusief het idle energie verbruik. 
    energy_consumed=$(echo "$data_after - $data_before" | bc)
    # echo "total consumed: $energy_consumed"
    # Bereken het idle energie verbruik tijdens het programma door de idle energie per seconde keer hoe lang het programma gerund heeft te doen.
    real_time=$(echo "$elapsed_time" | grep 'real' | awk '{print $2}')
    # echo "real_time: $real_time"
    total_seconds=$(echo $real_time | awk -Fm '{print $1 * 60 + $2}' | bc -l)
    # echo "total_seconds: $total_seconds"
    echo "$energy_consumed $total_seconds"
}
get_program_power_and_time_consumption1 () {
    local executable_path="$1"
    local num_runs="$2"
    local num_execute="$3"
    # Pak de idle power consumption:
    local idle_before=$(get_idle_power_consumption1 60)
    echo "$idle_before"
    local result=$(do_measurement "$executable_path" "$num_execute")
    local energy_consumed=$(echo $result | awk '{print $1}')
    local total_seconds=$(echo $result | awk '{print $2}')
    echo "total consumed: $energy_consumed"
    echo "total_seconds: $total_seconds"
    # Determine idle energy consumptie again
    local idle_after=$(get_idle_power_consumption1 60)
    echo "after: $idle_after"
    local diff=""
    local ten_percent=""
    if (( $(echo "$idle_before <= $idle_after" | bc -l) )); then 
        diff=$(echo "$idle_after - $idle_before" | bc -l)
        ten_percent=$(echo "$idle_after * 0.05" | bc -l)
        echo "ten_percent: $ten_percent"
    else
        diff=$(echo "$idle_before - $idle_after" | bc -l)
        ten_percent=$(echo "$idle_before * 0.05" | bc -l)
        echo "ten_percent: $ten_percent"
    fi
    echo "diff: $diff"

    if (( $(echo "$diff <= $ten_percent" | bc -l) )); then
        echo "The values are within 05 percent range of each other."
        idle_energy_consumed=$(echo "$total_seconds * $idle_after" | bc -l)
        echo "idle energy: $idle_energy_consumed"
        # Haal dit van het totale energieverbruik van het programma af en dan heb je het energieverbruik van het programma zelf.
        actual_energy_consumed=$(echo "$energy_consumed - $idle_energy_consumed" | bc -l)
        echo "actually consumed: $actual_energy_consumed"
    else
        echo "The values are not within 05 percent range of each other."
        local no_iter=0
        while (( $(echo "$diff > $ten_percent" | bc -l) ));
        do
            echo "The values are not within 05 percent range of each other."
            if [ "$no_iter" -eq 10 ] 
            then
                break
            fi
            idle_before=$(get_idle_power_consumption1 60)
            echo "$idle_before"

            result=$(do_measurement "$executable_path" "$num_execute")
            energy_consumed=$(echo $result | awk '{print $1}')
            total_seconds=$(echo $result | awk '{print $2}')
            echo "total consumed: $energy_consumed"
            echo "total_seconds: $total_seconds"
            local idle_after=$(get_idle_power_consumption1 60)
            echo "after: $idle_after"
            if (( $(echo "$idle_before <= $idle_after" | bc -l) )); then 
                diff=$(echo "$idle_after - $idle_before" | bc -l)
                ten_percent=$(echo "$idle_after * 0.05" | bc -l)
                echo "ten_percent: $ten_percent"
            else
                diff=$(echo "$idle_before - $idle_after" | bc -l)
                ten_percent=$(echo "$idle_before * 0.05" | bc -l)
                echo "ten_percent: $ten_percent"
            fi
            echo "diff: $diff"

            no_iter=$((no_iter + 1))
        done
        if (( $(echo "$diff <= $ten_percent" | bc -l) )); then
            echo "The values are within 05 percent range of each other."
            idle_energy_consumed=$(echo "$total_seconds * $idle_after" | bc -l)
            echo "idle energy: $idle_energy_consumed"
            # Haal dit van het totale energieverbruik van het programma af en dan heb je het energieverbruik van het programma zelf.
            actual_energy_consumed=$(echo "$energy_consumed - $idle_energy_consumed" | bc -l)
            echo "actually consumed: $actual_energy_consumed"
        fi
    fi
}


# get_idle_power_consumption
# echo "idle consumption: $idle_power_consumption"
section_to_execute="$1"

num_runs=3
for ((i=1; i<=$num_runs; i++)); do
    if [ "$section_to_execute" -eq 1 ]
    then
        executable_path="Rosetta/Avl-tree/garbage-collect/use-avl-tree-gc.gcc_run"
        echo "$executable_path"
        get_program_power_and_time_consumption1 "$executable_path" "$num_runs" 7200
    fi
    if [ "$section_to_execute" -eq 2 ]
    then    
        executable_path="Rosetta/Binary-digits/garbage-collect/binary-digits-gc.gcc_run"
        echo "$executable_path"
        get_program_power_and_time_consumption1 "$executable_path" "$num_runs" 51200
    fi
    if [ "$section_to_execute" -eq 3 ]
    then    
        executable_path="Rosetta/Binary-digits/garbage-collect-plus/binary-digits-gc-bc.gcc_run"
        echo "$executable_path"
        get_program_power_and_time_consumption1 "$executable_path" "$num_runs" 51200
    fi  
    if [ "$section_to_execute" -eq 4 ]
    then    
        executable_path="Rosetta/Factors-of-an-integer/garbage-collect/factors-of-an-integer-gc.gcc_run"
        echo "$executable_path"
        get_program_power_and_time_consumption1 "$executable_path" "$num_runs" 51200
    fi
    if [ "$section_to_execute" -eq 5 ]
    then
        executable_path="Rosetta/Factors-of-an-integer/garbage-collect-plus/factors-of-an-integer-gc-bc.gcc_run"
        echo "$executable_path"
        get_program_power_and_time_consumption1 "$executable_path" "$num_runs" 51200
    fi
    if [ "$section_to_execute" -eq 6 ]
    then            
        executable_path="Rosetta/Sorting-algorithms-Merge-sort/garbage-collect/sorting-algorithms-merge-sort-gc.gcc_run"
        echo "$executable_path"
        get_program_power_and_time_consumption1 "$executable_path" "$num_runs" 22000
    fi
    if [ "$section_to_execute" -eq 7 ]
    then        
        executable_path="Rosetta/Sorting-algorithms-Merge-sort/garbage-collect-plus/sorting-algorithms-merge-sort-gc-bc.gcc_run"
        echo "$executable_path"
        get_program_power_and_time_consumption1 "$executable_path" "$num_runs" 22000
    fi
    echo "================================NEW RUN================================"
done
