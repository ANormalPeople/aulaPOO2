#include <stdio.h>
#include <stdlib.h>


int main () {
 int m;
 float v, t;


 system("cls");
 printf("quantidade?\n");
 scanf("%d",&m);

  if(m<12){
    v=1.30;
    t= m * v;

  }else{
    v=1;
    t= m * v;
  }

 printf("\nvalor:%.2f\n",t);

 system ("PAUSE");
 return 0;
}