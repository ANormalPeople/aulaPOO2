#include <stdio.h>

int soma1(int *array1, int a, int *array2, int b, int *soma);

int main () {
    int array1[5]={1,2,3,4,5},array2[5]={1,2,3,4,5},soma[5];
    int result,a=sizeof(array1)/sizeof(array1[0]),b=sizeof(array2)/sizeof(array2[0]);
    result = soma1(array1,a,array2,b,soma);
    printf("%d\n",result);
    for(int i=0;i<a;i++){
        printf("%d ",soma[i]);
    }
    return 0;
}

int soma1(int *array1,int a, int *array2,int b, int *soma){

    if(a!=b){
        return 0;
    }
    else{
        while(a!=0){
            *soma = *array1 + *array2;
            soma++;
            array1++;
            array2++;
            a--;
        }
        return 1;
    }
}