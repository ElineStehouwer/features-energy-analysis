ifndef FILE
#$(error FILE is not set)
	FILE=factors-of-an-integer.c
endif

ifndef TASK
#$(error TASK is not set)
	TASK=factors-of-an-integer
endif

compile:
	gcc -Wall -O3 -march=native $(FILE) -o $(TASK).gcc_run 
	
compile-bc:
	gcc -Wall -O3 -march=native factors-of-an-integer-bc.c -o factors-of-an-integer-bc.gcc_run 

measure:
	./measure_bound_checks

run:
	seq 60 | xargs -I{} ./$(TASK).gcc_run > outnorm.txt

run-bc:
	seq 60 | xargs -I{} ./factors-of-an-integer-bc.gcc_run > outbc.txt

mem:
	/usr/bin/time -v ./$(TASK).gcc_run
valmem:
		valgrind --tool=massif --stacks=yes  ./$(TASK).gcc_run

clean:
	rm -rf *.gcc_run
