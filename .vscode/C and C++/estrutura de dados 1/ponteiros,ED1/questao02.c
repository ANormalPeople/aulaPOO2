#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

int var1,var2;

if(&var1>&var2){
    printf("%p",&var1);
}else{
    printf("%p",&var2);
}

printf("\n\n\n%p \t %p",&var1,&var2);
return 0;
} 
