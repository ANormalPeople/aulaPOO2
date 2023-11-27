#include <stdio.h>

void frac(float num, int *in, float *frac);

int main () {
    float num=3.14731, y;
    int x;
    frac(num,&x,&y);
    printf("\n\n%d\n%f",x,y);

    return 0;
}

void frac(float num, int* inteiro, float* frac) {
    *inteiro = (int) num;
    *frac = num - *inteiro;
}
