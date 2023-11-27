#include "temporadas.h"
#include "Series.h"
#include "participantes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct participantes {

    char nomeArtista[100];
    char nomePersonagem[100];
    char descricaoPersonagem[200];
    struct participantes* proximo;
};

void cadastro_P(Participantes** pessoa) {
    Participantes* new = (Participantes*)malloc(sizeof(Participantes));
    printf("\n\nDiga o nome do personagem: ");
	scanf(" %[^\n]", new->nomePersonagem);
    printf("\nDiga a Descricao do personagem: ");
    scanf(" %[^\n]", new->descricaoPersonagem);
    printf("\nDiga o nome do Artista: ");
    scanf(" %[^\n]", new->nomeArtista);


    Participantes* atual = *pessoa;
    Participantes* anterior = NULL;

    while (atual != NULL && strcmp(new->nomeArtista, atual->nomeArtista) > 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {
        new->proximo = *pessoa;
        *pessoa = new;
    } else {
        anterior->proximo = new;
        new->proximo = atual;
    }
}

void mostrar(Participantes *pessoas){
	Participantes *aux;
	aux = pessoas;
	while(aux != NULL){
		printf("\n\nNome do personagem: %s", aux->nomePersonagem);
		printf("\nDescricao do personagem: %s", aux->descricaoPersonagem);
		printf("\nNome do artista: %s", aux->nomeArtista);
		aux = aux->proximo;

	}

}

void mostrar_todos_artistas(Participantes *pessoas, char nome[100]){
	Participantes *aux;
	aux = pessoas;

	while(aux != NULL){
		int valida =strcmp(aux->nomePersonagem,nome); 
		if(valida == 0)
			printf("\nNome do artista: %s", aux->nomeArtista);
		aux = aux->proximo;

	}

}

void liberarMem_P(Participantes *pessoas){
    Participantes *aux;
    aux = pessoas;
	Participantes *aux2;
    aux2 = NULL;

	while (aux != NULL) {
		aux2 = aux;
		aux = aux->proximo;
		free(aux2);
		aux2 = NULL;
	}
	free(aux);
}