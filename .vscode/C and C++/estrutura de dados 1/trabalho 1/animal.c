#include "fazenda.h"
#include "animal.h"
#include "criador.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct animal{
	int id_animal, id_fazenda;
	char sexo[1]; // M ou F
	float peso; //em KG
	int status; // 1 - Nascimento na propria fazenda | 2 - venda | 3 - troca | 4 - Permuta
	struct animal *prox;
};

Animal *criaListaEncadeadaSimplesAnimais(){
	return NULL;
}

Animal *cadastro(Animal *rebanho){
	
	Animal *new = (Animal*) malloc(sizeof(Animal));
	new->id_animal = rand() % 100 + 10;
	printf("\nSexo(M/F) - ");
	scanf("%s", new->sexo);
	printf("\nPeso - ");
	scanf("%f",&new->peso);
	printf("\nStatus(1 - Nascimento na propria fazenda | 2 - venda | 3 - troca | 4 - Permuta) - ");
	scanf("%d", &new->status);
	new->prox = rebanho;
	return new;
}

Animal *permutasAnimais(Animal *origem, Animal **destino, int id_animal) {
	Animal *atual = origem;
	Animal *ant = NULL;

	while (atual != NULL && atual->id_animal != id_animal) {
		ant = atual;
		atual = atual->prox;
	}
	
	if (atual == NULL) {
		printf("\nAnimal não encontrado\n");
		return origem;
	}

	if (ant == NULL) {
		origem = atual->prox; // O animal é o primeiro da lista
	} else {
		ant->prox = atual->prox; // O animal está no meio da lista
	}

	atual->id_fazenda = (*destino)->id_fazenda;
	atual->prox = *destino;
	*destino = atual;
	atual->status = 4;

    free(atual);

    return origem;
}

float calcArroba(Animal *rebanho) {
	float arroba = 0;
	if (rebanho != NULL) {
		Animal *aux = rebanho;

		while (aux != NULL) {
			arroba += (aux->peso / 15);

			aux = aux->prox;
		} 
	}
	return arroba;
}

int buscarAnimal(Animal *rebanho, int id_animal) {
	if (rebanho != NULL) {
		Animal *aux = rebanho;

		while (aux != NULL) {
			if (id_animal == aux->id_animal) {
				return 1;
			}
			aux = aux->prox;
		}
		return 0;
	}
	else {
		return 0;
	}
}

Animal *removerA(Animal *a, int id) {
	Animal *atual = a;
	Animal *ant = NULL;

	while(atual != NULL && atual->id_animal != id) {
		ant = atual;
		atual = atual->prox;
	}
    if(atual == NULL){
        printf("\n\nrebanho nao encontrado");
        return a;
    }

    if(ant == NULL){
        a = atual->prox;
    }else{
        ant->prox = atual->prox;
    }
    free(atual);
	return a;	
}

void mostrar(Animal *aux){
	printf("\nSexo: %s",aux->sexo);
	printf("\nID: %d",aux->id_animal);
	printf("\nPeso: %f",aux->peso);
	printf("\nStatus: %d\n\n",aux->status);
}

void listaanimal(Animal *r){
	Animal *aux = r;

	while(aux != NULL){
		mostrar(aux);
		aux = aux->prox;
	}
}

void liberarMem(Animal *rebanho){
    Animal *aux = rebanho;
	Animal *aux2 = NULL;

	while (aux != NULL) {
		aux2 = aux;
		aux = aux->prox;
		free(aux2);
		aux2 = NULL;
	}
	free(aux);
}