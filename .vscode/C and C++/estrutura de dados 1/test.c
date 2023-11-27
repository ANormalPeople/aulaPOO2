#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void primo(int a){
//     int i,count = 0;
//     if(a==1){
//         printf("nao e primo");
//     }
//     for(i=2;i<=a-1;i++){
//         int aux = a % i;
//         printf("%d",aux);
//         if(aux !=  0){
//             count ++;
//         }
//     }
//     if(count == (a-2)){
//         printf(" e primo");//nao é
//     }else{
//         printf("nao e primo");
//     }
// }
// 2&7 = 1
// 3&7 = 1
// 4&7 = 1
// 5&7 = 1
// 6&7 = 1

int main() {
    // int a,b;
    // scanf("%d %d",&a,&b);

    //     printf("%d",dividir(a,b));
    int a[] = {5,4,3,2,1};
    for(int l=0;l<5;l++){
        for(int c=l;c<5;c++){
        int aux = 0;
            if(a[l]>a[c]){
                aux = a[l];
                a[l] = a[c];
                a[c] = aux;
            }
        }
}
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    return 0;
}