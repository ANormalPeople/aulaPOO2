#include <stdio.h>
#include <stdlib.h>

void somaComplexo( float rz1, float iz1, float rz2, float iz2, float *rz3, float *iz3);

int main () {

    float a1, a2, b1, b2,r1[50],r2[50];
    int c,x=0;

    system("cls");

    while(1){
    scanf("%f",&a1);    
    if(a1==0){
      break;
    }
    scanf("%f",&b1);
    scanf("%f",&a2);
    scanf("%f",&b2);
    somaComplexo(a1,b1,a2,b2,&r1[x],&r2[x]);

    x+=1;
    
    }

    printf("\n");

    for(c=0;c<x;c++){
        printf("%.1f + %.1fi ",r1[c],r2[c]);
        printf("\n");
    }
 
    system ("PAUSE");
    return 0;
}

void somaComplexo( float rz1, float iz1, float rz2, float iz2, float *rz3, float *iz3){

    *rz3 = rz2 + rz1;
    *iz3 = iz1 + iz2;
}