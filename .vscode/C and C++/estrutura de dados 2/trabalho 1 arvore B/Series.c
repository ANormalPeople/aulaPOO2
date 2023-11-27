#include "temporadas.h"
#include "Series.h"
#include "participantes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct series{
    int codigo;
    char titulo[100];
    int numTemporadas;
    Temporadas *temporadas; 
    struct series *esquerda; 
    struct series *direita; 

};


void cadastrarSerie(Series** raiz) {
    Series *no = (Series*)malloc(sizeof(Series));

	printf("\n\nDiga o codigo: ");
	scanf("%d", &no->codigo);
	printf("Diga o titulo: ");
	scanf(" %[^\n]",no->titulo);
	no->numTemporadas = 0;
	no->direita = NULL;
	no->esquerda = NULL;
	no->temporadas = NULL;

    int verifica = insesrir_S(raiz, no);

    if (verifica != 0)
        printf("Serie inserida com sucesso!\n");
    else
        printf("Erro ao inserir a serie. Codigo ja existe.\n");
}


int insesrir_S(Series **raiz,Series *no){
	int inseriu = 1;

	if(*raiz == NULL)
		*raiz = no;

	else if(no->codigo < (*raiz)->codigo)
		inseriu = insesrir_S((&(*raiz)->esquerda),no);
	else if(no->codigo > (*raiz)->codigo)
		inseriu = insesrir_S((&(*raiz)->direita),no);
	else
		inseriu = 0;

	return inseriu;
	
}

void pre_ordem(Series *raiz){

	if(raiz != NULL){
        printf("\nCodigo: %d ", raiz->codigo);
        printf("\nTitulo: %s ", raiz->titulo);
        printf("\nNumero de temporadas: %d\n", raiz->numTemporadas);
		pre_ordem(raiz->esquerda);
		pre_ordem(raiz->direita);
	}
}

void ordenado_S(Series* raiz) {
    if (raiz != NULL) {
        ordenado_S(raiz->esquerda);
        printf("\nCodigo: %d ", raiz->codigo);
        printf("\nTitulo: %s ", raiz->titulo);
        printf("\nNumero de temporadas: %d\n", raiz->numTemporadas);
        ordenado_S(raiz->direita);
    }
}

Series *busca_codigo_S(Series* raiz, int id) {
	Series *aux;
	aux = NULL;
	if (raiz != NULL){

		if (raiz->codigo == id)
			aux = raiz;

		else if (id < raiz->codigo)
			aux = busca_codigo_S(raiz->esquerda, id);
		else if (id > raiz->codigo)
			aux = busca_codigo_S(raiz->direita, id);

	}
	return aux;

}

void liberaSerie(Series *a){
	if (a != NULL){
		liberaSerie(a->esquerda);
		liberaSerie(a->direita);
		liberatemp(a->temporadas);
		free(a);
	}
}