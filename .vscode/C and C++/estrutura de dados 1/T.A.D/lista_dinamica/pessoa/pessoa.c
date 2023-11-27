#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    int id, idade;
    char nome[100];
    float altura;
    struct pessoa *prox;
};

Pessoa *criarlista(){
    Pessoa *l;
    l = NULL;
    return l;
}

void inserirPessoaInicio(Pessoa **l){
    Pessoa *new = (Pessoa*) malloc(sizeof(Pessoa));
    scanf("%s",new->nome);
    scanf("%d",&new->idade);
    scanf("%d",&new->id);
    scanf("%f",&new->altura);
    new->prox = *l;
    *l = new;
}

void inserirPessoaFim(Pessoa **l) {
    Pessoa *new = (Pessoa*) malloc(sizeof(Pessoa));
    scanf("%s", new->nome);
    scanf("%d", &new->idade);
    scanf("%d", &new->id);
    scanf("%f", &new->altura);
    new->prox = NULL; 
    if (*l == NULL) {
        *l = new; 
    } else {
 
        Pessoa *atual = *l;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = new;
    }
}

void inserirPessoaOrdenado(Pessoa **l) {
    
    Pessoa *new = (Pessoa*) malloc(sizeof(Pessoa));
    scanf("%s", new->nome);
    scanf("%d", &new->idade);
    scanf("%d", &new->id);
    scanf("%f", &new->altura);
    new->prox = NULL;

    if (*l == NULL || new->idade < (*l)->idade) {
        new->prox = *l;
        *l = new;
    } else {
        Pessoa *atual = *l;
        while (atual->prox != NULL && new->idade >= atual->prox->idade) {
            atual = atual->prox;
        }
        new->prox = atual->prox;
        atual->prox = new;
    }

}

void mostrarPessoa(Pessoa *p){
    printf("Nome: %s\nIdade: %d\nAltura: %.2f\nId: %d\n\n",p->nome,p->idade,p->altura,p->id);
}

void mostrarTodasPessoas(Pessoa *P){
    Pessoa *aux = P;
    while(aux != NULL){
        mostrarPessoa(aux);
        aux = aux->prox;
    }
}

int contarPessoasNaLista(Pessoa *P){
    Pessoa *aux = P;
    int num=0;
    while(aux != NULL){
        num++;
        aux = aux->prox;
    }
    return num;
}

void buscarPessoa(Pessoa *l){
    int id;
    scanf("%d",&id);
    printf("\nDados:\n\n");
    Pessoa *aux = l;
    while(aux != NULL){
        if(aux->id == id){
            mostrarPessoa(aux);
        }
        aux = aux->prox;
    }

}

void removerPessoa(Pessoa **l){
    int id;
    scanf("%d",&id);

    Pessoa *atual = *l;
    Pessoa *anterior = NULL;

    while(atual != NULL && atual->id != id ){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        printf("\n\nvalor não encontrado");
        return;
    }

    if(anterior == NULL){
        *l = atual->prox;
    }else{
        anterior->prox = atual->prox;
    }
    free(atual);
}

void liberarMemoria(Pessoa *lista){
    free(lista);
}