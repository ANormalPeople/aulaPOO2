#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float distancia(float a1, float b1, float a2, float b2);

int main (){
    float d, x1, y1 ,x2, y2;

    system("cls");

    scanf("%f%f%f%f",&x1,&y1,&x2,&y2);

    d= distancia(x1, y1, x2, y2);


    printf("%.2f\n",d);

    system("PAUSE");
    return 0;
}

//funçoes


float distancia(float a1, float b1, float a2, float b2){
    float di;


    di= sqrt( pow(a1-b1,2) + pow(a2-b2,2) );


    return di;
}