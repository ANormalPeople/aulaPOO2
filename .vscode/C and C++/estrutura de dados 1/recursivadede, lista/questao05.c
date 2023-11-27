#include <stdio.h>
#include <stdlib.h>

float juroscompostos(float VI, int NM, float TJM) {
    if (NM == 0) {
        return VI;
    } else {
        float valor = VI * (1 + TJM);
        return juroscompostos(valor, NM - 1, TJM);
    }
}

int main () {

    int num_mes;
    float valor_inicial,taxa;
    scanf("%f %d %f",&valor_inicial,&num_mes,&taxa);
    taxa = taxa/100;
    printf("%.2f",juroscompostos(valor_inicial,num_mes,taxa));

    return 0;
}