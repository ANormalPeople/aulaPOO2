
// PROJETO "LISTA DE ATENDIMENTO DE CONSULTORIO", PROJA FINAL DE ALGORITMO.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//variaveis globais
int global, dar;
//fim das variaveis globais




//prototipo das funçoes
int menu();
//fim do prototipo das funçoes



//declaraçao da struct
struct cliente{
char nome[30];
float hora;
int dia;
char mes[10];
};
//fim da declaraçao da struct






//comando central
int main () {
   struct cliente cl[100];
   int lr, c, n,matriz[12][100];
   //char el[5];
   int red=0;
   n=0;
  
  system("cls");
  printf("diga a quantidade de clientes desejada\n!!!aviso capacidade ate 100!!!\n");
  scanf("%d",&global);

 do{

    dar=menu();

  switch(dar){

   case 1:
    system("cls");
    for(c=0;c<global;c++){
      printf("diga o nome do %d cliente \n",c+1);
       scanf("%s",&cl[c].nome);
 
      printf("diga a hora do %d cliente \n",c+1);
       scanf("%f",&cl[c].hora);
 
      printf("diga o dia do %d cliente\n",c+1);
        scanf("%d",&cl[c].dia);
   
      printf("diga o mes do %d cliente\n",c+1);
        scanf("%s",&cl[c].mes);
     system("cls");
     n++;
    }   
    break;
  
   case 2:
    system("cls");
    printf("diga quando o cliente que deseja modificar aparecer\n");
    system("pause");
    do{
   for(c=0;c<global;c++){
     printf("caso deseje modificar o cliente de nome %s digite 1, caso nao digite 5\n",cl[c].nome);
     scanf("%d",&red);
     system("cls");
     
     if(red== 1){
      printf("diga o nome do cliente \n");
       scanf("%s",&cl[c].nome);
 
      printf("diga a hora do cliente \n");
       scanf("%f",&cl[c].hora);
 
      printf("diga o dia do cliente\n");
        scanf("%d",&cl[c].dia);
   
      printf("diga o mes do cliente\n");
        scanf("%s",&cl[c].mes);
     system("cls");
      }
     }
    }while(red !=5);
   break;

   case 3:
    system("cls");
     printf("o numero de total de clientes e: %d\n",n);
     system("pause");
     system("cls");
         
     
     break;
    

   case 4:
     for(c=0;c<global;c++){
      printf("\nInformacoes do %d cliente:\n",c+1);
      printf("| NOME: %s HORA %2.f DIA: %d MES: %s |\n\n",cl[c].nome, cl[c].hora, cl[c].dia, cl[c].mes);

     }
      system("pause");  
      system("cls");
     break;
     
   case 5:
    system("cls");
    break;
   }

 } while (dar !=5);

system("pause");
return (0);
}
//fim do comando central





//funçoes
int menu(){
  int x;
 printf("|-----------------------------Menu---------------------------------|\n");
 printf("| Menu do calendario de atendimento aos clientes, diga oq deseja   |\n");
 printf("| Caso deseje criar a lista digite 1                               |\n");
 printf("| Caso deseje remover um nome da agenda digite 2                   |\n");
 printf("| Caso deseje ver o total de clientes em cada mes digite 3         |\n");
 printf("| Caso deseje ver a lista de atendimento digite 4                  |\n");
 printf("| Caso deseje finalizar o processo digite 5                        |\n");
 printf("|------------------------------------------------------------------|\n");
 scanf("%d",&x);
 return (x);
}














//fim das funçoes
//feito em Visual Studio