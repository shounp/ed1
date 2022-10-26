#ifndef __FILA_H
#define __FILA_H

typedef enum {
    false,
    true
} bool;

typedef struct filaprio FilaPrioridade;

FilaPrioridade *criaFP();

void liberaFP(FilaPrioridade *);

void insere(FilaPrioridade *, int);

void removeMax(FilaPrioridade *);

int primeiro(FilaPrioridade *);

bool FPVazia(FilaPrioridade *);

bool FPCheia(FilaPrioridade *);

int tamanhoFP(FilaPrioridade *);

#endif