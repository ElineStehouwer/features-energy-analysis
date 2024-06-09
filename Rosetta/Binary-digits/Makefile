ifndef FILE
#$(error FILE is not set)
	FILE=binary-digits.c
endif

ifndef TASK
#$(error TASK is not set)
	TASK=binary-digits
endif

compile:
	gcc -Wall -O3 -march=native $(FILE) -o $(TASK).gcc_run -lm
	
compile-bc:
	gcc -Wall -O3 -march=native binary-digits-bc.c -o binary-digits-bc.gcc_run -lm

measure:
	./measure_bound_checks

run:
	seq 60 | xargs -I{}  ./$(TASK).gcc_run

run-bc:
	seq 60 | xargs -I{}  ./binary-digits-bc.gcc_run

mem:
	/usr/bin/time -v ./$(TASK).gcc_run
valmem:
		valgrind --tool=massif --stacks=yes  ./$(TASK).gcc_run

clean:
	rm -rf *.gcc_run
