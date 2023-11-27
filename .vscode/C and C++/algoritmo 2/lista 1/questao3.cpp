#include <stdio.h>
#include <stdlib.h>


int main () {

int c;
char d;
system("cls");

printf("destino?\n");
scanf("%c",&d);

printf("tipo de passagem?\n");
scanf("%d",&c);

switch (c)
{

case 1:

   if(d == 'a'){
      printf("\n900\n");
   }

   if(d == 'b'){
      printf("\n650\n");
   }

   if(d == 'c'){
      printf("\n600\n");
   }

   if(d == 'd'){
      printf("\n550\n");
   }
 break;

case 0:
  if(d=='a'){
      printf("\n500\n");
   }

   if(d=='b'){
      printf("\n350\n");
   }

   if(d=='c'){
      printf("\n350\n");
   }

   if(d=='d'){
      printf("\n300\n");
   }
 break;
 

}

system ("PAUSE");
return 0;
}