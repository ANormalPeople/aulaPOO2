#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

char str[100],h[3];
int d[5], n[5], i, cat;
system("cls");

printf("diga quantos contratos voce deseja que o progama leia, apos isso escreva primeiro o numero errado e depois o numero total\n");
scanf("%d",&cat);
system("cls");

for(int b=0;b<cat;b++){
scanf("%d%d",&d[b], &n[b]);
}

printf("\n");

for(int c=0;c<cat;c++){
sprintf(str,"%d",n[c]);
sprintf(h,"%d",d[c]);


for(i=0;i<strlen(str);++i){

 if(h[0] != str[i]){

 printf("%c",str[i]);

 }

}
printf("\n");
}

printf("\n");

system("PAUSE");
return 0;    
}