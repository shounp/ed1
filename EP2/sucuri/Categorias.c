/*
 * ESTE ARQUIVO NÃO DEVE SER MODIFICADO, APENAS ENTENDA O QUE CADA FUNÇÃO FAZ
 */
#include <stdio.h>
#include <stdlib.h>

#include "Categorias.h"

/**
 * @brief Nome das possíveis categorias dos objetos
 * 
 */
static char *nomeCategoria[MAX_CATEGORIAS] = {
    /* 6 operadores aritmeticos com 1 simbolo */
    /* "^",  0  */  "operador aritmetico exponenciacao" 
    /* "%",  1  */ ,"operador aritmetico resto de divisao"
    /* "*",  2  */ ,"operador aritmetico multiplicacao"
    /* "/",  3  */ ,"operador aritmetico divisao"
    /* "+",  4  */ ,"operador aritmetico adicao"
    /* "-",  5  */ ,"operador aritmetico subtracao"
    /* "_",  6  */ ,"operador aritmetico \"menos unario\""

    /* parenteses */ 
    /* "(" , 7 */  ,"abre parenteses" 
    /* ")" , 8 */  ,"fecha parenteses"    

    /* constantes */
    /* 9 */        ,"string representando float"
    /* 10 */       ,"string representando int"

    /* Objetos */
    /* 11 */       ,"valor float"
    /* 12 */       ,"valor int"

    /* identificador */
    /* 13 */       ,"indefinida" 
};

/**
 * @brief Imprime o nome da categoria de acordo com o vetor 'nomeCategoria'
 * 
 * @param i Categoria que se deseja imprimir o nome
 */
void imprimeNomeCategoria(int i) {
    if (i < 0 || i > MAX_CATEGORIAS)
        printf("ERRO: Categoria inválida\n");
    printf("%s\n", nomeCategoria[i]);
}

/**
 * @brief Retorna o nome da categoria de acordo com o vetor 'nomeCategoria'
 * 
 * @param i Categoria que se deseja obter o nome
 * @return char* 
 */
char *getNomeCategoria(int i) {
    if (i < 0 || i > MAX_CATEGORIAS) {
        printf("ERRO: Categoria inválida\n");
        return " ";
    }
    return nomeCategoria[i];
}