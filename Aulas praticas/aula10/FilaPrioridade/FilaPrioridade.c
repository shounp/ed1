#include <stdio.h>
#include <stdlib.h>

#include "FilaPrioridade.h"

/* Se precisar/quiser, pode criar outros structs */

struct filaprio {
    /* Preencha com os campos necessários*/
};

/**
 * @brief Faz a alocação de memória para a Fila de Prioridade
 * 
 * @return FilaPrioridade* 
 */
FilaPrioridade *criaFP() {
    return NULL;
}

/**
 * @brief Faz a liberação de memória dinamicamente alocada 
 * por cada nó da Fila de Prioridade
 * 
 * @param fp Ponteiro para a fila de prioridade que deve ser desalocada
 */
void liberaFP(FilaPrioridade *fp) {

}

/**
 * @brief Insere um elemento na fila, onde o seu valor indica a prioridade (quanto maior, maior a prioridade)
 * 
 * @param fp Ponteiro para a fila de prioridade onde o elemento deve ser inserido
 * @param v Valor do elemento a ser inserido
 */
void insere(FilaPrioridade *fp, int v) {
    
}

/**
 * @brief Remove o elemento de maior prioridade
 * 
 * @param fp Ponteiro para a fila de prioridade
 */
void removeMax(FilaPrioridade *fp) {
}

/**
 * @brief Retorna o elemento de maior prioridade
 * 
 * @param fp Ponteiro para a fila de prioridade
 * @return int 
 */
int primeiro(FilaPrioridade *fp) {
    
    return 0;
}

/**
 * @brief Retorna true se a fila de prioridade estiver vazia e false, caso contrário.
 * 
 * @param fp Ponteiro para a fila de prioridade a ser verificada
 * @return true ou false
 */
bool FPVazia(FilaPrioridade *fp) {
    return true;
}

/**
 * @brief Retorna true se a fila de prioridade estiver cheia e false, caso contrário.
 * 
 * @param fp Ponteiro para a fila de prioridade a ser verificada
 * @return true ou false
 */
bool FPCheia(FilaPrioridade *fp) {
    return true;
}

/**
 * @brief Retorna o número de elementos na fila de prioridade
 * 
 * @param fp Ponteiro para a fila de prioridade a ser verificada
 * @return int 
 */
int tamanhoFP(FilaPrioridade *fp) {
    return 0;
}


