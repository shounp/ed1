#include <stdio.h>
#include <stdlib.h>


#include "Deque.h"


int main() {
    Deque *dq = criaDeque();
    printf("Inserindo elementos no fim da fila...\n");
    push_back(dq, 1);
    push_back(dq, 2);
    push_back(dq, 3);
    push_back(dq, 4);
    push_back(dq, 5);
    printf("Primeiro elemento: %d\n", front(dq));
    printf("  Ultimo elemento: %d\n", back(dq));

    printf("Inserindo elementos no inicio da fila...\n");
    push_front(dq, 11);
    push_front(dq, 12);
    printf("Primeiro elemento: %d\n", front(dq));
    printf("  Ultimo elemento: %d\n", back(dq));
    
    printf("Retirando o primeiro elemento...\n");
    pop_front(dq);
    printf("Primeiro elemento: %d\n", front(dq));
    printf("  Ultimo elemento: %d\n", back(dq));
    printf("Retirando o primeiro elemento...\n");
    pop_front(dq);
    printf("Primeiro elemento: %d\n", front(dq));
    printf("  Ultimo elemento: %d\n", back(dq));

    printf("Retirando o ultimo elemento...\n");
    pop_back(dq);
    printf("Primeiro elemento: %d\n", front(dq));
    printf("  Ultimo elemento: %d\n", back(dq));
    printf("Retirando o ultimo elemento...\n");
    pop_back(dq);
    printf("Primeiro elemento: %d\n", front(dq));
    printf("  Ultimo elemento: %d\n", back(dq));

    liberaDeque(dq);

    return 0;
}

