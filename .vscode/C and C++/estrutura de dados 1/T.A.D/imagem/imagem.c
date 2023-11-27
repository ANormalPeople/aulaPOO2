#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#include "math.h"

struct pixel{
	int valor, x, y;
};

struct imagem{
	Pixel *pixels;
	int largura, altura;
};
Imagem *criarImagem(int largura, int altura){ 
	Imagem *img = (Imagem *) malloc(sizeof(Imagem));
	img->pixels = (Pixel*) calloc((largura*altura),sizeof(Pixel));
	img->altura = altura;
	img->largura = largura;
	return img;
}

 void preencherImagem(Imagem *img){
	    int raio = (int)fmin(img->largura, img->altura) / 2;
    int centro_x = img->largura / 2;
    int centro_y = img->altura / 2;

    for (int y = 0; y < img->altura; y++) {
        for (int x = 0; x < img->largura; x++) {
            int dx = x - centro_x;
            int dy = y - centro_y;
            double distancia = sqrt(dx * dx + dy * dy);

            if (distancia <= raio) {
                int indice = y * img->largura + x;
                img->pixels[indice].x = x;
                img->pixels[indice].y = y;
                img->pixels[indice].valor = 1;
            }
        }
    }
 }

 void imprimirImagem(Imagem *img){
	for(int i=0; i<img->altura;i++){
		for(int j=0; j<img->largura;j++){
			printf("%d ", img->pixels[i * img->largura + j].valor);
		}
		printf("\n");
	}
 }

void liberarImagem(Imagem *img){
	free(img->pixels);
	free(img);
}

void setPixelValue(Imagem *img, int y, int x, int valor){
    if (x >= 0 && x < img->largura && y >= 0 && y < img->altura) {
        int indice = y * img->largura + x;
        img->pixels[indice].x = x;
        img->pixels[indice].y = y;
        img->pixels[indice].valor = valor;
    }	
  }

 int getPixelValue(Imagem *img, int y, int x){
	return img->pixels[y * img->largura + x].valor;
 }