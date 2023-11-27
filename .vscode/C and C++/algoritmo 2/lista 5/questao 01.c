#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//nao consegui modularizar muito pois usei break e vetor.

void cubo(int *nPtr);

int main () {
    int x[100]={0},a;
    
   system("cls");

    for(a=0;a<=100;a++){
       scanf("%x",&x[a]);
        if(x[a]==0){
            break;
        }
        cubo(&x[a]);
    }

   printf("\n");

    for(a=0;a<=100;a++){        
       if(x[a]!=0){
         printf("%i\n",x[a]);       
       }else{
         break;       
       }
    }   

    system("PAUSE");
     return 0;
}

//funçoes

void cubo(int *nPtr){
    *nPtr = pow(*nPtr,3);   
}


