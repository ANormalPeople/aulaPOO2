#include <stdio.h>

int ordenado (int *a, int *b, int *c);

int main () {

    int A,B,C,r;
    scanf("%d %d %d",&A,&B,&C);
    printf("A:%d B:%d C:%d",A,B,C);
    r = ordenado(&A,&B,&C);
    printf("\n\nA:%d B:%d C:%d\t%d",A,B,C,r);

    return 0;
}

int ordenado (int *a, int *b, int *c){
    int temp, di=0;
    if(*a>*b){
        temp = *b;
        *b = *a;
        *a = temp;
    }
    if(*a>*c){
        temp = *c;
        *c = *a;
        *a = temp;
    }
    if(*b>*c){
       temp = *b;
       *b = *c;
       *c = temp;
    }
    if(*a==*b&&*a==*c){
        di = 1;
    } 
    return di; 
}