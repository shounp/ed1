#ifndef __LISTA_H_
#define __LISTA_H_

typedef enum {
    false,
    true
}bool;

typedef struct no {
    int dado;
    struct no *proximo;
} No;

typedef struct lista Lista;

Lista *criaLista();

void liberaLista(Lista* lista);

void insereInicioLista(Lista *lista, int elem);

void imprimeLista(Lista *lista);

bool listaVazia(Lista *l);

int tamanhoLista(Lista *lista);

No* primeiroNoLista(Lista *lista);

No* ultimoNoLista(Lista *lista);

void insereFimLista(Lista *lista, int elem);

No* n_esimo(Lista *lista, int n);

No* proximoNoLista(Lista *lista, No *p);

No* anteriorNoLista(Lista *lista, No *p);

No* procuraLista(Lista *lista, int valor);

No* procuraNoLista(Lista *lista, No *p);

void removeElementoLista(Lista *lista, int valor);

void removeNoLista(Lista *lista, No* p);

Lista* copiaLista(Lista *lista);

void insereMisteriosoLista(Lista *lista, int valor);


#endif