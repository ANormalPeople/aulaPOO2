#include <stdio.h>
#include <string.h>
int encaixa(const char *s1, const char *s2);

int main () {
    int k=0,c,z,i,x,s1,s2;

    
    
    while(k!=1){
        scanf("%d",&c);
        if(c>1 && c<1000){            
            x=c;
            for(i=0;i<x;i++){
                scanf("%d %d",&s1 ,&s2);
                z = encaixa(s1,s2);
                k=1;
            }
        }
    
    }

    if(z==0)
      printf("Encaixa");
    if(z==1)
      printf("Nao encaixa"); 

    return 0;
}


int encaixa(const char *s1, const char *s2){
    int x,i,cont = 0;

    for(i=0;i<=*(s2+i);i++){
       s1+=1;
       if(*(s1+i)>=*(s2+i))
       x =strcmp(*(s2+i),*(s1+i));    
    }
    if(x==0){
        x=1;
    }  
    if(x==-1){
        x=0;
    }
    if(x==1){
        x=0; 
    }
    
    return x;
}