#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int A=4, *a;
    float B=5.5, *b;
    char C='a',*c;

    printf("antes: \n%d, %.2f, %c\n",A,B,C);

    a = &A; 
    b = &B;
    c = &C;

    *a = 40;
    *b = 50.5;
    *c = 'b';

    printf("\ndepois: \n%d, %.2f, %c",A,B,C);

    return 0;
} 
