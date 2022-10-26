#include <stdio.h>
#include <stdlib.h>

double **cria(int n) {
	int i,j;
	double **m;
	m = malloc(n * sizeof(double*));
	for(i = 0; i < n; i++){
		m[i] = malloc((i+1)* sizeof(double));
	}
	for(i = 0; i < n; i++){
		for(j = 0; j <=i ; j++){// quando coloco j < n ele roda normalmente dando aquele erro
			m[i][j] = 0;		// no valgrind
		}
	}
    return m;
}

void modifica(double **m, int i, int j, int n, double valor){
	if(i < n && j < n){
		if(i == j)
			m[i][j] = valor;
		else{
			if(i > j)
				m[i][j] = valor;
			else
				m[j][i] = valor;
		}
	}
	else
		printf("ERRO ENCONTRADO\n");
}

double acessa(double **m, int i, int j, int n) {
    if(i < n && j < n){
    	if(i > j)
			return m[i][j];
		else
			return m[j][i];
	}
	else{
		for(i=0;i<n;i++){
			free(m[i]);
		}
		free(m);
		printf("ERRO ENCONTRADO\n");
		exit(1);
	}
    return 0;
}

void imprime(double **m, int n){
    int i,j;
    for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i >= j)
    			printf("%.2lf\t",m[i][j]);
    		else
    			printf("%.2lf\t",m[j][i]);
		}
		printf("\n");
	}
}

int main() {
	int i,j;
    int n = 10;
    double **m = cria(n);
    imprime(m, n);
    printf("\n");
    modifica(m, 0, 0, n, 2.5);
    modifica(m, 0, 1, n, 3.2);
    modifica(m, 0, 2, n, 6.0);
    modifica(m, 0, 9, n, 8.5);
    imprime(m, n);
    printf("\n");
    printf("m[%d][%d] = %.2lf\n", 0, 9, acessa(m, 0, 9, n));
    printf("m[%d][%d] = %.2lf\n", 9, 0, acessa(m, 9, 0, n));
	printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            modifica(m, i, j, n, 3.14);
        }
    }
    imprime(m, n);
	printf("\n");
    modifica(m, 0, 10, n, -1); //Deve gerar um erro e não modificar a matriz
    imprime(m, n);
	printf("\n");
    printf("m[%d][%d] = %.2lf\n", 10, 0, acessa(m, 10, 0, n)); //Gera erro e encerra o programa
	for(i=0;i<n;i++){
		free(m[i]);
	}
	free(m);
    return 0;
}