#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 52

char tip[][20]={"paus","ouros","copas","espadas"};
char nume[][20]={"As","Dois","Tres","Quatro","Cinco","Seis","Sete","Oito","Nove","Dez","Valete","Dama","Rei"};

int case1();
int case0();
//int mostrar();

struct carta{
    int naipe;
    int valor;

}deck[N];

int main () {

    srand(time(NULL));
    int c;
    
    scanf("%d",&c);

   if(c==1){
    case1();
   
   }
   else if (c == 0)
   {
    case0();
   }


    system("PAUSE");
    return 0;
}



int case1(){
   int c,x;
   for(c=0;c<4;c++){
       for(x=0;x<12;x++){
          printf("%s de %s\n",nume[x],tip[c]);
       } 
       
    }

}

int case0(){
   struct carta d1,d2;

   for(int c=0;c<4;c++){
      for(int x=0;x<12;x++){
         d1.naipe = rand()%4;
         d2.valor = rand()%13;
         printf("%s de %s\n",  nume[d2.valor], tip[d1.naipe]);   
      } 

   } 

}