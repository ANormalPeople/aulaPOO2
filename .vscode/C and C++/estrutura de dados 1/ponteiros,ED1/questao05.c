#include <stdio.h>

void maiorAmenorB(int *a, int *b);

int main () {

    int A,B;

    scanf("%d%d",&A,&B);
    printf("A:%d  B:%d",A,B);

    maiorAmenorB(&A,&B);

    printf("\n\nA:%d  B:%d",A,B);

    return 0;
}

void maiorAmenorB(int *a,int *b){
    int temp;

    if(*b>*a){
        temp = *a;
        *a = *b;
        *b = temp;
    }
}