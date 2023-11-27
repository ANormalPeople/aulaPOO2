#include <stdio.h>
#include <conio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include <stdio.h>
#include<time.h>//necessário p/ função time()
int main(void)
{
  int i;
  
  printf("Gerando 10 valores aleatorios:\n\n");
  
  /* srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
  com o valor da função time(NULL). Este por sua vez, é calculado
  como sendo o total de segundos passados desde 1 de janeiro de 1970
  até a data atual.
  Desta forma, a cada execução o valor da "semente" será diferente.
  */
  srand(time(NULL));
  
  for (i=0; i < 10; i++)
  {
    // gerando valores aleatórios na faixa de 0 a 100
    printf("%d ", rand() % 100);
  }
  
  getch();
  return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct alunos
{

  char aluno[20];
  float altura[5];
  float peso[5];
  float IRA[5];

};

int main (){
    int c, x[3];

    struct alunos al[c] , maior, media;

    system("cls");

    for(c=0;c<3;c++){
       scanf("%s",&al[c].aluno);
       scanf("%f",&al[c].altura);
       scanf("%f",&al[c].peso);
       scanf("%f",&al[c].IRA);
     

       media.altura = al[c].altura + media.altura;
       media.peso  = al[c].peso + media.peso;
       media.IRA = al[c].IRA + media.IRA;



       if(al[c].altura>maior.altura){
         maior.altura = al[c].altura;
         X[0] = c;
       }
       if(al[c].peso>maior.peso){
         maior.peso = al[c].peso;
         X[1] = c;
       } 
      
       if(al[c].IRA>maior.IRA){
         maior.IRA = al[c].IRA;
         X[2] = c;
       }
 
       setbuf(stdin, NULL);

    } 

    media.altura = media.altura / 5;
    media.peso = media.peso / 5;
    media.IRA = media.IRA / 5;



     printf("Media de peso:%f\nMedia de altura:%f\nMedia de IRA:%f",media.peso,media.altura,media.IRA);
     printf("Maior peso:%s%f\nMaior altura:%s%f\n",al[x[0]].aluno,maior.peso,al[x[1]].aluno,maior.altura);
     printf("Maior IRA:%s%f",al[x[2]].aluno,maior.IRA);






    system("PAUSE");
    return 0;
}