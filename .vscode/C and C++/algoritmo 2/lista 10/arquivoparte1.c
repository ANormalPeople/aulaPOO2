#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

typedef struct{
    int codigo;
    char nome[20];
}registro;

typedef struct{
    registro itens[MAX+2];
    int tamanho;
}tabela;


typedef struct{
    registro itens2[MAX+2];
    int tamanho2;
}tabelavazia;

tabela tab;
tabelavazia tab2;  
 

void inserireprintar();
void SalvarDados(const char* nome_arquivo);
void restaurarDados(const char* nome_arquivo);
void insercao();

int main() {

   int resp;
   char nome[100];

    inserireprintar();    

    printf("Sistema de backup de dados\n");
    printf("Informe a operacao desejada (1-salvar, 2-restaurar):\n");
    scanf("%d",&resp);
    printf("\nInforme o nome do arquivo de backup:\n");
    scanf("%s",nome);

    if(resp==1){
        SalvarDados(nome);
    }else{
        restaurarDados(nome);
    }

    printf("Operacao concluida com sucesso!");


    // TESTES
    // for (int i = 1; i < tab.tamanho; i++) {
    //  printf("%d%s: %d\n",i, tab2.itens2[i].nome, tab2.itens2[i].codigo);
    //  }
    
    return 0;
}

void inserireprintar(){
    int i;

    srand(time(NULL));
    for(i = 1;i <= (MAX+1); i++){
        sprintf(tab.itens[i].nome, "Gol");
        tab.itens[i].codigo = rand() % 1001;
        tab.tamanho++;
    }
   
   insercao(); 

    // TESTES
    // for (i = 1; i < tab.tamanho; i++) {
    // printf("%d%s: %d\n",i, tab.itens[i].nome, tab.itens[i].codigo);
    // }
}

void insercao() {
    int i, j;
    registro aux;
    for(i=1;i<tab.tamanho;i++){
        aux = tab.itens[i];
        j = i - 1;
        while((j>=0)&&(tab.itens[j].codigo > aux.codigo)){
            tab.itens[j + 1] = tab.itens[j];
            j--;
        }
     tab.itens[j+1] = aux;
    }
}

void SalvarDados(const char* nome_arquivo) {
    FILE* arquivo;
    int i;

    if ((arquivo = fopen(nome_arquivo, "wb")) != NULL) {
        for(i = 0; i < tab.tamanho; i++) {
            fwrite(&tab.itens[i], sizeof(tabela),1, arquivo);
        }
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para gravacao.\n");
    }
}

void restaurarDados(const char* nome_arquivo){
    FILE* arquivo;
    if ((arquivo = fopen(nome_arquivo, "rb")) != NULL) {
        int i = 0;
        while(fread(&tab2.itens2[i], sizeof(tabela), 1, arquivo) == 1) {
            i++;
        }
        tab2.tamanho2 = i;
        fclose(arquivo);

    } else {
        printf("Erro ao abrir o arquivo para gravaco.\n");
    }
}