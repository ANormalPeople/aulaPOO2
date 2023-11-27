#include <stdio.h>

int somadodobro(int *a, int *b);

int main () {


    int r,A,B;

    scanf("%d%d",&A,&B);
    printf("A:%d  B:%d",A,B);

    r = somadodobro(&A,&B);

    printf("\n\nsoma do dobro = %d",r);

    return 0;
}


int somadodobro(int *a, int *b){
    int r;

    *a = *a * 2;
    *b = *b * 2;
    r = *a + *b;
    return r;
    
}