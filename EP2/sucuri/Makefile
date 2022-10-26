CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LIBS=-lm
EXECUTAVEL=Sucuri

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o Pilha.o Util.o Fila.o Objeto.o Lexer.o Categorias.o Posfixa.o Avalia.o
	@echo Criando arquivo executável: $@
	@gcc main.o Pilha.o Util.o Fila.o Objeto.o Lexer.o Categorias.o Posfixa.o Avalia.o $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	@echo Compilando arquivo objeto: $@
	@gcc $(CFLAGS) -c main.c

Pilha.o: Pilha.c
	@echo Compilando arquivo objeto: $@
	@gcc $(CFLAGS) -c Pilha.c

Fila.o: Fila.c
	@echo Compilando arquivo objeto: $@
	@gcc $(CFLAGS) -c Fila.c

Objeto.o: Objeto.c
	@echo Compilando arquivo objeto: $@
	@gcc $(CFLAGS) -c Objeto.c

Lexer.o: Lexer.c
	@echo Compilando arquivo objeto: $@
	@gcc $(CFLAGS) -c Lexer.c

Util.o: Util.c
	@echo Compilando arquivo objeto: $@
	@gcc $(CFLAGS) -c Util.c

Categorias.o: Categorias.c
	@echo Compilando arquivo objeto: $@
	@gcc $(CFLAGS) -c Categorias.c

Posfixa.o: Posfixa.c
	@echo Compilando arquivo objeto: $@
	@gcc $(CFLAGS) -c Posfixa.c

Avalia.o: Avalia.c
	@echo Compilando arquivo objeto: $@
	@gcc $(CFLAGS) -c Avalia.c

clean: 
	@echo Apagando os arquivos
	@rm -rf *.o $(EXECUTAVEL)

# Você pode retirar a opção '-e' e '-s expressoes.txt' para executar o Suciri em modo Shell
run: $(EXECUTAVEL) 
	./$(EXECUTAVEL) -e -s expressoes.txt

#Executa o Sucuri no modo Shell sem exibir a expressão em notação pós-fixa 
# run: $(EXECUTAVEL) 
# 	./$(EXECUTAVEL) 

#Executa o modo Shell do Sucuri exibindo a expressão em notação pós-fixa
# run: $(EXECUTAVEL) 
# 	./$(EXECUTAVEL) -e

#Executa o Sucuri no modo script sem exibir a expressão em notação pós-fixa
# run: $(EXECUTAVEL) 
# 	./$(EXECUTAVEL) -s expressoes.txt
	
memcheck: $(EXECUTAVEL)
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL) -e -s expressoes.txt

