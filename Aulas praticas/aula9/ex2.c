#include <stdio.h>
#include <stdlib.h>


int main() {
    int x = 10;
    double y = 3.1415;
    char *s = "UFES";

    //int *pInt = &y; //y é do tipo double
    //printf("*pInt = &y resulta em: %d\n", *pInt);

    //double *pDouble = &x; //x é do tipo int
    //printf("*pDouble = &x resulta em: %lf\n", *pDouble);

    void *ptr = &x;
    printf("*ptr = &x resulta em: %d\n", *(int *)ptr);
    *(int *)ptr = 15;
    printf("*(int *)ptr = 15 resulta em: %d\n", *(int *)ptr);

    ptr = &y;
    printf("*ptr = &x resulta em: %lf\n", *(double *)ptr);

    ptr = s;
    printf("*ptr = &x resulta em: %s\n", (char *)ptr);

    return 0;
}