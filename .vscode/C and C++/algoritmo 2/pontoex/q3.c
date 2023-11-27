#include <stdio.h>
#include <string.h>


int encaixa(const char *s1, const char *s2);
// 0 nao 1 sim


int main () {
    int z,ct,i;
    char a_valor[1000], b_valor[1000];


    scanf("%d", &ct);
    for (i=0; i<ct; i++) {
        scanf("%s", a_valor);
        scanf("%s", b_valor);

        encaixa(a_valor,b_valor);

        
    }
        if((z=encaixa(a_valor,b_valor))==1){
            printf("encaixa");
        }else{
            printf("nao encaixa");    

    return 0;
}


int encaixa(const char *s1, const char *s2){
    int z, a_tamanho, b_tamanho, encaixa, j;


    a_tamanho = strlen(s1);
    b_tamanho = strlen(s2);

        for (j=1; j<=b_tamanho; j++) {
            if (s1[(a_tamanho-j)] == s2[(b_tamanho-j)]) {
                encaixa++;
            }
        }

        if (encaixa == b_tamanho) {
           z= 1;
        }
        else {
            z= 0;
        }
        
        return z;
    
    }





}