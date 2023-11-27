#include <stdio.h>
#include <stdlib.h>

int deXate0(int K, int Z){
    if(K==(Z+1)){
        return 0;
    }
    return (K-1) + deXate0((K - 1),Z);
}

int main () {

    int k,z,soma,temp;

    scanf("%d",&k);
    scanf("%d",&z);

    if(z>k){
        temp = z;
        z = k;
        k = temp;
    }

    soma = deXate0(k,z);
    printf("%d",soma);

    return 0;

}