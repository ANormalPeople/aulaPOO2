#include <stdio.h>
#include <stdlib.h>

//pela analise da questao o comando rand não tem uma sequencia aleatoria sendo preciso usar o comando srand(time(null)) e a biblioteca
//time para que seja totalmente aletorio.

int ca=0,co=0;

int lancamento();

int main () {

    system("cls");

    lancamento();

    printf("\ntotal de cara:%d\n",ca);

   system("PAUSE");
   return 0;
}


//funçao

int lancamento(){

   for(int i=1;i<=100;i++){
   int m;
   m =rand()%2;
   if(m == 1){
   printf("cara!\n");
   ca = ca +1;
   }else{
   co = co + 1;
   printf("coroa!\n");
  }

}
   return 0;
}