#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#include "imagem.c"

int main(){
	Imagem *img;

	img = criarImagem(5,5);
    preencherImagem(img);
	

	// 1 - Comente o que acontece com as linhas 15 e 16
	// nas linhas 15 e 16 ocorre o calculo do pixel atual em relação ao centro do circulo.
	//No caso da variavel 15 ocorre a subtração do valor de "dx" por "x" do pixel atual,
	//determinando a diferença horizontal entre a posição do pixel e o centro do circulo
	// E no caso da linha 16 ocorre a mesma coisa mas com os valores "dy" por "y" , determinando
	// assim a diferença vertical entre a posição do pixel e o centro do circulo
	
	// 2 - Comente o que acontece com as linhas 20 e 21
	// Nas linhas 20 e 21 ocorre o mesmo mas me locais diferentes de dx, dy, x e y
	 setPixelValue(img,3,2, 255);
	 imprimirImagem(img);
	 printf("Valor da posicao 3,2 %d\n", getPixelValue(img, 3,2));
	liberarImagem(img);
	return 0;
}