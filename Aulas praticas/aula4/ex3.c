#include <stdio.h>
#include <stdlib.h>

#include "Racional.h"

int main(){
    int n,i,nel;
    Racional *x = inicializaRacional(1, 2);
    Racional *y = inicializaRacional(1, 4);
    Racional *z = NULL;

    printf("quantos termos:");
    scanf("%d",&n);
    nel=8;
    imprimeRacional(x);
    for(i=0;i<=n-2;i++){
        z = somaRR(x ,y);
        imprimeRacional(z);
        setDen(x, getDen(z));
        setNum(x, getNum(z));
        setDen(y, nel);
        nel = nel*2;
        liberaRacional(z);
    }

    liberaRacional(y);
    liberaRacional(x);
    return 0;
}


int GCD(int a, int b)
{
    int i;
    if(!a || !b)
        return 1;
    for(i = MIN(a,b); i >= 1; i--)
        if(!(a % i) && !(b % i))
            break;
    return i;
}

RATIONAL *simplify_rational(RATIONAL *r)
{
   int m = GCD(r->n, r->d);

   r->n /= m;
   r->d /= m;


   return r;
}