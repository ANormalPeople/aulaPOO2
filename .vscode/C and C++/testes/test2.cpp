
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Legenda das variáveis
//ct1 : contador de votos do candidato 1
//ct2 : contador de votos do candidato 2
//codi1 : Código do candidato 1
//codi2 : Código do candidato 2
//opcao : Item do item escolhido pelo usuário
//perc1 : Percentual de votos do candidato 1
//perc2 : Percentual de votos do candidato 2




//Algoritmo
int opcao;//percentual de votos do candidato 1
int codi1, codi2;//codigo dos condaditos
int  en, ct1, ct2;
float cont1, cont2;


int ObtemEscolha();//obtemescolha
int ImprimeMenu();//funçao menu
int ObtemPercentuais();//funçao percentual
int ImprimeVencedor();//funçao vencedora

int main (){
float perc1, perc2;//percentual de votos do candidato 2

ct1 = 0;
ct2 = 0;


printf("Diga o codigo do 1 candidato:\t");
scanf("%d",&codi1);
printf("Diga o codigo do 2 candidato:\t");
scanf("%d",&codi2);
system("cls");
//Leia codi1,codi2

do{
 opcao=ObtemEscolha();     //Chamada da função ObtemEscolha
 if(opcao==1) 
   ct1++;
  
 if(opcao==2)
   ct2++;
}while (opcao !=3);
printf("votacao encerrada!\n");
 ObtemPercentuais();
 ImprimeVencedor ();E
//Fim
}


//Descrição das funções:
//Nome: ImprimeMenu
//Entrada: Código dos 2 candidatos
//Descrição: Imprime um menu com 3 opções
//Item 1: Código do candidato 1
//Item 2: Código do candidato 2
//Item 3: Encerrar votação
//Saída: nenhuma

int ImprimeMenu(){
  en= 0  ;
      printf("-------------MENU-----------------\n");
      printf("O numero do primeiro concorrente e: %d\n",codi1);
      printf("O numero do segundo  concorrente e: %d\n",codi2);
      printf("Caso queria encerrar a votacao digite  3");
      printf("\n-----------MENU-----------------\n");
      system("pause");
      system("cls");
     
}


//Nome: ObtemEscolha
//Entrada: Código dos 2 candidatos.
//Saída: O valor da opção escolhida.
//Descrição: Imprime uma lista utilizando os 2 códigos informados (conforme a descrição do módulo
//ImprimeMenu). Faz a leitura do teclado para obter um valor escolhido pelo usuário (opção). Este valor deve estar
//dentro dos valores informados. Caso o valor esteja fora dos limites deve ser impressa a mensagem 'Opcao
//INVALIDA' e repetir a leitura de um novo valor até que este seja válido.
//OBS: Este módulo deve utilizar ImprimeMenu.
//Nome: ObtemPercentuais
 
 
 
 
  int ObtemEscolha(){
  int x,c,b;
    
    ImprimeMenu();
    
   b=0;
    printf("caso queira votar no 1 candidato digite %d\n Caso queira votar no 2 candidato digite %d\n ",codi1,codi2);
    scanf("%d",&x);
    system("cls");
    
    if(x==codi1){
    printf("\nVoce votou no 1 candidato\n");
    system("pause");
     c= 1;
    }

    if(x==codi2){
    printf("\nVoce votou no 2 candidato\n");
    system("pause");
    c= 2;
    }
    
    if(x !=codi1 && x !=codi2){
      printf("\nopcao invalido, confira o numero e vote novamente\n");
      system("pause");
      system("cls");
    }
  system("cls");
   printf("deseja encerrar?");
   scanf("%d",&en);
    if(en==3)
      c= en;
   return(c);
  
  }
//Entrada: Número de votos de cada um dos 2 candidatos.
//Saída: O percentual de cada candidato em relação ao total de votos.
//Nome: ImprimeVencedor
  int ObtemPercentuais(){
   int caut;
   caut = ct1 + ct2;
   cont1 = ct1 / caut * 100;
   cont2 = ct2 / caut * 100;
   printf("o numero de votos do 1 candidato e: %d, com um percentual de %.2f%% de votos",ct1, cont1);
   printf("\nO numero de votos do 2 candidato e: %d, com um percentual de %.2f%% de votos",ct2,cont2);
   system("pause");

 }


//Entrada: código do candidato 1, código do candidato 2, percentual de votos do candidato 1 e percentual de
//votos do candidato 2.
//Descrição: Imprime o código e o percentual de votos do candidato vencedor, ou a palavra empate. Saída:
//Nenhuma.
int ImprimeVencedor (){
  if(ct1>ct2)
  printf("\nO candidato vender foi o candidato de codigo %d com um percentual de %2.f%% dos votos",codi1, cont1);
  if(ct1<ct2)
  printf("\nO candidato vender foi o candidato de codigo %d com um percentual de %2.f%% dos votos",codi2, cont2);
  if(ct1==ct2)
  printf("\nEMPATE");

}