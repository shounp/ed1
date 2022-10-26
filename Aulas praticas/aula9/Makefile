CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LIBS=-lm
EXECUTAVEL=TADaula9

all: $(EXECUTAVEL)

$(EXECUTAVEL): ex3.o
	gcc ex3.o $(LIBS) -o $(EXECUTAVEL)

ex3.o: ex3.c
	gcc $(CFLAGS) -c ex3.c

clean:
	rm -rf *.o $(EXECUTAVEL)

memcheck: $(EXECUTAVEL)
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL)

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)