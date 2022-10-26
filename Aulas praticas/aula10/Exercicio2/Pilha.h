#ifndef __TADP_H
#define __TADP_H

typedef enum {
    false,
    true
}bool;

typedef struct pilha Pilha;

Pilha *criaPilha();

void liberaPilha(Pilha *);

void push(Pilha *, char);

void pop(Pilha *);

char top(Pilha *);

bool pilhaVazia(Pilha *);

#endif