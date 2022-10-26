#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int codigo;
	int qtd_dias_trabalhados;
	int *horas_trabalhadas;
}Funcionario;

int main() {
    int n,i,j,hr,sl;
    printf("Digite a quantidade de funcionarios:");
    scanf("%d", &n);
    Funcionario *p = malloc(n*sizeof(Funcionario));
    if (p == NULL){
        printf("Sem memória\n");
        exit(1);
    }


    for(i = 0; i < n; i++){
    	printf("---Funcionario %d---\n",i+1);
        printf("codigo:");
        scanf("%d", &p[i].codigo);
        printf("Quantidade de dias trabalhados:");
        scanf("%d", &p[i].qtd_dias_trabalhados);
        p[i].horas_trabalhadas = malloc(p[i].qtd_dias_trabalhados * sizeof(int));
        for(j = 0 ;j < p[i].qtd_dias_trabalhados; j++){
        	p[i].horas_trabalhadas[j] = 0;
		}
		printf("Horas trabalhadas em cada dia:");
        for(j=0;j < p[i].qtd_dias_trabalhados;j++){
        	scanf("%d", &p[i].horas_trabalhadas[j]);
		}
    }

    printf("---Relatorio Final---\n");
    printf("Funcionario - Horas Trabalhadas - Salario\n");
    for(i=0; i < n; i++){
    	hr = 0;
	    for(j = 0;j < p[i].qtd_dias_trabalhados;j++){
			hr += p[i].horas_trabalhadas[j];
		}
		sl = hr*25;
    	printf("%d        -   %d    -        %.2d\n",p[i].codigo,hr,sl);
	}
	hr = 0;
	for(i=0; i < n; i++){
	    for(j = 0;j < p[i].qtd_dias_trabalhados;j++){
			hr += p[i].horas_trabalhadas[j];
		}
	}
	sl = hr*25;
	printf("\nTotal pago aos funcionarios: R$ %d\n",sl);
	for(i=0;i<n;i++){
			free(p[i].horas_trabalhadas);
		}
    free(p);
    return 0;
}