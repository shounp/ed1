#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

struct lista {
    Objeto *inicio;
    Objeto *fim;
    int n;
};

Lista *criaLista() {
    /*
     * Faz alocação de memória para a lista
     *
     * Complexidade: O(1)
    */
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio =  NULL;
    lista->fim = NULL;
    lista->n = 0;
    return lista;
}

void liberaLista(Lista* lista) {
    /*
     * Faz a liberação de memória dinamicamente alocada
     * por cada objeto da lista
     *
     * Complexidade: O(n)
    */
    Objeto* atual = lista->inicio;
    while (atual != NULL) {
        Objeto* t = atual->proximo;
        liberaObjeto(atual);
        atual = t;
    }
    free(lista);
    lista = NULL;
}

void insereLista(Lista *lista, Objeto *elem) {
    /*
     * Insere um novo elemento no *fim* da lista
     *
     * Complexidade: O(1)
    */
    elem->proximo = NULL;
    if(listaVazia(lista)) {
        lista->inicio = lista->fim = elem;
    }
    else {
        lista->fim->proximo = elem;
        lista->fim = elem;
    }
    lista->n++;
}

void imprimeLista(Lista *lista, void (*imprimeObjeto)(Objeto *)){
    /*
     * Função de alta ordem que imprime cada objeto da lista de acordo com
     * a função 'imprimeObjeto' (passada como parâmetro).
     *
     * Complexidade: O(n)
    */
    if(listaVazia(lista))
        return;
    Objeto *atual = lista->inicio;
    while(atual != NULL){
        imprimeObjeto(atual);
        atual = atual->proximo;
    }
}


bool listaVazia(Lista *l){
    /*
     * Retorna true se a lista estiver vazia e false, caso contrário
     *
     * Complexidade: O(1)
    */
    return (l->inicio == NULL);
}

int tamanhoLista(Lista *lista){
    /* Retorna o número de elementos da lista
     *
     * Complexidade: O(1)
    */
    return lista->n;
}

Objeto *getPrimeiro(Lista *lista) {
    /* Retorna um ponteiro para o primeiro elemento da lista
     *
     * Complexidade: O(1)
    */
    if (lista == NULL)
        return NULL;
    return lista->inicio;
}