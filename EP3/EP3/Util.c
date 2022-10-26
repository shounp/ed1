/*
 * ESTE ARQUIVO NÃO PRECISA SER MODIFICADO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Util.h"

/**
 * @brief Retorna o menor entre dois valores
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int min(int a, int b) {
    return (a < b ? a : b);
}

/**
 * @brief Retorna o menor entre três valores
 * 
 * @param a 
 * @param b 
 * @param c 
 * @return int 
 */
int min3(int a, int b, int c) {
    return min(a, min(b, c));
}

/**
 * @brief Distância de edição (Edit Distance) 
 * Implementação baseada em:
 * https://www.geeksforgeeks.org/edit-distance-dp-5/
 * https://web.stanford.edu/class/cs124/lec/med.pdf 
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int distanciaEdicao(char *a, char *b) {
    int m = strlen(a), n = strlen(b);
    int dp[m+1][n+1];

    for (int i=0; i<=m; i++)
        dp[i][0] = i;
    for (int j=0; j<=n; j++)
        dp[0][j] = j;

    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i-1] != b[j-1]) {
                dp[i][j] = min3( 1 + dp[i-1][j], 1 + dp[i][j-1], 1 + dp[i-1][j-1]);
            }
            else
                dp[i][j] = dp[i-1][j-1];
        }
    }
    return dp[m][n];
}

/* Fonte:  http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html */
void *mallocSafe(size_t nbytes) {
    void *ptr;

    ptr = malloc(nbytes);
    if (ptr == NULL) {
        ERRO(Socorro !malloc devolveu NULL !);
        exit(EXIT_FAILURE);
    }

    return ptr;
}

/**
 * @brief Função auxiliar para contabiliar o tempo. 
 * Retorna o instante de tempo atual.
 * 
 * @return double 
 */
double MyClock() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}

/**
 * @brief Função auxiliar para remover as pontuação das palavras
 * 
 * @param palavra 
 */
void removePontuacao(String palavra) {
    int count = 0;
    for (int i = 0; palavra[i]; i++)
        if (!ispunct(palavra[i]) || palavra[i] == '-' || palavra[i] == '/')
            palavra[count++] = palavra[i];
    palavra[count] = '\0';
}

/**
 * @brief Converte o string para caracteres em minúsculo
 * 
 * @param str 
 */
void converteMinusculo(String str) {
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

/**
 * @brief Retornar a posição da última letra do string
 * 
 * @param str 
 * @return int 
 */
int encontraPosicaoUltimaLetra(String str) {
    for (int i = strlen(str) - 1; i >= 0; i--)
        if (isalpha(str[i]))
            return i;
    return 0;
}