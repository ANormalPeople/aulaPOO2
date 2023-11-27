#include <stdio.h>

void preencher(int *a,int valor,int b);

int main () {
    int valor,array[10];
    int b = sizeof(array)/sizeof(array[0]);

    scanf("%d",&valor);
    preencher(array,valor,b);

    for(int i=0;i<10;i++){
        printf("%d\n",array[i]);
    }

    return 0;
}

void preencher(int *a,int valor,int b){
   int *A = a;

   while(A< a + b){
        *A = valor;
        A++;
   }
}
