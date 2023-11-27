#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main () {
char nome[5][20];
float media[3], a[5][3], ma[3]={0}, me[3]={0};
int x[3], l, c;

system("cls");

for(l=0;l<5;l++){
  printf("diga o nome do aluno %d, sua altura, peso e IRA(em linhas diferentes)\n",l+1);
   scanf("%s",nome[l]);
  for(c=0;c<3;c++){
   scanf("%f",&a[l][c]);
   
   if(me[c] ==0){
    me[c] = a[l][c];
   }else if(a[l][c]<me[c]){
    me[c]= a[l][c];
   }
  }
   
   if(a[l][0]>ma[0] ){
    ma[0] = a[l][0];
      x[l]=l;
   }
    if(a[l][1]>ma[1] ){
    ma[1] = a[l][1];
      x[l]=l;
   }
    if(a[l][2]>ma[2] ){
    ma[2] = a[l][2];
      x[l]=l;
   }

   if(me[0] ==0){
    me[0] = a[l][0];
   }else if(a[l][0]<me[0]){
    me[0]= a[l][0];
   }
   
   if(me[1] ==0){
    me[1] = a[l][1];
   }else if(a[l][1]<me[1]){
    me[1]= a[l][1];
   }
   
   if(me[2] ==0){
    me[2] = a[l][2];
   }else if(a[l][2]<me[2]){
    me[2]= a[l][2];
   }
    system("cls");

  }

media[0]= a[0][0]+a[1][0]+a[2][0]+a[3][0]+a[4][0]/5;
media[1]= a[0][0]+a[1][1]+a[2][2]+a[3][3]+a[4][4]/5;
media[2]= a[0][0]+a[2][1]+a[2][2]+a[3][3]+a[4][4]/5;

printf("Altura, sua media foi de %.2f com a maior sendo %.2f e a menor %.2f\n",media[0],ma[0],me[0]);
printf("PESO, sua media foi de %.2f com a maior sendo %.1f e a menor %.2f\n",media[1],ma[1],me[1]);
printf("IRA, sua media foi de %.2f com a maior sendo %.1f e a menor %.2f\n",media[2],ma[2],me[2]);

printf("\n\n O(A) %s e o aluno com maior altura sendo ela %.2f\n",nome[x[0]],ma[0]);
printf("O(A) %s e o aluno com maior peso sendo ela %.2f\n",nome[x[1]],ma[1]);
printf("O(A) %s e o aluno com maior IRA sendo ela %.2f\n",nome[x[2]],ma[2]);

system("PAUSE");
return 0;
}

