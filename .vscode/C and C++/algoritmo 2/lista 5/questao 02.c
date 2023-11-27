#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void raizes(float a,float b,float c, float *x1, float *x2);

int main()
{
    float a,b,c,x1,x2;
   
   while (1)
   {
            
        scanf("%f",&a);
        if (a == 0){
        
            break;
        }
        
        scanf("%f %f",&b,&c);
               
        raizes(a, b, c, &x1, &x2);
    }
    return 0;
}

void raizes(float a,float b,float c, float *x1, float *x2){
    float delta;
    
    delta = pow(b,2) - 4 * a * c;

    if (delta > 0)
    {
        *x1 = (-b + sqrt(delta)) / 2 * a;
        *x2 = (-b - sqrt(delta)) / 2 * a;
        printf("\n%.2f %.2f\n\n", *x1,*x2);
    }
    if (delta == 0)
    {
        *x1 = -b / (2 * a);
        *x2 = -b / (2 * a);
        printf("\n%.2f %.2f\n\n", *x1,*x2);
    }
    if (delta < 0)
    {
        printf("Complexo\n");
    }
    
    return;
}