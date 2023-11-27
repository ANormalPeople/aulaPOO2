#include <stdio.h>
#include <stdio.h>
#include <math.h>

int main () {
    int *matriz,raio=25;
    
    matriz = calloc(100 * 100,sizeof(int));
    //criando a matriz 100x100 preenchida com 0;
    for(int l=25; l < 75;l++){ 
        for(int j=25;j < 75;j++){
            matriz[l * 100 + j] = 1;
        }
    }//escrevendo o retangulo com 50% da matriz 100x100

    int centro_x = 25;
    int centro_y = 25;

    for(int i=25;i<75;i++){
        for(int j=25;j<75;j++){
            int distancia = sqrt(pow(i - centro_x, 2) + pow(j - centro_y, 2));
            if (distancia <= 25) {
            //escrvendo um circulo dentro do retangulo que esta dentro
                matriz[i * 100 + j] = 2;
            }
        }
    }
    free(matriz);
    return 0;
}