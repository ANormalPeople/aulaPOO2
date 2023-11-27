#include <stdio.h>
#include <stdlib.h>

#include "animal.h"
#include "fazenda.h"
#include "criador.h"

struct criador
{
	int id_criador;
	char nome[100];
	Fazenda *fazendas;//Esse ponteiro e uma lista circular (atentem-se)
	float patrimonio; //esse valor deve ser constantemente modificado para que o valor esteja atualizado	
	struct criador *prox, *ant; //lista dupla encadeada, nao é necessário ser circular
};

Criador *criarListaDuplaCriadores(){
	return NULL;
}

Criador *cadastrar_criador(Criador *criadores) {
	Criador *new = (Criador *) malloc(sizeof(Criador));

	new->id_criador = rand() % 1000000;

	printf("Criador de id: %d\n", new->id_criador);
	printf("Nome: ");
	scanf("%s", new->nome);
	new->fazendas = criarListaEncadeadaCircularFazendas();
	printf("Patrimonio: ");
	scanf("%f", &new->patrimonio);
	new->ant = NULL;
	if(criadores == NULL){
		new->prox = NULL;
	}else{
		criadores->ant = new;
		new->prox = criadores;
	}
	return new;
}

Criador *removerCriador(Criador *criadores, int id) {

	if (buscar(criadores, id) == 1) {
		Criador *aux = criadores;
		Criador *ant = NULL;
		while (aux != NULL && aux->id_criador != id) {
			ant = aux;
			aux = aux->prox;
		
		}
		if(aux == NULL){
			printf("\n PESSOA NÃO ENCONTRADA!!!!");
			return criadores;
		}
		if(aux->fazendas == NULL){		
			if(ant == NULL){
				criadores = aux->prox;
			}else{
				ant->prox = aux->prox;
			}
			free(aux);
			return criadores;
		}
		printf("\n\nO criador em questao pussui fazendas, portanto nao pode ser removido!!");
		return criadores;
	}
	printf("\nCriador inexistente!!!!\n");
	system("Pause");
	return criadores;
}//nao é permitido remover criador com fazendas cadastradas

int buscar(Criador *criadores, int id){
	Criador *aux = criadores;

	while (aux != NULL && aux->id_criador != id){
		aux = aux->prox;	
	}
	if (aux != NULL && aux->id_criador == id){
		return 1;
	}
	return 0;
	}

Criador *acharporID(Criador *criadores, int idcr){
	Criador *aux = criadores;

	while (aux != NULL && aux->id_criador != idcr){
		aux = aux->prox;	
	}
	if (aux != NULL && aux->id_criador == idcr){
		return aux;
	}
	return NULL;
	}


float calcPatrimonio(Criador *criadores, int id){
	Criador *aux = criadores;
	
	if (aux == NULL){
		printf("Erro! Lista de Criadores vazia!");
		return 0;
	}else{
		while (aux->id_criador != id && aux != NULL){
			aux = aux->prox;			
		}
		if(aux->prox == NULL){
			printf("Criador não encontado!");
			return 0;  
		}else{
			printf("Patrimonio total do Cirador: %s\n", aux->nome);
			printf("R$ %2.f\n", aux->patrimonio);
			return aux->patrimonio;
		}
	}
}
void printCriadores(Criador *criadores){
	Criador *aux = criadores;
	printf("\n \t Lista de Criadores: \n");
	while (aux != NULL){
		printf("\n  ID: %d \n", aux->id_criador);
		printf("  Nome: %s \n", aux->nome);
		printf("  Patrimonio: %.2f \n", aux->patrimonio);
		aux = aux->prox;
	}
	printf("\n\n");	
}

void liberarMemCriador(Criador *criadores) {
	if (criadores != NULL) {
		Criador *aux = criadores;
		while (aux->prox != NULL){
			aux = aux->prox;
		    liberarMem(aux->ant->fazendas->rebanho);
    		liberarMemoriaF(aux->ant->fazendas);
			free(aux->ant);
		}
		liberarMem(aux->fazendas->rebanho);
    	liberarMemoriaF(aux->fazendas);
		free(aux);
	}else{
		printf("Erro, nao foi possivel liberar memoria!");
	}
}

int validacao(Criador * criadores){
	if(criadores != NULL){
		printf("\nLISTA DE CRIADORES CADASTRADOS: \n");
		printCriadores(criadores);
	}else{
		printf("\nE preciso um criador registrado para que se possa acessar esta area!!!\n");
		return 0;
	}
	return 1;
}