#include <stdio.h>

int main () {

    int array[5],i;

    for(i=0;i<5;i++){
        scanf("%d",&array[i]);
    }

    for(i=0;i<5;i++){
        if(array[i]%2==0)
            printf("%p \n",&array[i]);
    }

    return 0;
}