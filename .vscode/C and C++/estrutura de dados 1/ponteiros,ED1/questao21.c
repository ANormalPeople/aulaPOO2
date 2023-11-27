#include <stdio.h>

int main () {

    int i=0,array[5]={0},*a;
    a = array;

    while(i<5){
        *a+=1;    
        a++;
        i++;
    }
    for (int c=0;c<5;c++){
        printf("%d\n",array[c]);
    }

    return 0;
}