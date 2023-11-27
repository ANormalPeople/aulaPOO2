#include <stdio.h>


void mostrarSequencias(int n);

int main () {
    int c,n,a=0;
    
    while(a!=1){
        scanf("%d",&c);

    if(c>1 && c<1000){
      n=c;
      mostrarSequencias(n);
      a=1;
    }
    }
    return 0;
}

void mostrarSequencias(int n){
    int i,l,x=1,c=0;

    for(i=0;i<n;i++){
        c++;
        for(l=0;l<3;l++){
           x = c * x;
           printf("%d ",x);      
           
        }
        x=1;
        printf("\n");
    }

}