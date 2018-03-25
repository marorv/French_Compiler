
CC=gcc
CFLAGS=-I.
DEPS = grammar.h
OBJ = main.o grammar.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

frenchComp: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY : clean
clean : $(OBJ)
	-rm $^