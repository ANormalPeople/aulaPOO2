#include <stdio.h>
#include <stdlib.h>

void nvarquivo_saida(int **saida,int a, int b);
void arquivo_clusters(int **mat,int a, int b);

int main () {

    int **mat,M,N;
    FILE *arquivo;

    arquivo = fopen("input.txt","r");
    if(arquivo == NULL){
        printf("erro ao abrir o arquivo");
        return 1;
    }

    fscanf(arquivo,"%d",&M);
    fscanf(arquivo,"%d",&N);

    mat = (int**) malloc(M * sizeof(int*));

    for(int i=0; i<N;i++){
        mat[i] = (int*) malloc(N * sizeof(int));
    }

    for (int l = 0; l < M; l++) {
        for (int c = 0; c < N; c++) {
            fscanf(arquivo, "%d", &mat[l][c]);
        }
    }
    fclose(arquivo);

    arquivo_clusters(mat,M,N);
    nvarquivo_saida(mat,M,N);

    return 0;
}

void nvarquivo_saida(int **saida,int a, int b){

    FILE* arquivo2;
    int i;

    if ((arquivo2 = fopen("saida.txt", "w")) != NULL) {
        fprintf(arquivo2, "%d\n", a);
        fprintf(arquivo2, "%d\n", b);
        for(i = 0; i < a; i++) {
            for(int l=0;l<a;l++){
                
                fprintf(arquivo2, "%d ", saida[i][l]);
            }
            fprintf(arquivo2, "\n");
        }
        fclose(arquivo2);
    } else {
        printf("Erro ao abrir o arquivo para gravacao.\n");
    }
}

void arquivo_clusters(int **mat,int a, int b){
    int rotulo = 255;
    int semente_x = 690;
    int semente_y = 440;
    FILE *arquivo;
    arquivo = fopen("input.txt","r");
    if(arquivo == NULL){
        printf("erro ao abrir o arquivo");
        exit(1);
    }

    for(int i = 0; i< a; i++){
        for(int l=0;l<b;l++){
            int dif_x = abs(semente_x - i);
            int dif_y = abs(semente_y - l);
            if(dif_x < 100 && dif_y < 100){
                mat[i][l] = rotulo;
            }else{
                mat[i][l] = 0;
            }
               
        }
    }

    fclose(arquivo);
}