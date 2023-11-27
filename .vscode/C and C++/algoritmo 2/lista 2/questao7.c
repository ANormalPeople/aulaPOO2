#include <stdio.h>
#include <stdlib.h>
int main () {

int vet[]={2,4,6,8,10,12,14,16,18,20};

system("cls");
 printf("elemento:\tvalor:\n");

for(int c=0;c<10;c++){
    printf("%d\t\t%d\n",c,vet[c]);
}

system("PAUSE");
return(0);  
}