#include <stdlib.h> 
#include <stdio.h> 
#include "matriz.h"

struct matriz { 
	int lin; 
	int col;
	float *v; 
};

Matriz *cria(int m, int n){
	Matriz *ma = (Matriz*) malloc(sizeof(Matriz));
	ma->v = (float*) malloc((m*n) * sizeof(float));
	ma->lin = m;
	ma->col = n;
	return ma;
}

void atribui (Matriz* mat, int i, int j, float v){
	if( i >= 0 && i < mat->lin && j >= 0 && j < mat->col){
		int indice = i * mat->col + j;
		mat->v[indice] = v;
	}
}

void libera (Matriz *mat){
	free(mat);
}

float acessa (Matriz* mat, int i, int j){
	return mat->v[i * mat->col + j];
}

int linhas (Matriz *mat){
	return mat->lin;
}

int colunas (Matriz* mat){
	return mat->col;
}

//k = i * m ->i + j