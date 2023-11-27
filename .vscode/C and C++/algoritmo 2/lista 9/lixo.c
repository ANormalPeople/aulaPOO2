#include <stdio.h>

void ordena (int *vect, int length) {
    int i, j, smallest_index, aux;

    for (i = 1; i < length; i++) {
        aux = vect[i];

        for (j = i - 1; j >= 0 && vect[j] > aux; j--) {
            vect[j + 1] = vect[j];
        }

        vect[j + 1] = aux;
    }
}

int busca_binaria (int *arr, int baixo, int cima, int alvo) {
    int meio = (cima + baixo) / 2;

    if (baixo > cima) {
        return -1;
    }

    if (alvo == arr[meio]) {
        return meio;
    } else if (alvo > arr[meio]) {
        return busca_binaria (arr, meio + 1, cima, alvo);
    } else if (alvo < arr[meio]) {
        return busca_binaria (arr, baixo, meio - 1, alvo);
    }
}

int main (void) {
    int caixas_total, i, j, add_in, lim_b, lim_c;
    int len = 10, num_procurado, baixo, cima, encontrou;

    while ((scanf ("%d", &caixas_total)) != EOF) {
        int parafusos[10000];
        add_in = 0;

        for (i = 0; i < caixas_total; i++) {
            scanf ("%d%d", &lim_b, &lim_c);

            for (j = lim_b; j <= lim_c; j++) {
                parafusos[add_in++] = j;
            }
        }
        scanf("%d", &num_procurado);

        ordena (parafusos, add_in);

        encontrou = busca_binaria (parafusos, 0, add_in - 1, num_procurado);

        if (encontrou == -1) {
            printf("%d not found\n", num_procurado);
            continue;
        }

        baixo = encontrou;
        cima = encontrou;

        for (i = 1; parafusos[encontrou - i] == parafusos[encontrou] && encontrou - i >= 0; i++) {
            baixo--;
        }

        for (i = 1; parafusos[encontrou + i] == parafusos[encontrou] && encontrou - i >= 0; i++) {
            cima++;
        }

        printf("%d found from %d to %d\n", num_procurado, baixo, cima);
    }

    return 0;
}


void insercao(int c) {
    int i, j,aux;
    
    for(i=1;i<c;i++){
        aux = vetor[i];
        j = i - 1;
        while((j>=0)&&(vetor[j] > vetor)){
            vetor[j + 1] = vetor[j];
            j--;
        }
     vetor[j+1] = aux;
    }
}