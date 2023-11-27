//dont is mine//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarTabela( int num_com, int num_mov,char *tipo){

    printf("%8s | %6d | %5d\n",tipo,num_com,num_mov);
 
}

void gerarDados(int v[], int n, int ordemChave){
	int i, c;

    if(ordemChave == 0){
        for(i = 0, c = 0; c < n; c ++,i ++){
            v[i] = c;
        }
    }
    else if (ordemChave == 1){
        srand(time(NULL));
        for (c = 0; c < n; c ++){
            v[c] = (rand()%10000);
        }
    }
    else if (ordemChave == 2){
        for (i = 0, c = n-1; c >= 0; c --, i ++){
            v[i] = c;
        }
    }
}   


void metodos(int v[], int n,int *num_comp, int *num_mov,int ordem){
    int c;
    char tipo[15];
    if(ordem == 0){
        printf("melhor caso: %d\n----------------------------\n",n);
    }else if(ordem == 1){
        printf("medio caso:  %d\n-----------------------------\n",n);
    }else{
        printf("pior caso:  %d\n------------------------------\n",n);
    }
        printf("%8s |%6s|%5s\n----------------------------\n","metodo","num comp","num mov");

    // bolha
    int i, j, aux;
    for ( i = 0; i < n -1 ; i++){
        for ( j = 1; j < n - i; j ++ ){
            ++ *num_comp;
            if (v[j] < v[j-1]){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
                *num_mov += 3;
            }
        }
    }
    gerarTabela(*num_comp,*num_mov,"bolha");
    // seleção
    *num_comp = 0;
    *num_mov = 0;
    int min;
    for (i = 0 ; i < n ; i ++){
        min = i;
        for(j = i+1 ; j < n ; j ++){
            *num_comp = *num_comp + 1;
            if(v[j] < v[min]){
                min = j;
            }
        }
        aux = v[min];
        v[min] = v[i];
        v[i] = aux;    
        *num_mov += 3;
    }
    gerarTabela(*num_comp,*num_mov,"selecao");
    // inserção
    *num_comp = 0;
    *num_mov = 0;
    for (i = 1; i < n; i ++){
        ++ *num_mov;
        aux = v[i];
        j = i - 1;
        ++ *num_comp;
        while ((j >= 0) && (aux < v[j]))
        {
            ++ *num_comp;
            v[j+1] = v[j];
            ++ *num_mov;
            j --;
        }
        ++ *num_mov;
        v[j+1] = aux;
    }
    gerarTabela(*num_comp,*num_mov,"insercao");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}



int main(){

    int vetor[10000];
    int NUM_COMP = 0, NUM_MOV = 0;

    gerarDados(vetor,0,2);
    metodos(vetor,0,&NUM_COMP,&NUM_MOV,2);

    NUM_COMP = 0;
    NUM_MOV = 0;

    gerarDados(vetor,100,2);
    metodos(vetor,100,&NUM_COMP,&NUM_MOV,2);

    NUM_COMP = 0;
    NUM_MOV = 0;

    gerarDados(vetor,200,2);
    metodos(vetor,200,&NUM_COMP,&NUM_MOV,2);

    NUM_COMP = 0;
    NUM_MOV = 0;

    gerarDados(vetor,300,2);
    metodos(vetor,300,&NUM_COMP,&NUM_MOV,2);
    NUM_COMP = 0;
    NUM_MOV = 0;

    gerarDados(vetor,400,2);
    metodos(vetor,400,&NUM_COMP,&NUM_MOV,2);
    NUM_COMP = 0;
    NUM_MOV = 0;
    gerarDados(vetor,500,2);
    metodos(vetor,500,&NUM_COMP,&NUM_MOV,2);
    NUM_COMP = 0;
    NUM_MOV = 0;

    gerarDados(vetor,600,2);
    metodos(vetor,600,&NUM_COMP,&NUM_MOV,2);
    NUM_COMP = 0;
    NUM_MOV = 0;

    gerarDados(vetor,700,2);
    metodos(vetor,700,&NUM_COMP,&NUM_MOV,2);
    NUM_COMP = 0;
    NUM_MOV = 0;

    gerarDados(vetor,800,2);
    metodos(vetor,800,&NUM_COMP,&NUM_MOV,2);
    NUM_COMP = 0;
    NUM_MOV = 0;

    gerarDados(vetor,900,2);
    metodos(vetor,900,&NUM_COMP,&NUM_MOV,2);
    NUM_COMP = 0;
    NUM_MOV = 0;

    gerarDados(vetor,1000,2);
    metodos(vetor,1000,&NUM_COMP,&NUM_MOV,2);


  return 0;
}