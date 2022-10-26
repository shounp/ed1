#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

struct fila {
    Objeto *inicio;
    Objeto *fim;
    int n;
};

/**
 * @brief Faz a alocação de memória para a Fila
 * 
 * @return Fila* 
 */
Fila *criaFila() {
    Fila *f = mallocSafe(sizeof(Fila));
    f->inicio = f->fim = NULL;
    f->n = 0;
    return f;
}

/* Faz a desalocação da fila */
/**
 * @brief Faz a liberação de memória dinamicamente alocada 
 * por cada objeto da Fila
 * 
 * @param fila Ponteiro para a fila que deve ser desalocada
 */
void liberaFila(Fila *fila) {
    AVISO(Fila.c: ainda não completei a função 'liberaFila');
    
}

/**
 * @brief Insere um novo objeto a fila. Como é passado um poteiro do objeto
 * a ser inserido, você pode:
 * - inserí-lo apenas fazendo com que o último elemento atual da fila aponte para 
 * esse objeto e fila->fim passa a apontar para esse objeto; ou
 * - criar uma cópia do objeto e inserir essa cópia no fim da fila.
 * 
 * @param fila Ponteiro para a fila onde o objeto deve ser inserido
 * @param objeto Objeto a ser inserido
 */
void enqueue(Fila *fila, Objeto *objeto) {
    AVISO(Fila.c: ainda não completei a função 'enqueue');
    
}

/**
 * @brief Remove (apaga) o primeiro objeto da fila
 * 
 * @param fila Ponteiro para a fila
 */
void dequeue(Fila *fila) {
    AVISO(Fila.c: ainda não completei a função 'dequeue');
    
}

/**
 * @brief Retorna (sem apagar) o primeiro objeto da fila
 * 
 * @param fila Ponteiro para a fila
 * @return Objeto* 
 */
Objeto *front(Fila *fila) {
    AVISO(Fila.c: ainda não completei a função 'front');

    return NULL;
}

/**
 * @brief Verifica se a fila está vazia 
 * 
 * @param fila Ponteiro para a fila
 * @return true ou false
 */
bool filaVazia(Fila *fila) {
    return (fila==NULL || fila->n == 0);
}

/**
 * @brief Retorna o número de elementos na fila
 * 
 * @param fila Ponteiro para a fila
 * @return int 
 */
int tamanhoFila(Fila *fila) {
    if (filaVazia(fila))
        return 0;
    return fila->n;
}

/**
 * @brief Retorna uma cópia (independente) da fila passada como parâmetro
 * 
 * @param fila Ponteiro para a fila que se deseja copiar
 * @return Fila* 
 */
Fila *copiaFila(Fila *fila) {
    AVISO(Fila.c: ainda não completei a função 'copiaFila');

    return NULL;
}

/**
 * @brief Fução que imprime os elementos da fila. 
 * Essa função pode ajudar a detectar problemas nos objetos da fila
 * Para imprimir um objeto, use (chame) a função imprimeObjeto.
 * 
 * @param fila Ponteiro para a fila que se deseja imprimeir
 * @param tipo Tipo da impressão (veja a função imprimeObjeto no arquivo Objeto.c)
 */
void imprimeFila(Fila *fila, int tipo) {

}

/**
 * @brief Função de Alta Ordem que recebe uma fila e uma função (modificaObjeto).
 * Para cada objeto da fila, aplique a função 'modificaObjeto' ao objeto.
 * 
 * @param fila 
 * @param modificaObjeto 
 */
void converteElementosFila(Fila *fila, void (*modificaObjeto)(Objeto *)) {
    AVISO(Fila.c: ainda não completei a função 'converteElementosFila');
    
}