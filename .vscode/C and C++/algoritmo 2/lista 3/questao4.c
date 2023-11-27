#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// O comando rand tem uma semente fixa, fazendo assim a sequencia de valores sempre ser a mesmas então utilizei essa biblioteca
// e esse comando pra fazer ficar totalmente aleatorio.

int p,c=-1, v=0, soma=0, d1, d2, a1, b2;


int calculo();
int primeirarotaca();
int rotacoesposteriores();


int main  () {

    srand(time(NULL));

    system("cls");
    do{
      
      a1 =rand()%6;
      b2 =rand()%6;  



      if(a1>0 && b2>0){        
        
        calculo();

 
        if(c==0){
          
          primeirarotaca();
          
          }
    
        if(c>=1){

        rotacoesposteriores();
    }

      }   
   }while(v == 0 );

    return 0;
}




//funçoes


int calculo (){

  d1=a1;
  d2=b2;
  soma = d1 + d2;
  c=c+1; 

 return 0;
}


int primeirarotaca(){


 if(soma==7 || soma == 11){
   printf("\nSoma dos dados %d + %d = %d",d1,d2,soma);
   printf("\nvoce ganhou :)\n"); 
   system("PAUSE");
   v=1;
   }

 if(soma==2 || soma ==3 || soma ==12){
   printf("\nSoma dos dados %d + %d = %d",d1,d2,soma);
   printf("\nvoce perdeu :(\n");
   system("PAUSE");
   v=1;    
   }
       
 if(soma==4 || soma==5 || soma==6 || soma==8 || soma==9 || soma == 10){
   printf("\nSoma dos dados %d + %d = %d",d1,d2,soma);
   printf("\nO ponto e %d\n",soma);
   system("PAUSE");   
   p=soma;
   }

return 0;      
}


int rotacoesposteriores(){

 if(soma==7){
   printf("\nSoma dos dados %d + %d = %d\n",d1,d2,soma);
   printf("voce perdeu :(\n");
   system("PAUSE");
   v=1;
   }

 if(p==soma){
    printf("\nSoma dos dados %d + %d = %d\n",d1,d2,soma);
    printf("voce ganhou :)\n");
    system("PAUSE");
    v=1;
    }
       
 if(soma != 7 && p != soma){
   printf("\nSoma dos dados %d + %d = %d\n",d1,d2,soma);
   system("PAUSE");
   v=0;
   }

return 0;
}