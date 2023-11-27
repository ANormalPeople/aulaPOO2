#include <stdio.h>
#include <stdlib.h>


int main () {

int  num[10]={0},num2[10];

system("cls");

for( int c=0;c<10;c++){

 scanf("%d",&num2[c]);

  if(num2[c] >= 1 && num2[c] < 20){
  
  num[c] = num2[c];
  
  }else{
   c--; 
  }
}

 for(int m=0;m<10;m++){

for(int v=-1;v<num[m];v++){
 
  printf("**");
 
 }
 printf("\n");
}

system("PAUSE");
return 0;
}0