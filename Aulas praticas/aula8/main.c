#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Conjunto.h"

void exercicio1();
void exercicio2();
void exercicio3();
void exercicio4();
void exercicio5();
void exercicio6();
void exercicio7();
void exercicio8();
void exercicio9();

bool ehPar(int x);
bool ehImpar(int x);
bool ehPositivo(int x);
bool ehNegativo(int x);
bool ehPrimo(int x);
int quadrado(int x);
int raizQuadrada(int x);

int main()
{

    // exercicio1();

    // exercicio2();

    // exercicio3();

    // exercicio4();

    // exercicio5();

    // exercicio6();

    // exercicio7();

    // exercicio8();

    exercicio9();

    return 0;
}

void exercicio1()
{
    printf("** Exercício 1 **\n");
    Conjunto *c1 = criaConjuntoVazio();
    insere(c1, 1);
    insere(c1, 1);
    insere(c1, 1);
    insere(c1, 2);
    insere(c1, 3);
    insere(c1, 4);
    imprime(c1);
    imprimeReverso(c1);
    printf("Tamanho do conjunto: %d\n", tamanho(c1));
    libera(c1);
    printf("\n");
}

void exercicio2()
{
    printf("** Exercício 2 **\n");
    // Podemos criar um conjunto já passando os elementos.
    // O primeiro valor representa a quantidade de parâmetros que virá em seguida
    // No exemplo abaixo, o 6 indica que serão passados 6 números (2, 5, 7, 1, 9, 10)
    Conjunto *c2 = criaConjuntoValores(6, 2, 5, 7, 1, 9, 10);
    printf("Conjunto inicial: ");
    imprime(c2);
    int x = 2;
    printf("Removendo do conjunto o elemento '%d'\n", x);
    removeElemento(c2, x);
    imprime(c2);
    printf("Tamanho do conjunto: %d\n", tamanho(c2));

    x = 10;
    printf("Removendo do conjunto o elemento '%d'\n", x);
    removeElemento(c2, x);
    imprime(c2);
    printf("Tamanho do conjunto: %d\n", tamanho(c2));

    x = -15;
    printf("Removendo do conjunto o elemento '%d'\n", x);
    removeElemento(c2, x);
    imprime(c2);
    printf("Tamanho do conjunto: %d\n", tamanho(c2));

    x = 5;
    printf("Removendo do conjunto o elemento '%d'\n", x);
    removeElemento(c2, x);
    imprime(c2);
    printf("Tamanho do conjunto: %d\n", tamanho(c2));

    libera(c2);
    printf("\n");
}

void exercicio3()
{
    printf("** Exercício 3 **\n");
    // Também podemos inicializar um conjunto a partir de um vetor.
    // Note a sintaxe caso queiramos já inicializar o vetor com valores.
    int valoresC3[] = {5, 2, 1, 7, 10, 9, 11, 35, 2, 1, 9};
    // Observe como podemos obter a quantidade de elementos de um vetor
    int tamValoresC3 = sizeof(valoresC3) / sizeof(valoresC3[0]);
    printf("Quantidade de valores no vetor: %d\n", tamValoresC3);
    Conjunto *c3 = criaConjuntoArray(valoresC3, tamValoresC3);
    printf("Conjunto gerado: ");
    imprime(c3);
    printf("Tamanho: %d\n", tamanho(c3));
    printf("Fazendo uma copia do conjunto\n");
    Conjunto *c3Copia = copia(c3);
    printf("Resultado: ");
    imprime(c3Copia);
    printf("Inserindo alguns elementos na cópia\n");
    insere(c3Copia, 12);
    insere(c3Copia, 13);
    insere(c3Copia, 14);
    insere(c3Copia, 15);
    printf("Resultado: ");
    imprime(c3Copia);
    printf("Conjunto original: ");
    imprime(c3);
    libera(c3);
    libera(c3Copia);
    printf("\n");
}

void exercicio4()
{
    printf("** Exercício 4 **\n");
    Conjunto *c41 = criaConjuntoValores(4, 1, 2, 4, 8);
    Conjunto *c42 = criaConjuntoValores(5, 2, 3, 5, 7, 1);
    printf("C1: ");
    imprime(c41);
    printf("C2: ");
    imprime(c42);
    Conjunto *r4 = uniao(c41, c42);
    printf("C1 U C2: ");
    imprime(r4);
    libera(c41);
    libera(c42);
    libera(r4);
    printf("\n");
    c41 = criaConjuntoValores(3, 1, 2, 3, 4);
    c42 = criaConjuntoValores(2, 2, 3);
    printf("C1: ");
    imprime(c41);
    printf("C2: ");
    imprime(c42);
    r4 = uniao(c41, c42);
    printf("C1 U C2: ");
    imprime(r4);
    libera(c41);
    libera(c42);
    libera(r4);
    printf("\n");
    c41 = criaConjuntoValores(3, 1, 2, 3, 4);
    c42 = criaConjuntoVazio();
    printf("C1: ");
    imprime(c41);
    printf("C2: ");
    imprime(c42);
    r4 = uniao(c41, c42);
    printf("C1 U C2: ");
    imprime(r4);
    libera(c41);
    libera(c42);
    libera(r4);
    printf("\n");
    c41 = criaConjuntoVazio();
    c42 = criaConjuntoVazio();
    printf("C1: ");
    imprime(c41);
    printf("C2: ");
    imprime(c42);
    r4 = uniao(c41, c42);
    printf("C1 U C2: ");
    imprime(r4);
    libera(c41);
    libera(c42);
    libera(r4);
    printf("\n");
}

void exercicio5()
{
    printf("** Exercício 5 **\n");
    Conjunto *a = criaConjuntoValores(5, 1, 3, 5, 7, 9);
    Conjunto *b = criaConjuntoValores(4, 2, 4, 6, 8);
    Conjunto *r = intersecao(a, b);
    printf("C1: ");
    imprime(a);
    printf("C2: ");
    imprime(b);
    printf("C1 ∩ C2: ");
    imprime(r);
    printf("\n");
    libera(a);
    libera(b);
    libera(r);

    a = criaConjuntoValores(4, 1, 2, 4, 8);
    b = criaConjuntoValores(4, 2, 3, 5, 7);
    r = intersecao(a, b);
    printf("C1: ");
    imprime(a);
    printf("C2: ");
    imprime(b);
    printf("C1 ∩ C2: ");
    imprime(r);
    libera(a);
    libera(b);
    libera(r);

    a = criaConjuntoValores(2, 2, 3);
    b = criaConjuntoValores(4, 1, 2, 3, 4);
    r = intersecao(a, b);
    printf("C1: ");
    imprime(a);
    printf("C2: ");
    imprime(b);
    printf("C1 ∩ C2: ");
    imprime(r);
    libera(a);
    libera(b);
    libera(r);
    printf("\n");
}

void exercicio6()
{
    printf("** Exercício 6 **\n");
    Conjunto *a = criaConjuntoValores(5, 1, 3, 5, 7, 9);
    Conjunto *b = criaConjuntoValores(4, 2, 4, 6, 8);
    Conjunto *r = diferenca(a, b);
    printf("C1: ");
    imprime(a);
    printf("C2: ");
    imprime(b);
    printf("C1 - C2: ");
    imprime(r);
    printf("\n");
    libera(a);
    libera(b);
    libera(r);

    a = criaConjuntoValores(4, 1, 2, 4, 8);
    b = criaConjuntoValores(4, 2, 3, 5, 7);
    r = diferenca(a, b);
    printf("C1: ");
    imprime(a);
    printf("C2: ");
    imprime(b);
    printf("C1 - C2: ");
    imprime(r);
    printf("\n");
    libera(a);
    libera(b);
    libera(r);

    a = criaConjuntoValores(2, 2, 3);
    b = criaConjuntoValores(4, 1, 2, 3, 4);
    r = diferenca(a, b);
    printf("C1: ");
    imprime(a);
    printf("C2: ");
    imprime(b);
    printf("C1 - C2: ");
    imprime(r);
    printf("\n");
    libera(a);
    libera(b);
    libera(r);
}

void exercicio7()
{
    printf("** Exercício 7 **\n");
    Conjunto *a = criaConjuntoValores(6, 2, 5, 7, 1, 9, 10);
    Conjunto *b = criaConjuntoValores(6, 5, 2, 1, 7, 10, 9);
    printf("C1: ");
    imprime(a);
    printf("C2: ");
    imprime(b);
    printf("C1 == C2? %s\n", (iguais(a, b) ? "SIM" : "NAO"));
    libera(a);
    libera(b);
    printf("\n");

    a = criaConjuntoValores(3, 1, 2, 3);
    b = criaConjuntoValores(3, 2, 3, 4);
    printf("C1: ");
    imprime(a);
    printf("C2: ");
    imprime(b);
    printf("C1 == C2? %s\n", (iguais(a, b) ? "SIM" : "NAO"));
    libera(a);
    libera(b);
    printf("\n");

    a = criaConjuntoVazio();
    b = criaConjuntoVazio();
    printf("C1: ");
    imprime(a);
    printf("C2: ");
    imprime(b);
    printf("C1 == C2? %s\n", (iguais(a, b) ? "SIM" : "NAO"));
    libera(a);
    libera(b);
    printf("\n");
}

void exercicio8()
{
    printf("** Exercício 8 **\n");
    Conjunto *a = criaConjuntoValores(9, 2, -5, 7, -1, -9, 10, -8, 22, 31);
    printf("Conjunto: ");
    imprime(a);
    printf("    Quantidade de numeros pares: %d\n", contaSe(a, ehPar));
    printf("  Quantidade de numeros impares: %d\n", contaSe(a, ehImpar));
    printf("Quantidade de numeros positivos: %d\n", contaSe(a, ehPositivo));
    printf("Quantidade de numeros negativos: %d\n", contaSe(a, ehNegativo));
    printf("   Quantidade de numeros primos: %d\n", contaSe(a, ehPrimo));
    libera(a);
    printf("\n");
}

void exercicio9()
{
    printf("** Exercício 9 **\n");
    Conjunto *a = criaConjuntoValores(9, 2, -5, 7, -1, -9, 10, -8, 22, 31);
    printf("Conjunto: ");
    imprime(a);
    printf("Elevando cada número ao quadrado\n");
    transforma(a, quadrado);
    imprime(a);
    printf("Aplicando a raiz quadara a cada número\n");
    transforma(a, raizQuadrada);
    imprime(a);
    libera(a);
    printf("\n");
}

bool ehPar(int x)
{
    return x % 2 == 0;
}

bool ehImpar(int x)
{
    return x % 2 != 0;
}

bool ehPositivo(int x)
{
    return x > 0;
}

bool ehNegativo(int x)
{
    return x < 0;
}

bool ehPrimo(int n)
{
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0 || n % 11 == 0)
        return n == 2 || n == 3 || n == 5 || n == 7 || n == 11;

    for (unsigned long long i = 5; i * i <= n; i += 6)
        if (n % i == 0 || (n % (i + 2)) == 0)
            return false;

    return true;
}

int quadrado(int x)
{
    return x * x;
}

int raizQuadrada(int x)
{
    return (int)sqrt(x);
}