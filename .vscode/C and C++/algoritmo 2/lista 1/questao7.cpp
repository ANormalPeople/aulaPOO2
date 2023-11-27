#include <stdio.h>
#include <stdlib.h>

int main () {
system("cls");
int c, x, y, cont, mutl;

scanf("%d",&x);
scanf("%d",&y);
mutl=1;
cont=0;
for(c=x;c<=y;c++){

   if(c%2==0){
    cont+=c;
   }
   if(c%2==1){
    mutl*=c;
   }
}
printf("\n %d \n %d \n",cont, mutl);


system("PAUSE");
return 0;
}

//pelo oq eu entendi x sempre sera menor que y ja que X < Y-2
