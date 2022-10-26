#ifndef __TADP_H
#define __TADP_H

typedef struct ve2 VE2;

VE2 *criaVE2(int);

void liberaVE2(VE2 *ve);

void adicionaVE2(VE2 *ve, int v);

void removeVE2(VE2 *ve);

int obtemElementoVE2(VE2 *ve);

int vazioVE2(VE2 *ve);

int cheioVE2(VE2 *ve);

int tamanhoVE2(VE2 *ve);

#endif