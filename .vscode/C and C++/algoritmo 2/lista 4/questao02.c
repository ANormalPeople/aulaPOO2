#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculo_distancia(float a1, float b1, float a2, float b2);

struct  posicao{
    float x1;
    float y1;
    float x2;
    float y2;
};

int main () {
    struct posicao d;
    float a;
   
   system("cls");

   scanf("%f %f",&d.x1,&d.x2);
   scanf("%f %f",&d.y1,&d.y2);

   a = calculo_distancia(d.x1,d.y1,d.x2,d.y2);
   
   printf("Distancia:%.4f\n",a);

    return 0; 
}

float calculo_distancia(float a1, float b1, float a2, float b2){
    float di;

    di = sqrt( pow(a1-b1,2) + pow(a2-b2,2) );

    return di;
}