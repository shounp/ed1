#include <stdio.h>
#include <stdlib.h>
#include "Racional.h"


struct racional {
    long num;
    long den;
};

int MDC(int a, int b){
    if(b == 0)
        return a;
    else
        return MDC(b,a%b);
}

void simplifica(Racional* r){
    int m;
    m = MDC(r->num, r->den);
    r->num /= m;
    r->den /= m;
}

Racional *inicializaRacional(long n, long d){
    if (d == 0) {
        printf("O denominador deve ser diferente de 0!\n");
        return NULL;
    }
    Racional *r = malloc(sizeof(Racional));
    if (r == NULL) {
        fprintf(stderr, "Sem memória!\n");
        exit(1);
    }
    r->num = n;
    r->den = d;
    simplifica(r);
    return r;
}


void liberaRacional(Racional* r) {
    if(r != NULL) { //Evita a tentativa de desalocação de um ponteiro não alocado
        free(r);
        r = NULL; //Evita ponteiros soltos
    }
}

void setNum(Racional* r, long n) {
    r->num = n;
}

void setDen(Racional* r, long d) {
    if(d == 0) {
        printf("O denominador deve ser diferente de 0!\n");
        return;
    }
    r->den = d;
}

long getNum(Racional* r) {
    return r->num;
}

long getDen(Racional* r) {
    return r->den;
}

void imprimeRacional(Racional* r){
	if(r!= NULL)
    	printf("%ld/%ld\n", r->num, r->den);
}

Racional* multiplicaRR(Racional* r1, Racional* r2) {
    /* Retorna o resultado de r1*r2 */
    Racional* r = inicializaRacional( r1->num*r2->num, r1->den*r2->den);
    simplifica(r);
    return r;
}

Racional *multiplicaRI(Racional *r, long a) {
    /* Retorna o resultado de r*a */
    r->num = r->num*a;
    simplifica(r);
    return r;
}

bool comparaRacional(Racional *r1, Racional *r2){
    /* Retorna true se r1 == r2 e false, caso contrário */
    return r1->num*r2->den == r1->den*r2->num;
}

Racional* somaRR(Racional* r1, Racional* r2) {
    /* Retorna o resultado de r1+r2 */
   	long mmc = r1->den*r2->den;
    long nu = (mmc/r1->den)*r1->num + (mmc/r2->den)*r2->num;
    long de = mmc;
    Racional* r = inicializaRacional( nu, de);
    simplifica(r);
    return r;
}

Racional *somaRI(Racional *r, long a) {
    /* Retorna o resultado da soma de r + a */
    r->num = r->num + r->den*a;
    simplifica(r);
    return r;
}