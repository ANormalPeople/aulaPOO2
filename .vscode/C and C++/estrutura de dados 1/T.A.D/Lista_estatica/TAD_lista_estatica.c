#include <stdio.h>
#include "TAD_lista_estatica.h"
#include <string.h>
#include <stdlib.h>
struct pessoa{
    int id,idade;
    float altura;
    char nome[100];
};

Pessoa *criar(){
    Pessoa *l;
    int tamanho;
    printf("diga o tamanho: ");
    scanf("%d",&tamanho);
    l =  (Pessoa*) malloc(sizeof(Pessoa) * (tamanho+1));    
    strcpy(l[tamanho+1].nome,"F_D_L");
    return l;
}

void inserirPessoaInicio(Pessoa *l){  
    int tamanho = contarPessoasNaLista(l);  
    for(int i=0;i<tamanho;i++){
        printf("Diga o nome, idade e altura(por linha) da pessoa %d abaixo:\n",i+1);
        l[i].id = i;
        scanf("%s",l[i].nome);
        scanf("%d",&l[i].idade);
        scanf("%f",&l[i].altura);
    }
}

void inserirPessoaFim(Pessoa *l){
    int tamanho = contarPessoasNaLista(l); 
    for(int i=tamanho-1;i>=0;i--){
        printf("Diga o nome, idade e altura(por linha) da pessoa %d abaixo:\n",i+1);
        l[i].id = i;
        scanf("%s",l[i].nome);
        scanf("%d",&l[i].idade);
        scanf("%f",&l[i].altura);
    }
}

void inserirPessoaOrdenado(Pessoa *l){
    int tamanho = contarPessoasNaLista(l); 
    inserirPessoaInicio(l);
    for(int x=0;x<tamanho;x++){
        for(int c=x;c<tamanho;c++){
            if(l[x].idade>l[c].idade){
                int aux1 = l[c].idade;
                l[c].idade = l[x].idade;
                l[x].idade = aux1;

                char aux2[100];
                strcpy(aux2, l[c].nome);
                strcpy(l[c].nome, l[x].nome);
                strcpy(l[x].nome, aux2);

                float aux3 = l[c].altura;
                l[c].altura = l[x].altura;
                l[x].altura = aux3;
            }
        }
    }
}

int contarPessoasNaLista(Pessoa *lista){
    int t=0;
    while(strcmp(lista[t].nome,"F_D_L")!=0){
        t++;
    }
    return t-1;
}

void mostrarPessoa(Pessoa p){
    printf("\n\nNome: %s\nIdade:%d\nAltura:%.2f",p.nome,p.idade,p.altura);
}

void mostrarTodasPessoas(Pessoa *l){
   int t = contarPessoasNaLista(l);
    for(int i=0;i<t;i++){
        mostrarPessoa(l[i]);
    }
}

void buscarPessoa(Pessoa *l){
    char aux1[100];
    int t = contarPessoasNaLista(l),aux2,x=0;
    float aux3;
    printf("\nDiga o nome, idade e altura(por linha) da pessoa que deseja buscar abaixo:\n");
    scanf("%s",aux1);
    scanf("%d",&aux2);
    scanf("%f",&aux3);
    for(int i=0;i<t;i++){
        if(strcmp(aux1,l[i].nome)==0 && aux2 == l[i].idade && aux3 == l[i].altura){
            mostrarPessoa(l[i]);
            x++;
            break;
        }
    }
    if(x==0){
        printf("\n\nSEM DADOS DA PESSOA CORRESPONDENTE");

    }

 }

void removerPessoa(Pessoa *l){
    int aux2,t = contarPessoasNaLista(l),x=0;
    float aux3;
    char aux1[100];

    printf("\nDiga o nome, idade e altura(por linha) da pessoa que deseja remover abaixo:\n");
    scanf("%s",aux1);
    scanf("%d",&aux2);
    scanf("%f",&aux3);

    for(int i=0;i<t;i++){
        if(strcmp(aux1,l[i].nome)==0 && aux2 == l[i].idade && aux3 == l[i].altura){
            for (int c = i; c < t; c++) {
                l[c].idade = l[c+1].idade;
                l[c].altura = l[c+1].altura;
                strcpy(l[c].nome,l[c+1].nome);
            }
            strcpy(l[t].nome,"F_D_L");
            l = (Pessoa*) realloc(l, (t-1) * sizeof(Pessoa));
            x++;
            break;
        }
    }
    if(x==0){
        printf("\n\nSEM DADOS DA PESSOA CORRESPONDENTE");
    }else{
        printf("\n sucesso!");
    }
}

void liberarMemoria(Pessoa *l){
    free(l);
}