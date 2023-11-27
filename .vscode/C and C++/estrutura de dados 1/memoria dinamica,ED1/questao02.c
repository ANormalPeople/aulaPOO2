#include <stdio.h>
#include <stdlib.h>

int main () {

    int *vetor,count=0,N=1,X,soma=0,menor,maior=0;
    float media;
    vetor = malloc(1*sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }

    do {
        scanf("%d", &X);
        if (X != -1) {
            if (count == N) {
                N *= 2;  // Duplica a capacidade do vetor
                vetor = realloc(vetor, N * sizeof(int));
                if (vetor == NULL) {
                    printf("Erro na realocacao de memoria.\n");
                    exit(1);
                }
            }
            if(maior<X){
                maior=X;
            }
            vetor[count] = X;
            soma += X;
            count++;
        }
    } while (X != -1);
    
    menor=vetor[0];
    for(int i=1;i<count;i++){
        if(menor>vetor[i]){
            menor=vetor[i];
        }
    }
    media = soma/count;
    printf("\n soma:%d\nmedia:%.2f\nmaior:%d\nmenor:%d\nvalores:\n",soma,media,maior,menor);
    for(int i=0;i<count;i++){
        printf("%d: %d\n",i+1,vetor[i]);
    }
    free(vetor);
    return 0;
}