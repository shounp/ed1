#ifndef __LISTA_H_
#define __LISTA_H_

#include "Util.h"
#include "Objetos.h"

typedef struct lista Lista;

Lista *criaLista();

void liberaLista(Lista *);

void insereLista(Lista *, Objeto *);

void imprimeLista(Lista *, void (*imprimeObjeto)(Objeto *));

bool listaVazia(Lista *);

int tamanhoLista(Lista *);

Objeto *getPrimeiro(Lista *);

#endif