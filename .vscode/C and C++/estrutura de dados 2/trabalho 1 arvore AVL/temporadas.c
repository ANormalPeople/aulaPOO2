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

    int verifica = insesrirAVL_T(raiz, no);

    if (verifica != 0)
        printf("Serie inserida com sucesso!\n");
    else
        printf("Erro ao inserir a serie. Codigo ja existe.\n");
    return verifica;
}

int insesrirAVL_T(Temporadas **raiz,Temporadas *no){
	int FB,inseriu = 1;

	if(*raiz == NULL)//1
		*raiz = no;
	else if(no->numero_da_Temporada < (*raiz)->numero_da_Temporada){
		insesrirAVL_T((&(*raiz)->esquerda),no);
	}else if(no->numero_da_Temporada > (*raiz)->numero_da_Temporada){
		insesrirAVL_T((&(*raiz)->direita),no);
    }else{
        inseriu = 0;
    }
	FB = Altura_T((*raiz)->esquerda) - Altura_T((*raiz)->direita);
	if(FB == 2){
		int FBesq;
		Temporadas *aux;
		aux = (*raiz)->esquerda;
		FBesq = Altura_T(aux->esquerda) - Altura_T(aux->direita);
		if(FBesq == 1)
			rotacaoDireita_T(raiz);//4
		else if(FBesq == -1){
			rotacaoEsquerda_T(&((*raiz)->esquerda));//5
			rotacaoDireita_T(raiz);//5
		}
	}else if(FB == -2){
        int FBdir;
        Temporadas *aux;
        aux = (*raiz)->direita;
        FBdir = Altura_T(aux->esquerda) - Altura_T(aux->direita);
        if(FBdir == -1)
            rotacaoEsquerda_T(raiz);
        else if(FBdir == 1){
		rotacaoDireita_T(&((*raiz)->direita));//5
		rotacaoEsquerda_T(raiz);//5
        }
    }
    return inseriu;
}

void rotacaoDireita_T(Temporadas **raiz){
    Temporadas *aux = (*raiz)->esquerda;
    (*raiz)->esquerda = aux->direita;
    aux->direita =  *raiz;
}

void rotacaoEsquerda_T(Temporadas **raiz){
    Temporadas *aux = (*raiz)->direita;
    (*raiz)->direita = aux->esquerda;
    aux->esquerda = *raiz;
}


int Altura_T(Temporadas *raiz) {
    int valor = -1;
    if (raiz != NULL) {    
        int altura_esquerda = Altura_T(raiz->esquerda);
        int altura_direita = Altura_T(raiz->direita);

        if (altura_esquerda > altura_direita)
            valor = 1 + altura_esquerda;
        else
            valor = 1 + altura_direita;
    }
    return valor;
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