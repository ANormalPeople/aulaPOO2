#include <stdio.h>

void ler(float *nota1, float *nota2);

int main () {
    float nota1,nota2,mediasimples,mediaponderada;
    ler(&nota1,&nota2);
    mediasimples = (nota1 + nota2) / 2;
    mediaponderada = (nota1 + nota2 * 2) / 3;
    printf("primeira nota: %.2f\nsegunda nota: %.2f\n",nota1,nota2);
    printf("media simples: %.2f\n media ponderada: %.2f",mediasimples,mediaponderada);
    return 0;
}


void ler(float *nota1, float *nota2){
    do
    {
        scanf("%f", nota1);
    } while (*nota1<0 || *nota1 > 10);

        do
    {
        scanf("%f", nota2);
    } while (*nota2<0 || *nota2 > 10);
    
}

