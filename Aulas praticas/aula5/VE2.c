#include <stdio.h>
#include <stdlib.h>

#include "VE2.h"

struct ve2 {
    int capacidade; //Tamanho do array F
    int ini;        //Posicao do "primeiro" elemento
    int fim;        //Posição livre onde um elemento deve ser inserido
    int n;          //Número de elementos na estrutura
    int *F;         //Array para armazenar os elementos
};

VE2 *criaVE2(int capacidade) {
    /*Verifique se o valor em capacidade é válido */
    /*Se for, inicialize n, ini e fim com 0 (indicando que a estrutura está vazia) */
    /*Aloque o array 'F' e retorne o ponteiro da estrutura */
    if(capacidade == 0){
        printf("A capacidade deve ser diferente de 0!\n");
        return NULL;
    }
    VE2 *r = malloc(sizeof(VE2));
    if(r == NULL){
        fprintf(stderr, "sem memoria!\n");
        exit(1);
    }
    r->capacidade = capacidade;
    r->ini = 0;
    r->fim = 0;
    r->n = 0;
    r->F = malloc(capacidade*sizeof(int));
    if(r->F == NULL){
        fprintf(stderr, "Sem memória!\n");
        exit(1);
    }
    return r;
}

void liberaVE2(VE2 *ve) {
    /* Faz a desalocação de memória */
    if(ve == NULL){
        return;
    }
    if(ve->F != NULL)
        free(ve->F);
    free(ve);
    ve = NULL;
}

void adicionaVE2(VE2 *ve, int v) {
    /* Adiciona um elemento no fim do vetor */
    /* Lembre-se de verificar se há espaço para adicionar o elemento */
    /* Complexidade: O(1)  */
    if(ve == NULL){
        printf("vetor nao alocado\n");
        return;
    }
    if(ve->n == ve->capacidade){
        printf("vetor cheio\n");
    }
    else{
        ve->F[ve->fim] = v;
        ve->fim = (ve->fim+1) % ve->capacidade;
        ve->n++;
    }
}

void removeVE2(VE2 *ve) {
    /* Retira o ultimo elemento*/
    /* Complexidade: O(1)  */
    if(ve == NULL){
        printf("vetor nao alocado\n");
        return;
    }
    else if(ve->n == 0){
        printf("nenhuma posicao para ser removido\n");
    }
    else{
        ve->F[ve->ini] = 0;
        ve->ini = (ve->ini+1) % ve->capacidade;
        ve->n--;
    }
}

int obtemElementoVE2(VE2 *ve){
    /*Retorna o elemento ultimo */
    /* Complexidade: O(1)  */
    if(ve == NULL){
        printf("vetor nao alocado\n");
        return -1;
    }
    else{
        return ve->F[ve->ini];
    }
}

int vazioVE2(VE2 *ve) {
    /* Verifica se a estrutura está vazia */
    /* Complexidade: O(???)  */
    if(ve == NULL){
        printf("vetor nao alocado\n");
        return -1;
    }
    else if(ve->n > 0){
        return 0;
    }
    else
        return 1;
}

int cheioVE2(VE2 *ve) {
    /* Verifica se a estrutura está cheia */
    /* Complexidade: O(1)  */

    if(ve == NULL){
        printf("vetor nao alocado\n");
        return 0;
    }
    else if(ve->n == ve->capacidade){
        return 1;
    }
    else
        return 0;

}

int tamanhoVE2(VE2 *ve) {
    /* Retorna o número de elementos que a estrutura armazena */
    /* Complexidade: O(1)  */
    if(ve==NULL){
        printf("vetor nao alocado\n");
        return 0;
    }
    else
        return ve->n;
}

/*Nessa estrutura, é utilizado o campo 'ini' para indicar  a posição do primeiro elemento, que não necessariamente está na posição 0. */
/* O que mudaria se optarmos por não usar esse campo e sempre manter o primeiro elemento na posição 0? */
/* A complexidade para inserir e remover um elemento seriam as mesmas? */
/* Escreva abaixo, em forma de comentário, a sua resposta */

/*Se mudassemos para que cada primeiro elemento estivesse na posição 0, a complexidade iria permanecer a mesma pois, mudaria apenas
      algumas atribuições, ou seja, o código funcionaria de maneira similar mas com algumas pequenas alterações*/
