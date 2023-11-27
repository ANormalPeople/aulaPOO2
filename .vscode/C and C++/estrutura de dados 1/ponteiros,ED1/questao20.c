#include <stdio.h>

int negativos(float *vet, int N);

int main () {

    float array[10]={-1,-2,-3,-4,-5,6,7,8,9,10};
    int result,tam = sizeof(array)/sizeof(array[0]); 

    result = negativos(array,tam);
    printf("%d",result);
    return 0;
}

int negativos(float *vet, int N){
    float *A = vet;
    int count=0;
    while(A < vet+N){
        if (*A<0){
            count++;
        }
        A++;
    }
    return count;
}