#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct pessoa{
    int id, idade;
    char nome[100];
    float altura;
    struct pessoa *prox,*ant;
};

Pessoa *criarlista(){
    return NULL;
}

Pessoa *inserir(Pessoa *l){
    Pessoa *novo = (Pessoa*) malloc(sizeof(Pessoa));
    scanf("%d",&novo->idade);
    scanf("%f",&novo->altura);
    scanf("%s",novo->nome);
    novo->id = rand() % 1000 + 100;
    novo->ant = NULL;//So pode ficar se voce quiser inserir no inicio
    if(l == NULL){
        novo->prox = NULL;
    }else{
        l->ant = novo;
        novo->prox = l;
    }
    return novo;
}


void mostrarPessoa(Pessoa *l){
        printf("\n%s",l->nome);
        printf("\n%d",l->idade);
        printf("\n%.2f",l->altura);
        printf("\n%d\n",l->id);
}

void mostrarTodasPessoas(Pessoa *l){
    Pessoa *aux = l;

    while(aux != NULL){
        mostrarPessoa(aux);
        aux = aux->prox;
    }
}

Pessoa *removerPessoa(Pessoa *l){
    int id;
    scanf("\n\n%d",&id);
    Pessoa *atual=l;
    Pessoa *anterior = NULL;

    while(atual != NULL && atual->id != id){
        anterior = atual;
        atual = atual->prox;

    }
    if(atual == NULL){
        printf("PESSOA NAO ENCONTADA!!");
        return l;
    }

    if(anterior == NULL){
        l = atual->prox;
    }else{
        anterior->prox = atual->prox; 
    }
    free(atual);
    return l;
}
