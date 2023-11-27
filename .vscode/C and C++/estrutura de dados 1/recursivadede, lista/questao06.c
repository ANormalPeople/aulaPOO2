#include <stdio.h>
#include <stdlib.h>

int buscasequencial(int N, int T, int *array){
    if(T<0){
        return 0;
    }
    if(N == array[T]){
        return 1;
    }
    return buscasequencial(N,T-1,array);
}

int main () {

    int valor, N;

    printf("tamanho do vetor\n");
    scanf("%d",&valor);
    if(valor<0){
        printf("tamanho invalido");
        return 0;
    }
    int array[valor];
    for(int i = 0; i< valor; i++){
        scanf("%d",&array[i]);
    }

    printf("parametro de busca\n");
    scanf("%d",&N);
    if(buscasequencial(N,valor-1,array)==1){
        printf("valor encontrado");
    }else{
        printf("valor nao encontrado");
    }

    return 0;
}