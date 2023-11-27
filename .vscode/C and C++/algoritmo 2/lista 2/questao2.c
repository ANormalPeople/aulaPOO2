#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main (){

char nome[20], t, c;

system("cls");

scanf("%s",&nome);
t = strlen(nome);

for(c=0;c<t;c++){
printf("%c\t",toupper(nome[c]));
}

system("PAUSE");
return 0;
}