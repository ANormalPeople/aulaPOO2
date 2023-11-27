#include <stdio.h>
#include <stdlib.h>

int deXate0(int K){
    if(K==0){
        return 0;
    }
    return K + deXate0(K - 1);
}

int main () {

int k,soma;

scanf("%d",&k);
soma = deXate0(k);
printf("%d",soma);

return 0;

}