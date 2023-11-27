#include <stdio.h>
#include <stdlib.h>

int main (){
float s, d ,v;
 system("cls");
 printf("salario?\n");
 scanf("%f",&s);


 if(s<=600){
  d = 0;
  v = s;
 }

 if(s>600 && s<=1200 ){
  d = s * 20 / 100;
  v = s - d;
 }

 if(s>1200 && s<=2000){
  d = s * 25 / 100;
  v = s - d;

 }

 if(s>2000){
  d = s * 30 / 100;
  v = s - d;
 }

 printf("desconto:\t%.2f \n valor final:\t%.2f\n",d,v); 

 system("pause");
 return 0;
}