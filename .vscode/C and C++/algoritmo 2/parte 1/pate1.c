#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000


typedef struct{
    int codigo;
    char nome[20];
}registro;

typedef struct{
registro itens[MAX+1];
int tamanho;
}tabela;

tabela tab;

void inserir();

int main () {


        inserir();
    

    return 0;

}

void inserir ( ){
    int i;

    srand(time(NULL));
    for(i=0;i<1000;i++){
        sprintf(tab.itens[i].nome, "Gol");
        tab.itens[i].codigo=rand()%1000;
    }

  for (i = 0; i < 1000; i++) {
        printf("%s: %d\n",tab.itens[i].nome,tab.itens[i].codigo);
    }
}
