#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long long vInt;
    double vDouble;
    char vStr[15];
}TipoDadoStruct;

typedef union {
    long long vInt;
    double vDouble;
    char vStr[15];
}TipoDadoUnion;

#define PI 3.14159265358979323846

int main() {
    TipoDadoStruct exStruct = (TipoDadoStruct){10, PI, "UFES"};
    TipoDadoUnion exUnion;
    exUnion.vInt = 10;
    printf("%lld\n", exUnion.vInt);
    exUnion.vDouble = PI;
    strcpy(exUnion.vStr, "UFES");
    exUnion.vInt = 9223372036854775807;
    printf("%lld\n", exUnion.vInt);
    strcpy(exUnion.vStr, "ABCDEFGHIJKLMNO");
    printf("%s\n", exUnion.vStr);

    return 0;
}