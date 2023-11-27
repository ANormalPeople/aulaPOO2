#include <stdio.h>

void maiorequant(int *array, int tam, int *cont, int *num);

int main () {
    int array[10]= {5, 2, 15, 3, 7, 15, 8, 6, 15, 2};  
    int tam = sizeof(array)/sizeof(array[0]);
    int cont=0, num=0;

    maiorequant(array,tam,&cont,&num);

    printf("%d %d",num,cont);

    return 0;
}

void maiorequant(int *array, int tam,int *cont,int *num){
    int *A = array;
    while(A<array+tam){
        if(*num<*A){
        *num = *A;
        }
        A++;
    }
    A = &array[0];
    while(A<array+tam){
        if(*num ==*A){
            *cont+= 1;
        }
        A++;
    }
}