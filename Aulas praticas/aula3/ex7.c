#include <stdio.h>
#include <stdlib.h>

void troca(int *x, int *y) {
	int tmp = *x;
    *x = *y;
    *y = tmp;
}

void inverte(int v[], int n) {
    int i=0,j=n-1;
    while(i<j){
    	troca(&v[i],&v[j]);
    	i++;
    	j--;
	}

}

int main() {
    int n = 10,i;
    int *valores = malloc(n*sizeof(int));
    int inicio = 0, fim = n - 1;
    for (i = 0; i < n; i++)
        valores[i] = i + 1;

    printf("Antes de inverter o vetor:\n");
    for (i = 0; i < n; i++)
        printf("%d ", valores[i]);
    printf("\n");

    inverte(valores, n);

    printf("Apos inverter o vetor:\n");
    for(i = 0; i < n; i++)
        printf("%d ", valores[i]);
    printf("\n");

    free(valores);
    return 0;
}