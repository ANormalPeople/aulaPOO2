#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "fazenda.h"
#include "animal.h"

struct endereco{
	char cidade[50], estado[2], logradouro[200];
};

struct fazenda{
	int id_criador, id_fazenda;
	char nome[100];
	Endereco localizacao;
	float valor_fazenda;//lembrar de atualizar o valor sempre que houver alterações no rebanho
	Animal *rebanho; // ponteiro para uma lista (verificar no .h do animal que lista é)
	//ponteiro para permitir o apontamento para o proximo elemento da lista (deve ser circular)
	struct fazenda *prox;
};

Fazenda *criarListaEncadeadaCircularFazendas(){
	return NULL;
}

Fazenda *cadastrarFazenda(Fazenda *fazendas){
	Fazenda *new = (Fazenda *) malloc(sizeof(Fazenda));
	Fazenda *aux;
	new->id_fazenda = rand() % 1000;
	new->rebanho = criaListaEncadeadaSimplesAnimais();
	printf("\nNome: ");
	scanf("%s", new->nome);
	printf("localizacao da cidade: ");
	scanf("%s", new->localizacao.cidade);
	printf("localizacao do estado: ");
	scanf("%s", new->localizacao.estado);
	printf("localizacao do logradouro: ");
	scanf("%s", new->localizacao.logradouro);
	new->valor_fazenda = 0;
	if(fazendas == NULL){
		new->prox = new;
		return new;
	}else{
		aux = fazendas;
		while(aux->prox != fazendas){
			aux = aux->prox;
		}
		aux->prox = new;
		new->prox = fazendas;
	}
	return new;
}

Fazenda *removerFazenda(Fazenda *fazendas, int id){
	
	if(fazendas == NULL){
		printf("\n Sem fazendas cadastradas!!");
		return NULL;
	}	

	Fazenda *atual = fazendas;
	Fazenda *ant = NULL; 

		do{
			if(atual->id_fazenda == id && atual->rebanho == NULL){
				if (ant == NULL) {
					Fazenda *ultima =  fazendas->prox;
					while (ultima->prox != fazendas) {
						ultima = ultima->prox;
					}
					if(ultima == fazendas){
						free(fazendas);
						return NULL;
					}
					fazendas = atual->prox; 
					ultima->prox = fazendas;
				}else{
					ant->prox = atual->prox;
				}
				free(atual);
				return fazendas;
			}else{
				printf("A fazenda possui rebanhos!!!!");
				return fazendas;
			}
			ant = atual;
			atual = atual->prox;
		}while (atual != fazendas);
		printf("\nFazenda não encontrada!!!");
		return fazendas;
	
	printf("\n Sem dados!!!!");
	return fazendas;
	
}//nao permitir remover fazenda se houver animais cadastrados

int buscarFazenda(Fazenda *fazendas, int id) {
	
	if (fazendas != NULL) {
		Fazenda *aux = fazendas;

		do{
			if (aux->id_fazenda == id) {
				return 1;
			}
			aux = aux->prox;
		}while(aux != fazendas);
		printf("fazenda nao encontrada!!!");
		return 0;
	}
	printf("fazenda vazia!!!");
	return 0;
	
}

Fazenda *buscarFazendaID(Fazenda *fazendas, int id) {
	
	if (fazendas != NULL) {
		Fazenda *aux = fazendas;

		do{
			if (aux->id_fazenda == id) {
				return aux;
			}
			aux = aux->prox;
		}while(aux != fazendas);
		printf("\nfazenda nao encontrada!!!\n");
		return NULL;
	}
	printf("\nfazenda vazia!!!\n");
	return NULL;
	
}

void listafazendas(Fazenda *f){
	Fazenda *aux = f;
		do{
			printf("\n\nNome: %s ",aux->nome);
			printf("\nID: %d ",aux->id_fazenda);
			printf("\nValor: %.2f ",aux->valor_fazenda);
			printf("\ncidade: %s ",aux->localizacao.cidade);
			printf("\nestado: %s ",aux->localizacao.estado);
			printf("\nlogradouro: %s ",aux->localizacao.logradouro);
			quantTotalSexo(aux);
			aux = aux->prox;
		}while(aux != f);
}

void totalArroba(Fazenda *fazendas) {
	fazendas->valor_fazenda = 235 * calcArroba(fazendas->rebanho);
}

void quantTotalSexo(Fazenda* fazendas) {
    int M = 0, F = 0;
    Animal* aux = fazendas->rebanho;
    while (aux != NULL) {
        if (aux->sexo[0] == 'M') {
            M++;
        }
        if (aux->sexo[0] == 'F') {
            F++;
        }
        aux = aux->prox;
    }
    printf("\nTotal de animais do sexo M: %d\n", M);
    printf("Total de animais do sexo F: %d\n", F);
}


void lista_animais_status(Fazenda* rebanho) {
    if (rebanho != NULL) {
        int op;
        printf("\nDiga de qual status deseja obter informacoes: ");
        scanf("%d", &op);

        Fazenda* aux_fazenda = rebanho;
        do {
            Animal* aux_animal = aux_fazenda->rebanho;
            while (aux_animal != NULL) {
                switch (op) {
                    case 1:
                        if (aux_animal->status == 1) {
                            mostrar(aux_animal);
                        }
                        break;
                    case 2:
                        if (aux_animal->status == 2) {
                            mostrar(aux_animal);
                        }
                        break;
                    case 3:
                        if (aux_animal->status == 3) {
                            mostrar(aux_animal);
                        }
                        break;
                    case 4:
                        if (aux_animal->status == 4) {
                            mostrar(aux_animal);
                        }
                        break;
                    default:
                        printf("\nEscolha uma opcao valida!!!!\n");
                        return;
                }
                aux_animal = aux_animal->prox;
            }
            aux_fazenda = aux_fazenda->prox;
        } while (aux_fazenda != rebanho);
    }
}

void liberarMemoriaF(Fazenda *fazendas) {
	if (fazendas != NULL) {
		Fazenda *aux = fazendas;
		Fazenda *aux2 = NULL;

		while (aux->prox != fazendas) {
			aux2 = aux;
			aux = aux->prox;
			free(aux2);
			aux2 = NULL;	
		}
		free(aux);
		aux = NULL;
	}
}