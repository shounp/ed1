#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

struct lista {
    No *inicio;
    No *fim;
    int tamanho;
};

Lista *criaLista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
}

void liberaLista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* t = atual->proximo; /* guarda referência para o próximo elemento */
        free(atual);            /* libera a memória apontada por atual */
        atual = t;              /* faz atual apontar para o próximo */
    }
    free(lista);
    lista = NULL;
}

void insereInicioLista(Lista *lista, int elem) {
    /* Insere um novo elemento no inicio da lista
     *
     * Complexidade: O(1)
     */
    No *no = malloc(sizeof(No));
    no->dado = elem;
    no->proximo = lista->inicio;
    lista->inicio = no;
    if(no->proximo == NULL){//no->proximo  lista->inicio
        lista->fim = no;
    }
    lista->tamanho++;
}

void insereFimLista(Lista *lista, int elem) {
    /* Insere um novo elemento no fim da lista
     *
     * Complexidade: O(n)
     */
    No *no = malloc(sizeof(No));
    no->dado = elem;
    no->proximo = NULL;
    No *atual = lista->inicio;
    if(lista->inicio == NULL){
        lista->inicio = no;
    }
    else{
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = no;
    }
    lista->fim = no;//n
    lista->tamanho++;
}

void imprimeLista(Lista *lista){
    /* Imprime os elementos da lista. Note que nessa implementação
     * os valores são impressos enquanto não se atinge o nó 'lista->fim'.
     */
    No *atual = lista->inicio;
    // Enquanto não atingirmos o 'fim' da lista, avançamos.
    while(atual != lista->fim) {
    	printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    if (atual) //Imprime a informação do último nó, caso ele exista
        printf("%d -> ", atual->dado);
    printf("NULL\n");
}

bool listaVazia(Lista *l){
    /* Verifica se a lista está vazia ou não
     *
     * Complexidade: O(1)
    */
    return (l->inicio == NULL); // ou return l->tamanho == 0;
}

int tamanhoLista(Lista *lista){
    /* Retorna o número de elementos da lista
     *
     * Complexidade: O(1)
    */
    return lista->tamanho;
}

No* primeiroNoLista(Lista *lista){
    /* Retorna uma referência para o primeiro no da lista
     *
     * Complexidade: O(1)
     */
    return lista->inicio;
}

No* ultimoNoLista(Lista *lista){
    /* Retorna uma referência para o último no da lista
     *
     * Complexidade: O(1)
     */
    return lista->fim;
}

No* procuraLista(Lista *lista, int valor){
    /* Retorna uma referência para o nó tal que no->dado == valor
     *
     * Complexidade: O(n)
     */
    for(No *aux = lista->inicio; aux != NULL; aux = aux->proximo) {
         if(aux->dado == valor)
            return aux;
    }
    return NULL;
}

No* procuraNoLista(Lista *lista, No *p){
    /* Retorna uma referência para o nó tal que no == p
     *
     * Complexidade: O(n)
     */
    for(No *aux = lista->inicio; aux != NULL; aux = aux->proximo) {
         if(aux->proximo == p)
            return aux->proximo;
    }
    return NULL;
}

No* n_esimo(Lista *lista, int n) {
    /* Retorna uma referência para o n-esimo nó da lista
     *
     * Complexidade: O(n)
     */
     int i = 1;
     for(No *aux = lista->inicio; aux != NULL; aux = aux->proximo) {
         if(i == n)
            return aux;
        i++;
    }
    return NULL;
}

No* proximoNoLista(Lista *lista, No *p){
    /* Retorna uma referência para o nó posterior àquele referenciado por p
     *
     * Complexidade: O(n)
     */
    if (listaVazia(lista))
        return NULL;

    /* Como não há garantia que o nó esteja na lista, devemos fazer uma busca pelo nó */
    /* Você deve utilizar a função procuraNoLista */
    No *atual = procuraNoLista(lista, p);
    if (atual == NULL) { // Nó não encontrado
        return NULL;
    }
    return atual->proximo;
}

No* anteriorNoLista(Lista *lista, No *p){
    /* Retorna uma referência para o nó anterior àquele referenciado por p
     *
     * Complexidade: O(n)
     */
    if (listaVazia(lista))
        return NULL;
    No *aux = lista->inicio;
    No *anterior = NULL;
    while (aux != p) {
        anterior = aux;
        aux = aux->proximo;
    }
    return anterior;
}

void removeElementoLista(Lista *lista, int valor){
    /* Remove os nós tal que no->dado == valor
     *
     * Complexidade: O(n)
     */
    if (listaVazia(lista))
        return;
    No *p = lista->inicio;
    No *anterior = NULL;
    while(p){
        if(p->dado == valor) {
            if (p == lista->inicio && p == lista->fim) { // Lista só contém um elemento
                lista->inicio = lista->fim = NULL;
                free(p);
                p = NULL;
                lista->tamanho--;
            }
            else if(p == lista->inicio) { // O elemento a ser removido é o primeiro nó
                lista->inicio = lista->inicio->proximo;
                free(p);
                p = lista->inicio;
                lista->tamanho--;
            }
            else if (p == lista->fim /* p->proximo == NULL */) { // O elemento a ser removido é o último nó
                anterior->proximo = NULL;
                lista->fim = anterior;
                free(p);
                p = NULL;
                lista->tamanho--;
            }
            else { // O elemento está no meio da lista
                anterior->proximo = p->proximo;
                free(p);
                p = anterior->proximo;
                lista->tamanho--;
            }
        }
        else{
            anterior = p;
            p = p->proximo;
        }
    }
}

void removeNoLista(Lista *lista, No* p) {
    /* Remove o nó referenciado por p
     *
     * Complexidade: O(n)
     */
     if (listaVazia(lista))
        return;
    No *po = lista->inicio;
    No *anterior = NULL;
    while(po){
        if(po == p){
            lista->tamanho--;
            if (po == lista->inicio && po == lista->fim) { // Lista só contém um elemento
                lista->inicio = lista->fim = NULL;
                free(po);
                po = NULL;
            }
            else if(po == lista->inicio) { // O elemento a ser removido é o primeiro nó
                lista->inicio = lista->inicio->proximo;
                free(po);
                po = lista->inicio;
            }
            else if (po == lista->fim /* p->proximo == NULL */) { // O elemento a ser removido é o último nó
                anterior->proximo = NULL;
                lista->fim = anterior;
                free(po);
                po = NULL;
            }
            else { // O elemento está no meio da lista
                anterior->proximo = po->proximo;
                free(po);
                po = anterior->proximo;
            }

        }
        else{
            anterior = po;
            po = po->proximo;
        }
    }
}

void insereMisteriosoLista(Lista *lista, int valor) {
    /* Insere ...
     *a)inserir em ordem crescente
     *b)da se comeca do inicio e fim ao msm tempo
     *c)sim ,mas teria uma custo maior o(n log n)
     * Complexidade: O(n)
     */
    No *no = malloc(sizeof(No));
    no->dado = valor;
    no->proximo = NULL;
    if(listaVazia(lista)) {
        no->proximo = lista->inicio;
        lista->inicio = lista->fim = no;
    }
    else {
        No *atual = lista->inicio;
        No *anterior = NULL;
        while (atual && atual->dado < no->dado){
            anterior = atual;
            atual = atual->proximo;
        }
        if (atual == lista->inicio) {
            no->proximo = lista->inicio;
            lista->inicio = no;
        }
        else if (atual == NULL) {
            anterior->proximo = no;
            lista->fim = no;
        }
        else {
            anterior->proximo = no;
            no->proximo = atual;
        }
    }
    lista->tamanho++;
}

Lista * copiaLista(Lista *lista) {
    /* Retorna um cópia da lista.
     *
     * Complexidade: O(n)
     */
    if(lista->inicio == NULL){
        return NULL;
    }
    Lista *copia = criaLista();
    No *aux = lista->inicio;
    while(aux != NULL){
        insereFimLista(copia,aux->dado);
        aux = aux->proximo;
    }
    return copia;
}