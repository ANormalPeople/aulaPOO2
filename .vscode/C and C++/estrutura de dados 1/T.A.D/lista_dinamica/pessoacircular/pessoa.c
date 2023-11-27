#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct pessoa{
    int id, idade;
    char nome[100];
    float altura;
    struct pessoa *prox;
};

Pessoa *criarlista(){
    return NULL;
}

Pessoa *Inserir(Pessoa *l){
    Pessoa *novo = (Pessoa*) malloc(sizeof(Pessoa));
    Pessoa *aux;
    scanf("%d",&novo->idade);
    scanf("%f",&novo->altura);
    novo->id = rand() % 1000+100;
    scanf("%s",novo->nome);
    if(l==NULL){
        novo->prox = novo;
        return novo;
    }else{
        aux = l;
        while(aux->prox != l){
            aux=aux->prox;
        }        
        aux->prox=novo;
        novo->prox=l;
    }
    return l;
}


void mostrarPessoa(Pessoa *p){
    printf("\n\nNome: %s",p->nome);
    printf("\nIdade: %d",p->idade);
    printf("\nAltura: %f",p->altura);
    printf("\nID: %d",p->id);
}

void mostrarTodasPessoas(Pessoa *p){
    Pessoa *aux = p;

    if(p == NULL){
        printf("lista vazia");
    }

    do{
        mostrarPessoa(aux);
        aux=aux->prox;
    }while(aux != p);

}

Pessoa *removerPessoa(Pessoa *p, int id) {
    if (p == NULL) {
        printf("Lista vazia!!!\n");
        return NULL;
    }

    Pessoa *atual = p;
    Pessoa *ant = NULL;

    do {
        if (atual->id == id) {
            if (ant == NULL) {
                Pessoa *ultimo = p->prox;
                while (ultimo->prox != p) {
                    ultimo = ultimo->prox;
                }
                if (ultimo == p) {
                    free(p);
                    return NULL;
                }
                p = atual->prox;
                ultimo->prox = p;
            } else {
                ant->prox = atual->prox;
            }
            free(atual);
            return p;
        }
        ant = atual;
        atual = atual->prox;
    } while (atual != p);

    printf("\nPessoa não encontrada!!!\n");
    return p;
}


//covid influenza DT e