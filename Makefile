OBJECTS = helper.o
DEPS = fib.o fib_mem.o
HEADERS = helper.h
FLAGS = -std=c99 -lm

default: all 

%.o: %.c $(HEADERS)
	gcc -c $< $(FLAGS) -o $@

all: $(OBJECTS) $(DEPS)
	-make memo
	-make nomemo
	-make clean
	-ls

memo: $(OBJECTS) fib_mem.o
	gcc fib_mem.o $(OBJECTS) $(FLAGS) -o $@ 

nomemo: $(OBJECTS) fib.o
	gcc fib.o $(OBJECTS) $(FLAGS) -o $@

clean:
	-rm -f $(OBJECTS) $(DEPS) _fib.log
	
destroy:
	-make clean
	-rm -f mem* nomem* _fib.log
