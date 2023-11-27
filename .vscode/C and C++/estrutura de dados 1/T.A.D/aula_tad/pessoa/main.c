#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "pessoa.c"

int main()
{
	int num_pessoas,r;
	printf("Quantas pessoas deseja cadastrar?");
	scanf("%d", &num_pessoas);
	Pessoa *p;
	p = add_pessoa(num_pessoas);
	mostrar_pessoas(p, num_pessoas);
	buscar_altura(p,num_pessoas);
	mostrar_por_altura(p,num_pessoas);
	printf("\n\n deseja remover alguem? 1=s/0=n\n");
	scanf("%d",&r);
	if(r==1){
	 num_pessoas = remover_pessoa(p,num_pessoas);
	}
	mostrar_pessoas(p,num_pessoas);
	return 0;
}