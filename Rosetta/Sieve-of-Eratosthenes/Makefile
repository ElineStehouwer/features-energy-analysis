ifndef FILE
#$(error FILE is not set)
	FILE=sieve-of-eratosthenes.c
endif

ifndef TASK
#$(error TASK is not set)
	TASK=sieve-of-eratosthenes
endif

compile:
	gcc -Wall -O3 -march=native $(FILE) -o $(TASK).gcc_run 
	
compile-bc:
	gcc -Wall -O3 -march=native sieve-of-eratosthenes-bc.c -o sieve-of-eratosthenes-bc.gcc_run 

measure:
	./measure_bound_checks

run:
	seq 60 | xargs -I{} ./$(TASK).gcc_run

run-bc:
	seq 60 | xargs -I{} ./sieve-of-eratosthenes-bc.gcc_run 

mem:
	/usr/bin/time -v ./$(TASK).gcc_run
valmem:
		valgrind --tool=massif --stacks=yes  ./$(TASK).gcc_run

clean:
	rm -rf *.gcc_run
