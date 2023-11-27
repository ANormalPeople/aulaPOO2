#include <stdio.h>
#include <math.h>

void calc_esfera(float R, float *area, float *volume);


int main () {

    float R=5.0,X,Y;
    calc_esfera(R,&X,&Y);

    printf("area: %.2f\nvolume: %.2f",X,Y);

    return 0;
}

void calc_esfera(float R, float *area, float *volume){
    *area = 4 * 3.14* (R*R);
    *volume = (4.0/3.0) * 3.14 * (R*R*R);
}
