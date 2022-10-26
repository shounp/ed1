/*
 * ESTE ARQUIVO NÃO DEVE SER MODIFICADO, APENAS ENTENDA O QUE CADA FUNÇÃO FAZ
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Lexer.h"
#include "Util.h"
#include "Categorias.h"
#include "Objeto.h"

/*Baseando em: https://www.geeksforgeeks.org/c-program-detect-tokens-c-program */

/* Mensagens de erro de sintaxe */
#define SYNTAX_ERROR(pos,erroMsg)  \
    fprintf(stderr, "    %s\n", linha);  \
    fprintf(stderr, "    %*c^\n", pos, ' ');  \
    ERRO(criaFilaObjetos em Lexer.c: erroMsg);

/*
 * Whitespace characters: space, horizontal tab, vertical tab, form feed, newline
 * http://en.wikipedia.org/wiki/C_language
*/
static const char *whiteSpace = " \t\v\f\n";

/* Caracteres dos Operadores */
static const char *carOperadores = "^%*/+-_";

/**
 * @brief Verifica se o string é um delimitador
 * 
 * @param ch 
 * @return true ou false
 */
bool isDelimiter(char ch) {
	return (strchr(whiteSpace, ch) || strchr(carOperadores, ch) || ch == '(' || ch == ')' || ( ch != '.'  && ispunct(ch)));
}

/**
 * @brief Verifica se o string é um operador (ou parênteses)
 * 
 * @param ch 
 * @return true ou false
 */
bool isOperator(char ch) {
    return (strchr(carOperadores, ch) || ch == '(' || ch == ')');
}


/**
 * @brief Verifica se o string é um identificador válido
 * 
 * @param str 
 * @return true ou false
 */
bool validIdentifier(char* str) {
    return ( isalpha(str[0]) );
}

/**
 * @brief Verifica se o string 'str' contém um número inteiro.
 * 
 * @param str: String a ser testado
 * @return true ou false
 */
bool isInteger(char* str) {
	int i, len = strlen(str);
	if (len == 0)
		return false;
	for (i = 0; i < len; i++) {
		if (!isdigit(str[i]) || (str[i] == '-' && i > 0))
			return false;
	}
	return true;
}

/**
 * @brief Verifica se o string 'str' contém um número real.
 * 
 * @param str: String a ser testado
 * @return true ou false
 */
bool isRealNumber(char* str) {
	int i, len = strlen(str);
	bool hasDecimal = false;
	if (len == 0)
		return false;
	for (i = 0; i < len; i++) {
        if ( (!isdigit(str[i]) && str[i] != '.') || (str[i] == '-' && i > 0))
            return false;
        if (str[i] == '.' && hasDecimal) { // Garante que o string só contenha um '.'
			return false;
		}
		if (str[i] == '.')
			hasDecimal = true;
    }
	return hasDecimal;
}

/**
 * @brief Remove os espaços em branco do string 'str'
 * 
 * @param str 
 */
void removeSpaces(char *str) {
	int count = 0;
	for (int i = 0; str[i]; i++)
		if (!strchr(whiteSpace, str[i]))
			str[count++] = str[i];
	str[count] = '\0';
}

/**
 * @brief Gera um substring de 'str' da posição 'left' à posição 'right'
 * 
 * @param str 
 * @param left 
 * @param right 
 * @return char* 
 */
char* subString(char* str, int left, int right) {
	int i;
	char *subStr = mallocSafe(sizeof(char) * (right - left + 2));
	for (i = left; i <= right; i++)
		subStr[i - left] = str[i];
	subStr[right - left + 1] = '\0';
	return subStr;
}

/**
 * @brief Separa o string em operadores, operandos e delimitadores. Ao fim, é 
 * retornado uma fila de objetos.
 * 
 * @param linha 
 * @return Fila* 
 */
Fila *criaFilaObjetos(String linha) {
	Fila *filaObjetos = criaFila();
	int left = 0, right = 0;
	
	//Para simplificar, removemos os espaços em brancos
	removeSpaces(linha);

	int len = strlen(linha);

	while (right <= len && left <= right) {

		Objeto *objeto = NULL;
		bool encontrouObjeto = false;

		while ( (right < len) && (!isDelimiter(linha[right]) ) ) {
			right++;
		}

		if (left == right && linha[right] == '\0')
			break;

		if ( isDelimiter(linha[right]) && left == right ) {
			encontrouObjeto = true;
			if ( isOperator(linha[right]) ) {
				/* procura pelo operador */
				int j = 0;
				while (j < MAX_SIMBOLOS && strncmp(&linha[right], getOperador(j), strlen(getOperador(j)))) {
					j++;
				}
				if (j == MAX_SIMBOLOS){ /* Não encontrou o operador... erro */
					SYNTAX_ERROR(right, ErroSintaxe: sintaxe inválida!);
				}
				else {
					objeto = criaObjeto();
					objeto->categoria = j;
					objeto->valor.pStr = getOperador(j);
				}
			}
			right++;
			left = right;
		} 
		else if ( (isDelimiter(linha[right]) && left != right) || (right == len && left != right)) {
			String subStr = subString(linha, left, right - 1);
			encontrouObjeto = true;
			/* Encontramos um número inteiro */
			if ( isInteger(subStr) ) {
				objeto = criaObjeto();
				objeto->categoria = INT_STR;
				objeto->valor.pStr = subStr;
			}
			/* Encontramos um número real */
			else if ( isRealNumber(subStr) ) {
				objeto = criaObjeto();
				objeto->categoria = FLOAT_STR;
				objeto->valor.pStr = subStr;
			}
			else {
				free(subStr);
			}
			left = right;
		}
		/* Ocorreu algum erro */
		if (objeto == NULL) {
			if (encontrouObjeto){
				right--;
			}
			/* Se chegou aqui teve algum problema */
			SYNTAX_ERROR(right, ErroSintaxe: sintaxe inválida!);
			liberaFila(filaObjetos);
			return NULL; /* abandonamos a linha */
		} else { // Está tudo certo, então adicionamos o objeto na fila
			//imprimeObjeto(objeto, ITEM);
			enqueue(filaObjetos, objeto);
		}

	}
	return filaObjetos;
}

