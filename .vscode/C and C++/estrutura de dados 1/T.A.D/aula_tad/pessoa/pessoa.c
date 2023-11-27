#include "pessoa.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct pessoa {
    char nome[100];
    int idade;
    int altura;
};

Pessoa *add_pessoa(int t) {
    Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa) * t);
    for (int i = 0; i < t; ++i){
	    printf("Nome: ");
	    scanf("%s", p[i].nome);
	    printf("Idade: ");
	    scanf("%d", &(p[i].idade));
	    printf("Altura: ");
	    scanf("%d", &(p[i].altura));
	}
    return p;
}


void mostrar_pessoas(Pessoa *p, int t){
	printf("\n\n\n\n");
	for (int i = 0; i < t; ++i)
	{
		printf("Nome: %s\n", p[i].nome);
		printf("Idade: %d\n", p[i].idade);
		printf("Altura: %d\n", p[i].altura);
	}
}

void buscar_altura(Pessoa *p, int t){
	int busca;
	int x=0;
	printf("diga o valor base da altura para a busca\n");
	scanf("%d",&busca);

	for(int i = 0; i < t; i++){
		if (p[i].altura == busca){
			printf("Nome: %s\n", p[i].nome);
			printf("Idade: %d\n", p[i].idade);
			printf("Altura: %d\n", p[i].altura);			
			x++;
		}
	}
	if(x==0){
		printf("não existem pessoas com esta altura");
	}
}

void mostrar_por_altura(Pessoa *p, int t){
	int busca;
	int x=0;
	char nome[100];
	printf("diga o valor base da altura para a busca\n");
	scanf("%d",&busca);
	printf("diga o nome:\n");
	scanf("%s",nome);
	for(int i = 0; i < t; i++){
		if (p[i].altura == busca && strcmp(p[i].nome,nome)==0){
			printf("Nome: %s\n", p[i].nome);
			printf("Idade: %d\n", p[i].idade);
			printf("Altura: %d\n", p[i].altura);			
			x++;
			break;
		}
	}
	if(x==0){
		printf("não existem pessoas com esta altura");
	}
}

int remover_pessoa(Pessoa *p, int t){
	int idade,buff1;
	char nome[100],buff2[100];
	int altura,buff3;
	printf("diga as credenciais da pessoa que voce deseja remover\n\n");
	printf("Nome: ");
	scanf("%s",nome);
	printf("Idade: ");
	scanf("%d", &idade);
	printf("Altura: ");
	scanf("%d", &altura);

	for(int i = 0; i < t; i++){
		if(idade == p[i].idade && strcmp(nome,p[i].nome)==0 && altura == p[i].altura){

			buff1 = p[t-1].altura;
			p[t-1].altura = p[i].altura;
			p[i].altura = buff1;
			
			strcpy(buff2,p[t-1].nome);
			strcpy(p[t-1].nome,p[i].nome);
			strcpy(p[i].nome,buff2);
            
			buff3 = p[t-1].idade;
			p[t-1].idade = p[i].idade;
			p[i].idade = buff3;
			break;
		}
	}

		p = (Pessoa*) realloc(p,sizeof(Pessoa)*(t-1));
		return (t-1);
}