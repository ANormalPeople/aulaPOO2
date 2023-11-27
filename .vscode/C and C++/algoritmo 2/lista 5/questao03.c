#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void maiusculo(char *sPtr);

int main(){
	char s[50][50];
    int num,x=0,c;
	system("cls");


    while(1){
        scanf("%d",&num);
        if(num==0){
            break;
        }
        scanf("%[^\n]s",s[x]);
        x+=1;
    }

   for(c=0;c<x;c++){
       printf("\n"); 
       maiusculo(s[c]);
   }
  
    return 0;
    system("PAUSE"); 
}

void maiusculo(char *sPtr){

	printf( "%s",strupr(sPtr));

}
