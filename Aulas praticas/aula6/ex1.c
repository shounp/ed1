#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *proximo;
}No;

typedef struct lista {
    No *inicio;
    int tam;
}Lista;

Lista *criaLista() {
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    //complexidade 0(1);
    l->tam = 0;
    return l;
}

/*void insere(Lista *l, int valor) {
    No *no = malloc(sizeof(No));
    no->dado = valor;
    no->proximo = l->inicio;
    l->inicio = no;
    l->tam++;
}*/

/*void imprimeLista(Lista *l) {
    No *atual = l->inicio;
    while (atual) { //ou while (atual != NULL)
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
}*/

void liberaLista(Lista *l) {
    No *atual = l->inicio;
    while (atual != NULL) {
        No *tmp = atual->proximo;
        free(atual);
        atual = tmp;
    }
    free(l);
    l = NULL;
}

/*int tamanhoLista(Lista *l){
    //complexidade O(n)
    int t=0;
    No *atual = l->inicio;
    while(atual){
        t += 1;
        atual = atual->proximo;
    }
    return t;
}*/

No *criaNo(int valor){
    No *no = malloc(sizeof(No));
    no->dado = valor;
    no->proximo = NULL;
    return no;
}

void insereNo(Lista *l, No *no){
    no->proximo = l->inicio;
    l->inicio = no;
    l->tam++;
}

void imprimeListaRec(No *no){
    if(no){
        imprimeListaRec(no->proximo);
        printf("%d\n", no->dado);
    }
}

int tamanhoListaRec(No *no){
    int t = 0;
    if(no){
        t = tamanhoListaRec(no->proximo);
        t++;
    }
    return t;
}

int main() {
    Lista *l = criaLista();
    No *no = criaNo(11);
    /*insere(l, 2);
    insere(l, 3);
    insere(l, 5);
    insere(l, 7);*/
    insereNo(l,no);
    insereNo(l,criaNo(13));

    //printf("%d\n", tamanhoLista(l));
    printf("%d\n", l->tam);
    printf("%d\n", tamanhoListaRec(l->inicio));

    //imprimeLista(l);
    imprimeListaRec(l->inicio);

    liberaLista(l);

    return 0;
}