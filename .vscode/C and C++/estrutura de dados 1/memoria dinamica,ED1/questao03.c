#include <stdio.h>
#include <stdlib.h>

void obtem_produtos_zerados(int *codigo,int *estoque,int *num,int **zero,int *total);

int main () {

    int codigo[5]={1,2,3,4,5},estoque[5]={0,24,97,0,0};
    int num = sizeof(codigo)/sizeof(codigo[0]);
    int *zerados,total=0;

    obtem_produtos_zerados(codigo, estoque, &num, &zerados,&total);

    printf("CODIGO DOS PRODUTOS ZERADOS:\n\n");
    for(int i=0;i<total;i++){
        printf("%d\n",zerados[i]);
    }

    free(zerados);

}

void obtem_produtos_zerados(int *codigo,int *estoque,int *num,int **zero,int *total){
    int N=1;
    *zero = malloc(N * sizeof(int));
    if (*zero==NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    for (int i = 0; i < *num; i++) {
        if (estoque[i] == 0) {
            (*zero)[*total] = codigo[i];
            (*total)++;
            if (*total == N) {
                N*=2;
                int *temp=realloc(*zero, N * sizeof(int));
                if (temp == NULL) {
                    printf("Erro na realocação de memória.\n");
                    free(*zero);
                    exit(1);
                }
                *zero=temp;
            }
        }
    }
}

/*#include <stdio.h>
#include <stdlib.h>

void obtem_produtos_zerados(int *codigo,int *estoque,int *numcod,int *numest,int **zero,int *total);

int main () {

    int codigo[5]={1,2,3,4,5},estoque[5]={85,24,97,0,0};
    int numcod = sizeof(codigo)/sizeof(codigo[0]),numest = sizeof(estoque)/sizeof(estoque[0]);
    int *zerados,total=0;

    obtem_produtos_zerados(codigo, estoque, &numcod, &numest, &zerados,&total);

    printf("CODIGO DOS PRODUTOS ZERADOS:\n\n");
    for(int i=0;i<total;i++){
        printf("%d\n",zerados[i]);
    }

    free(zerados);

}

void obtem_produtos_zerados(int *codigo,int *estoque,int *numcod,int *numest,int **zero,int *total){
    int N=1;

    if (*zero == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);

    for(int i = 0;i<*numcod;i++){

        if(estoque[i] == 0){
            (*zero)[*total] = codigo[i];
            (*total)++;
        }

        if (*total == N) {
            N *= 2;
            int *temp = realloc(*zero, N * sizeof(int));
            if (temp == NULL) {
                printf("Erro na realocação de memória.\n");
                free(*zero);
                exit(1);
            }
            *zero = temp;
        }
    }

}*/