#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y, z;
}Ponto;

int main() {
    Ponto p = {1.5, 2.7, 0.5};

    //int *pInt = &p; //p é do tipo Ponto
    //printf("*pInt = &p resulta em: %d\n", *pInt);

    // double *pDouble = &p; //p é do tipo Ponto
    // printf("pDouble = &p resulta em: %lf\n", *pDouble);

    void *ptr = &p;
    //Note o que foi feito para conseguirmos acessar cada campo do struct.
    //Por quê precisamos usar essa sintaxe?
    //Como poderiamos fazer para usar o operador ->?
    printf("*ptr = &p resulta em: %lf x %lf x %lf\n", ((Ponto *)ptr)->x, (*(Ponto *)ptr).y, (*(Ponto *)ptr).z);

    ptr = malloc(sizeof(Ponto));
    //Mesmo o ponteiro apontando para um Ponto, por ele ser do tipo void *, não podemos
    //acessar os campos do struct de forma direta, como mostrado abaixo:
    //
    //ptr->x = 10;
    //ptr->y = 10;
    //ptr->z = 10;
    //
    //Para termos acesso, precisamos fazer um cast antes:
    ((Ponto *)ptr)->x = 10;
    ((Ponto *)ptr)->y = 7.3;
    ((Ponto *)ptr)->z = 8.5;
    //Ou
    (*(Ponto *)ptr).x = 10;
    (*(Ponto *)ptr).y = 7.3;
    (*(Ponto *)ptr).z = 8.5;

    //De forma mais simples, podemos criar uma variável auxiliar do tipo ponteiro para Ponto:
    Ponto *ptrPonto = (Ponto *)ptr; //Uma boa prática é fazer o cast para Ponto * do ponteiro void
    //ptrPonto->x = 5.5; //ou (*ptrPonto).x = 5.5;
    //ptrPonto->y = 8.7; //ou (*ptrPonto).y = 8.7;
    //ptrPonto->z = 3.4; //ou (*ptrPonto).z = 3.4;

    free(ptr);
    return 0;
}