#ifndef __OBJETOS_H_
#define __OBJETOS_H_

#include "Util.h"

typedef enum tipo {
    INT,
    FLOAT,
    STR
} Tipo;

typedef union {
    int vInt;
    double vFloat;
    String vString;
} Item;

typedef struct objeto {
    Tipo tipo;
    Item item;
    struct objeto *proximo;
} Objeto;

Objeto *criaObjeto(); //Objeto indefinido

Objeto *criaObjetoInteiro(int);

Objeto *criaObjetoReal(double);

Objeto *criaObjetoString(String);

void liberaObjeto(Objeto *);

void imprimeInformacaoObjeto(Objeto *);

void imprimeItemObjeto(Objeto *);

#endif