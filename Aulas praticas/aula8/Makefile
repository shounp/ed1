CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LIBS=-lm
EXECUTAVEL=TADConjunto

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o Conjunto.o
	gcc main.o Conjunto.o $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc $(CFLAGS) -c main.c

Conjunto.o: Conjunto.c
	gcc $(CFLAGS) -c Conjunto.c

clean:
	rm -rf *.o $(EXECUTAVEL)

memcheck: $(EXECUTAVEL)
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL)

run: $(EXECUTAVEL)
	chcp 65001
	./$(EXECUTAVEL)