#include "temporadas.h"
#include "Series.h"
#include "participantes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct temporadas {
    int numero_da_Temporada;
    char tituloTemporada[100];
    int qtdEpisodios;
    int ano;
    Participantes* participantes; 
    struct temporadas* esquerda;
    struct temporadas* direita;     
};

int cadastrarTemporada(Temporadas** raiz) {

    Temporadas *no = (Temporadas*)malloc(sizeof(Temporadas));

	printf("Diga o Titulo da temporada: ");
	scanf(" %[^\n]",no->tituloTemporada);
	printf("Diga o numero da temporada: ");
	scanf("%d", &no->numero_da_Temporada);
	printf("Diga o ano: ");
	scanf("%d", &no->ano);
	printf("Diga a quantidade de episodios: ");
	scanf("%d", &no->qtdEpisodios);
	no->direita = NULL;
	no->esquerda = NULL;
    no->participantes = NULL;

    int verifica = insesrir_T(raiz, no);

    if (verifica != 0)
        printf("Temporada inserida com sucesso!\n");
    else
        printf("Erro ao inserir a Temporada. Codigo ja existe.\n");
    return verifica;
}

int insesrir_T(Temporadas **raiz,Temporadas *no){
	int inseriu = 1;

	if(*raiz == NULL)
		*raiz = no;

	else if(no->numero_da_Temporada < (*raiz)->numero_da_Temporada)
		inseriu = insesrir_T((&(*raiz)->esquerda),no);
	else if(no->numero_da_Temporada > (*raiz)->numero_da_Temporada)
		inseriu = insesrir_T((&(*raiz)->direita),no);
	else
		inseriu = 0;

	return inseriu;
}

Temporadas* busca_codigo_T(Temporadas* raiz, int id) {
    Temporadas *aux_temp;
    aux_temp = NULL;
    if (raiz != NULL){

        if (raiz->numero_da_Temporada == id)
            aux_temp = raiz;
        else if (id < raiz->numero_da_Temporada)
            aux_temp = busca_codigo_T(raiz->esquerda, id);
        else if (id > raiz->numero_da_Temporada)
            aux_temp = busca_codigo_T(raiz->direita, id);
    }

    return aux_temp;
}


void ordenado_T(Temporadas *raiz) {
    if (raiz != NULL) {
        ordenado_T(raiz->esquerda);
        printf("\n\nNOME: %s \n", raiz->tituloTemporada);
        printf("ANO: %d \n", raiz->ano);
        printf("Quantidade de episodios: %d \n", raiz->qtdEpisodios);
        printf("Codigo da temporada: %d \n", raiz->numero_da_Temporada);
        ordenado_T(raiz->direita);
    }
}

void mostrar_artista(Temporadas *raiz,char nome[100]){
    if(raiz != NULL){
        mostrar_artista(raiz->esquerda,nome);
        mostrar_todos_artistas(raiz->participantes,nome);
        mostrar_artista(raiz->direita,nome);
    }
}

void liberatemp(Temporadas *a){
	if (a != NULL){
	    liberatemp(a->esquerda);
	    liberatemp(a->direita);
        liberarMem_P(a->participantes);
	    free(a);
    }
}