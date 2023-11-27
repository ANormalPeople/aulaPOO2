#include <stdio.h>
#include <stdlib.h>

int main (){

    int var1,var2;

    scanf("%d %d",&var1,&var2);

    if(&var1>&var2){
        printf("\n%d",var1);
    }else{
        printf("\n%d",var2);
    }

    printf("\n\n\n%p \t %p",&var1,&var2);

    return 0;
}