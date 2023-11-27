#include <stdio.h>
#include <stdlib.h>
#include "conta.h"


struct conta{
    int id;
    char nome[50];
    float saldo;
    struct conta *prox;
};

Conta *criar(){
    return NULL;
}

Conta *inserir(Conta *l){
   Conta *nova = (Conta*) malloc(sizeof(Conta));
    scanf("%s",nova->nome);
    scanf("%d",&nova->id);
    scanf("%f",&nova->saldo);

    nova->prox = NULL; 
    if (l == NULL) {
        l = nova; 
    } else {
 
        Conta *atual = l;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = nova;
        return  atual;
    }

    return  l;
}

void mostrar(Conta *l){
    Conta *aux = l;
    while(aux != NULL){
        printf("\n\n%s\n",aux->nome);
        printf("%d\n",aux->id);
        printf("%.2f",aux->saldo);
        aux = aux->prox;
    }
}

Conta *remover(Conta *l){
    int id;
    printf("ID:");
    scanf("%d",&id);
    Conta *atual = l;
    Conta *ant = NULL;
    while ( id != atual->id || atual != NULL) {
        ant = atual;
        atual = atual->prox;
    }    

    if(atual == NULL){
        printf("Conta não encontrada!!!");
        return l;
    }
    if(ant == NULL){
       l = atual->prox; 
    }else{
        ant->prox = atual->prox;
    }
    free(atual);
    return l;
}
