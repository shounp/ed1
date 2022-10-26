#include <stdio.h>
#include <stdlib.h>

#include "Deque.h"

typedef struct no {
    int dado;
    /* Preencha com os outros campos necessários*/
}No;

struct deque {
    /* Preencha com os campos necessários*/
};

/**
 * @brief Faz a alocação de memória para a deque
 * 
 * @return Deque* 
 */
Deque *criaDeque() {
    return NULL;
}

/**
 * @brief Faz a liberação de memória dinamicamente alocada 
 * por cada no da deque
 * 
 * @param deque Ponteiro para a deque que deve ser desalocada
 */
void liberaDeque(Deque *deque) {
    
}

/**
 * @brief Insere um elemento no início da dequee
 * 
 * @param deque Ponteiro para a deque onde o elemento deve ser inserido
 * @param valor Valor do elemento a ser inserido
 */
void push_front(Deque *deque, int valor) {

}

/**
 * @brief Insere um elemento no fim da deque
 * 
 * @param deque Ponteiro para a deque onde o elemento deve ser inserido
 * @param valor Valor do elemento a ser inserido
 */
void push_back(Deque *deque, int valor) {

}

/**
 * @brief Remove o primeiro elemento da deque
 * 
 * @param deque Ponteiro para a deque na qual o elemento deve ser removido
 */
void pop_front(Deque *deque) {

}

/**
 * @brief Remove o último elemento da deque
 * 
 * @param deque Ponteiro para a deque na qual o elemento deve ser removido
 */
void pop_back(Deque *deque) {

}

/**
 * @brief Retorna (sem remover) o primeiro elemento da deque
 * 
 * @param deque Ponteiro para a deque que se deseja ter acesso ao primeiro elemento
 * @return int 
 */
int front(Deque *deque) {

}

/**
 * @brief Retorna (sem remover) o último elemento da deque
 * 
 * @param deque Ponteiro para a deque que se deseja ter acesso ao último elemento
 * @return int 
 */
int back(Deque *deque) {

}

/**
 * @brief Retorna true se a deque estiver vazia e false, caso contrário.
 * 
 * @param deque Ponteiro para a deque a ser verificada
 * @return true ou false
 */
bool dequeVazia(Deque *deque) {

    return true;
}

/**
 * @brief Retorna o número de elementos na deque
 * 
 * @param deque Ponteiro para a deque a ser verificada
 * @return int 
 */
int tamanhoDeque(Deque *deque) {

    return 0;
}
