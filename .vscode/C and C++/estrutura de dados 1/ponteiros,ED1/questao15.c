#include <stdio.h>

void imprimir(int *a,int tam);

int main () {

    int array[5]={0};
    int tam = sizeof(array) / sizeof(array[0]);
    imprimir(array,tam);   
    return 0;
}
//usar sizeof(array) dentro da função retornará 
//o tamanho do ponteiro e não o tamanho do array completo.
void imprimir(int *a, int tam){
    int *A = a;

    while(A<a+tam){
        printf("%d\n",*A);
        A++;
    }
}