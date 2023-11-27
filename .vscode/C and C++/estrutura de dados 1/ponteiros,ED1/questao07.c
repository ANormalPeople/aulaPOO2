#include <stdio.h>

void soma(int *a, int *b);

int main () {

    int A, B;

    scanf("%d %d",&A,&B);
    printf("A:%d B:%d\n\n",A,B);
    soma(&A,&B);
    printf("A:%d B:%d",A,B);

    return 0;
}

void soma(int *a, int *b){
   *a += *b;
}