#include <stdio.h>
#include <stdlib.h>

#include "VE1.h"

struct ve1 {
    int capacidade; //Tamanho do array F
    int n;          //Posição do útimo elemento (também pode ser usado para determinar o #elementos)
    int *P;         //Array para armazenar os elementos na estrutura
};

VE1 *criaVE1(int capacidade) {
    /*Verifique se o valor em capacidade é válido */
    /*Se for, inicialize n com -1 (indicando que a estrutura está vazia) */
    /*Aloque o array 'P' e retorne o ponteiro da estrutura */
    if(capacidade == 0){
        printf("A capacidade deve ser diferente de 0!\n");
        return NULL;
    }
    VE1 *r = malloc(sizeof(VE1));
    if(r == NULL){
        fprintf(stderr, "Sem memória!\n");
        exit(1);
    }
    r->capacidade = capacidade;
    r->n = -1;
    r->P = malloc(capacidade*sizeof(int));
    if(r->P ==NULL){
        fprintf(stderr, "Sem memória!\n");
        exit(1);
    }
    return r;
}

void liberaVE1(VE1 *ve) {
    /* Faz a desalocação de memória */
    if(ve == NULL){
        return;
    }
    if(ve->P != NULL)
        free(ve->P);
    free(ve);
    ve = NULL;
}

void adicionaVE1(VE1 *ve, int v) {
    /* Adiciona um elemento no fim do vetor */
    /* Lembre-se de verificar se há espaço para adicionar o elemento */
    /* Complexidade: O(1)  */
    if(ve == NULL){
        printf("vetor nao alocado\n");
        return;
    }
    if(ve->n+1 == ve->capacidade){
        printf("vetor cheio\n");
    }
    else{
        ve->P[ve->n+1] = v;
        ve->n++;
    }
}

void removeVE1(VE1 *ve) {
    /* Retira o ultimo elemento*/
    /* Complexidade: O(1)  */
    if(ve == NULL){
        printf("vetor nao alocado\n");
        return;
    }
    else if(ve->n > -1){
        ve->P[ve->n] = 0;
        ve->n--;
    }
    else
        printf("vetor nao alocado\n");

}

int obtemElementoVE1(VE1 *ve){
    /*Retorna o elemento ultimo */
    /* Complexidade: O(1)  */
    //return ve->p[ve->n];
    if(ve == NULL){
        printf("vetor nao alocado\n");
        return -1;
    }
    else{
        return ve->P[ve->n];
    }
}

int vazioVE1(VE1 *ve) {
    /* Verifica se a estrutura possui algum elemento ou está vazia */
    /* Complexidade: O(1)  */
    //return (ve->n==-1);
    if(ve == NULL){
        printf("vetor nao alocado\n");
        return 1;
    }
    else if(ve->n > -1){
        return 0;
    }
    else
        return 1;
}

int cheioVE1(VE1 *ve) {
    /* Verifica se a estrutura está cheia */
    /* Complexidade: O(1)  */
    //return (ve->n == v->capacidade);
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

int tamanhoVE1(VE1 *ve) {
    /* Retorna o número de elementos que a estrutura armazena */
    /* Complexidade: O(1)  */
    //return ve->n+1;
    if(ve == NULL){
        printf("vetor nao alocado\n");
        return 0;
    }
    else
        return ve->n+1;
}