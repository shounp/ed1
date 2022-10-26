CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LIBS=-lm
EXECUTAVEL=Exercicio2

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o Pilha.o Lista.o
	gcc main.o Pilha.o Lista.o $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc $(CFLAGS) -c main.c

Pilha.o: Pilha.c
	gcc $(CFLAGS) -c Pilha.c
	
Lista.o: Lista.c
	gcc $(CFLAGS) -c Lista.c


clean:
	rm -rf *.o $(EXECUTAVEL)


run: $(EXECUTAVEL)
	./$(EXECUTAVEL)

memcheck: $(EXECUTAVEL)
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL)