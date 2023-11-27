#include <stdlib.h>
#include <stdio.h>

int main (){

 int x;
 long m, n, r;

  system("cls");

  scanf("%ld",&m);
  scanf("%ld",&n);
  x=0;
  while(r != 0){ 
  r = m % n;
  m = n;
  n = r;
  x++;
  }

  printf("\n%ld\n",m);
  
  
  printf("\nquantitade repitida:%d\n",x);

  system ("PAUSE");
  return 0;
  }