#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAXIMO 1000

int main() {
    int i,ts;
	char *numeroStr = malloc(TAM_MAXIMO*sizeof(char));
    printf("Digite um número natual: ");
    scanf("%s", numeroStr);
    ts = strlen(numeroStr);
    int *numero = malloc(ts*sizeof(int));
	for(i=0;i<ts;i++){
		numero[i]  = numeroStr[i]-'0';
	}
	for(i=0;i<ts;i++){
		printf("%d\n",numero[i]);
	}
	free(numeroStr);
	free(numero);
    return 0;
}