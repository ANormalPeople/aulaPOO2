#include <stdio.h>

void maiormenor(int *array, int tam,int *maior, int *menorzin);

int main () {
    int array[10]={1,2,3,4,5,6,7,8,9,10};
    int max=0,min,tam = sizeof(array)/sizeof(array[0]);
    maiormenor(array,tam,&max,&min);
    printf("%d\n%d",max,min);

    return 0;
}

void maiormenor(int *array, int tam,int *maior, int *menorzin){
    int *A = array;
    *menorzin = *array;
    while(A<array+tam){
        if(*maior<*A){
            *maior = *A;
        }
        if(*menorzin>*A){
            *menorzin = *A;
        }
        A++;
    }

}