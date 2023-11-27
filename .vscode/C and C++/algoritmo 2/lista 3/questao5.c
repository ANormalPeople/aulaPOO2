#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validacao(int x);

int main (){
    int c=0;

   system("cls");
  
    srand(time(NULL));
    
    while(c==0){    
        c=rand()%1000;
    }  

    validacao(c);

    return 0;
}



//funções

int validacao(int x){

    int v=0, l;
   
    printf("Eu tenho um numero entre 1 e 1000.\nVoce pode adivinhar meu numero?\nDigite seu primeiro palpite:\n"); 

    while(v==0){
        
        printf("\n");
        scanf("%d",&l);
    
        if(x<l){
          printf("\nMuito alto. Tente novamente\n");
          system("PAUSE");
        }

        if(x>l){
          printf("\nMuito baixo. Tente novamente.\n");
          system("PAUSE");
        }

        if(x==l){
          printf("\nExcelente! Voce adivinhou o numero!\n");
          system("PAUSE");
          v=1;     
        }
    }

return 0;
}