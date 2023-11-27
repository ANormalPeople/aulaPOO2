#include <stdio.h>
#include <stdlib.h>

float exponeciacao(float a, int b){
    if(b==0){
        return 1;
    }
    if(b>0){
        if(b==1){
            return a;
        }
        return a * exponeciacao(a,b-1);
    }else{
        if(b== -1){
            return 1/a;
        }
        return (1/a) * exponeciacao(a,b+1);
    }
}
int main () {
    float a,b;

    scanf("%f %f",&a,&b);
    float r = exponeciacao(a,b);
    printf("%.5f",r);
    return 0;
}