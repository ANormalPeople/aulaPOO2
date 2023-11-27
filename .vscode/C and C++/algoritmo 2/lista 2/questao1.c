
#include <stdio.h>
#include <stdlib.h>

int main () {

int a[11]={0}, c, n;

system("cls");

while(n!=-1){
scanf("%d",&n);
for(c=0;c<11;c++){
if(n==c){
 a[c]++;
}
}
}

for(c=0;c<11;c++){
 printf("%d\t%d\n", c, a[c]);
}

system ("PAUSE");
return  0;
}