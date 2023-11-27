#include <stdio.h>

int main () {

    float matriz[3][3];

    for(int l=0;l<3;l++){
        for(int c=0;c<3;c++){
            printf("%d|%d: %p\n",l,c,&matriz[l][c]);        
        }
    }

    return 0;
}