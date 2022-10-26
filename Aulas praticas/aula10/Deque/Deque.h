#ifndef __DEQUE_H
#define __DEQUE_H

typedef enum {
    false,
    true
} bool;

typedef struct deque Deque;

Deque *criaDeque();

void liberaDeque(Deque *);

void push_front(Deque *, int);

void push_back(Deque *, int);

void pop_front(Deque *);

void pop_back(Deque *);

int front(Deque *);

int back(Deque *);

bool dequeVazia(Deque *);

int tamanhoDeque(Deque *);

#endif