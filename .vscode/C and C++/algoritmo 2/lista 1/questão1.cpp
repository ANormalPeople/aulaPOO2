#include <stdio.h>
#include <stdlib.h>


int main () {
float c, v, a;


system("cls");
printf("compra\n");
scanf("%f",&c);

if(c < 20){
a = c* 45 / 100;
}else{

a = c* 30 / 100;
}

v= a + c;
printf("\nvenda:%.2f\n",v);
system("pause");
return 0;
}
