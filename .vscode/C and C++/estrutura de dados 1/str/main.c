#include "str.h"
#include "str.c"
#include <stdio.h>
#include <stdlib.h>

int main () {
    char *A, *B; 
    lerStr(&A);
    lerStr(&B);    
    printf("\ntamanho da 1 string:%d\t tamanho da 2 string:%d",tamanhoStr(A),tamanhoStr(B));
    printf("\nComaparando(1igual/0direfente):%d\n",comparar(A,B));
    A = concatenar(A,B);
    printf("\nprimeira variavel concatenada: %s",A);
    liberar(A);
    liberar(B);

    return 0;
}