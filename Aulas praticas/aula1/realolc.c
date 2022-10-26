#include <stdio.h>
#include <stdlib.h>

int main() {
    int NumInstrucao, Instrucao, Posicao, PrimeiroValor, SegundoValor;
    long long *Vetor = NULL, TamVetor, Coringa;
    scanf("%lld %d", &TamVetor, &NumInstrucao);
    if(TamVetor <= 10000000 && TamVetor >= 1) {
        if(NumInstrucao > 1 && NumInstrucao < 1000) {
            Vetor = malloc((TamVetor+1) * sizeof(long long));
            if (Vetor == NULL) {
                printf("Vetor nÃ£o possui memoria!\n");
            }
            for(int Indice0 = 1; Indice0 <= TamVetor; Indice0++) {
                Vetor[Indice0] = 0;
            }
        }
    }
    for(int Indice = 0; Indice < NumInstrucao; Indice++) {
        scanf("%d", &Instrucao);
        if (Instrucao == 1) {
            scanf("%d %d %lld", &PrimeiroValor, &SegundoValor, &Coringa);
            if (1 <= PrimeiroValor && SegundoValor <= TamVetor) {
                for(int Indice2 = PrimeiroValor; Indice2 <= SegundoValor; Indice2++) {
                    Vetor[Indice2] += Coringa;
                }
            }
        }
        else if(Instrucao == 2) {
            scanf("%d %d %lld", &PrimeiroValor, &SegundoValor, &Coringa);
            if (1 <= PrimeiroValor && SegundoValor <= TamVetor) {
                for(int Indice3 = PrimeiroValor; Indice3 <= SegundoValor; Indice3++) {
                    Vetor[Indice3] -= Coringa;
                }
            }
        }
        else if(Instrucao == 3) {
            scanf("%d", &Posicao);
            printf("%lld\n", Vetor[Posicao]);
        }
    }
    free(Vetor);
    return 0;
}