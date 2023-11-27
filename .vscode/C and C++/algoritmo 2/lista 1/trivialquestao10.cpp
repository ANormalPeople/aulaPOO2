#include <stdio.h>
#include <stdlib.h>



int main () {
int i, aux, a, b, x;

 system("cls");
 scanf("%d%d",&a, &b);
 
 if (a<b){//swap
  aux = a;
   a = b;
   b= aux;
 }
 
  for(i=a; i > 1 && !(a%i==0 && b%i==0); i--){
 }

 printf("\n%d\n",i);

 system("PAUSE");
 return 0;
}

