#ifndef EP2_PILHA_H
#define EP2_PILHA_H

#include "Objeto.h"
#include "Util.h"

typedef struct pilha Pilha;

Pilha *criaPilha();

void liberaPilha(Pilha *);

void empilha(Pilha *, Objeto *);

void desempilha(Pilha *);

Objeto *topoPilha(Pilha *);

bool pilhaVazia(Pilha *);

int tamanhoPilha(Pilha *);

void imprimePilha(Pilha *, int);

#endif