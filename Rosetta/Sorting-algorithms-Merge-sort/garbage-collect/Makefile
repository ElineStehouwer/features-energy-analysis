ifndef FILE
#$(error FILE is not set)
	FILE=sorting-algorithms-merge-sort-gc.c
endif

ifndef TASK
#$(error TASK is not set)
	TASK=sorting-algorithms-merge-sort-gc
endif

compile:
	gcc -Wall -O3 -march=native -I/usr/gc/include $(FILE) /usr/gc/lib/libgc.so -o $(TASK).gcc_run -lm
	
measure:
	./measure_bound_checks

run:
	seq 60 | xargs -I{}  ./$(TASK).gcc_run

mem:
	/usr/bin/time -v ./$(TASK).gcc_run
valmem:
		valgrind --tool=massif --stacks=yes  ./$(TASK).gcc_run

clean:
	rm -rf *.gcc_run
