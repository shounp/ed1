CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LIBS=-lm
EXECUTAVEL=Lista

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o Lista.o Objetos.o
	gcc main.o Lista.o Objetos.o $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc $(CFLAGS) -c main.c

Lista.o: Lista.c
	gcc $(CFLAGS) -c Lista.c

Objetos.o: Objetos.c
	gcc $(CFLAGS) -c Objetos.c

clean:
	rm -rf *.o $(EXECUTAVEL)

memcheck: $(EXECUTAVEL)
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL)

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)