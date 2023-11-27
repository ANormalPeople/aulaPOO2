#include <stdio.h>
#include <stdlib.h>

void atezero(int N){
    if(N<0){
        return;
    }
    printf("%d ",N);
    return atezero(N-1);
}

int main () {

    int N;
    scanf("%d",&N);
    atezero(N);

    return 0;
}