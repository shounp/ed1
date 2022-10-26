#ifndef __TADP_H
#define __TADP_H

typedef struct ve1 VE1;

VE1 *criaVE1(int);

void liberaVE1(VE1 *ve);

void adicionaVE1(VE1 *ve, int v);

void removeVE1(VE1 *ve);

int obtemElementoVE1(VE1 *ve);

int vazioVE1(VE1 *ve);

int cheioVE1(VE1 *ve);

int tamanhoVE1(VE1 *ve);

#endif