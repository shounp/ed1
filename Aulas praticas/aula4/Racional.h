#ifndef RACIONAL_H
#define RACIONAL_H



typedef enum {
    false,
    true
}bool;

typedef struct racional Racional;

Racional* inicializaRacional(long n, long d);


void liberaRacional(Racional* r);

void setNum(Racional* r, long n);

void setDen(Racional* r, long d);

long getNum(Racional* r);

long getDen(Racional* r);

void imprimeRacional(Racional* r);

Racional* multiplicaRR(Racional* r1, Racional* r2);

Racional *multiplicaRI(Racional *r, long a);

bool comparaRacional(Racional *r1, Racional *r2);

Racional* somaRR(Racional* r1, Racional* r2);

Racional *somaRI(Racional *r, long a);

#endif