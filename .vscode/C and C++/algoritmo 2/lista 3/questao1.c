#include <stdio.h>
#include <stdlib.h>

int inverter(int v);

int main (){

system("cls");
int m, n=0;

    scanf("%d",&n);

n = inverter(n);

printf("%d\n",n);

system("PAUSE");
return 0;
}

//AREA DAS FUNÇOES

int inverter(int v){
  int d = 0;

  while(v>0){
     d= 10 * d + v % 10;
     v = v / 10;

  }


return d;
}