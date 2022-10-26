#ifndef __CONJUNTO_H
#define __CONJUNTO_H

typedef enum {
    false,
    true
} bool;

typedef struct no {
    int valor;
    struct no *proximo;
    struct no *anterior;
} No;

typedef struct conjunto Conjunto;

Conjunto *criaConjuntoVazio();

Conjunto *criaConjuntoValores(int, ...);

Conjunto *criaConjuntoArray(int *, int);

void libera(Conjunto *);

int tamanho(Conjunto *c);

bool vazio(Conjunto *c);

void insere(Conjunto *, int);

void removeElemento(Conjunto *, int);

No *busca(Conjunto *, int);

bool pertence(Conjunto *, int);

void imprime(Conjunto *);

void imprimeReverso(Conjunto *);

Conjunto *copia(Conjunto *);

Conjunto *uniao(Conjunto *, Conjunto *);

Conjunto *intersecao(Conjunto *, Conjunto *);

Conjunto *diferenca(Conjunto *, Conjunto *);

bool iguais(Conjunto *, Conjunto *);

int contaSe(Conjunto *, bool (*compara)(int));

void transforma(Conjunto *, int (*funcao)(int));

#endif