## Makefile ##
EXECUTAVEL=TADRacional
LIBS=-lm
CFLAGS = -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o Racional.o
	@echo Criando arquivo executável: $@
	@gcc main.o Racional.o $(LIBS) -o $(EXECUTAVEL)


main.o: main.c
	@echo Compilando arquivo objeto: $@
	@gcc $(CFLAGS) -c main.c

Racional.o: Racional.c
	@echo Compilando arquivo objeto: $@
	@gcc $(CFLAGS) -c Racional.c

clean:
	rm -rf *.o $(EXECUTAVEL)

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)

memcheck: $(EXECUTAVEL)
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL)