#include <stdio.h>

int maiorValor(int *array, int N);

int main () {

    int N,K;

    printf("diga quantos valores inteiros N deseja que sejam lidos\n");
    scanf("%d",&N);
    int gigantetalvez[N];
    int len=sizeof(gigantetalvez)/sizeof(gigantetalvez[0]);
    printf("valores?\n");
    for(int i=0;i<len;i++){
        scanf("%d",&gigantetalvez[i]);
    }

    printf("agora diga a quantidade de elementos por linha\n");
    scanf("%d",&K);

    for(int i = 0;i < N; i ++){
        printf("%d",gigantetalvez[i]);
        if((i+1)%K==0){
            printf("\n");
        }
    }

    printf("\n");
    int maior = maiorValor(gigantetalvez, N);
    printf("Maior valor do array: %d\n", maior);

    return 0;
}

int maiorValor(int *array, int N) {
    int maior = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}