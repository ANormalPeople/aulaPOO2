#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Movi=0, Compi=0;

typedef struct Aluno{
    int chave;
    char nome[30];
    char endereco[50];
    char telefone[14];

} Aluno;

void gerarDados(Aluno v[ ], int n, int ordemChave);//tamanho do vetor o int n.
void bolha(Aluno v[],int n);
void insercao(Aluno v[],int n);
void selecao(Aluno v[],int n);


int main () {
    Aluno vetor[1000];
    int n, alg, ord;  
    
    scanf("%d",&n);




    while(1){
        

        scanf("%d",&ord);
        if(ord==3){
          break;
        }
        scanf("%d",&alg);
    
        gerarDados(vetor,n,ord);
        


    switch (alg){
        case 0:
            printf("bolha\n");
            for(int f=0;f<n;f++){
              printf("%d ",vetor[f].chave);
            }
            printf("\n");        
            bolha(vetor,n);
            for(int f=0;f<n;f++){
              printf("%d ",vetor[f].chave);
            }
            printf("\n");
            printf("Movimentacao:%d\nComparacao:%d\n",Movi,Compi);      
            break;
    
        case 1:
            printf("selecao\n");
            for(int f=0;f<n;f++){
              printf("%d ",vetor[f].chave);
            }
            printf("\n");    
            selecao(vetor,n);
            for(int f=0;f<n;f++){
              printf("%d ",vetor[f].chave);
            }
            printf("\n");    
            printf("Movimentacao:%d\nComparacao:%d\n",Movi,Compi);                
            break;
    
        case 2:
            printf("insercao\n");
            for(int f=0;f<n;f++){
              printf("%d ",vetor[f].chave);
            }
            printf("\n");    
            insercao(vetor,n);
            for(int f=0;f<n;f++){
              printf("%d ",vetor[f].chave);
            }
            printf("\n");
            printf("Movimentacao:%d\nComparacao:%d\n",Movi,Compi);                
            break;
        default:
            break;
        }

    }



    system ("PAUSE");
    return 0;
}

void gerarDados(Aluno v[], int n, int ordemChave){
    int i, c;

    if(ordemChave == 0){
        for(i = 0, c = 0; c < n; c ++,i ++){
            v[i].chave = c;
        }
        
    }
    else if (ordemChave == 1){
        srand(time(NULL));
        for (c = 0; c < n; c ++){
            v[c].chave = rand()%10000;
        }
    }
    else if (ordemChave == 2){
        for (i = 0, c = n-1; c >= 0; c --, i ++){
            v[i].chave = c;
            
        }
    }

}  

void bolha(Aluno v[],int n){
    int i, j, aux;
    Movi=0,Compi=0;
    for( i = 0; i < n - 1;i++){
        for(j=1;j<n-i;j++){
            Compi++;
            if(v[j].chave < v[j-1].chave){
                Movi+=3;
                aux = v[j-1].chave;
                v[j-1].chave=v[j].chave;
                v[j].chave=aux;
            }
        }
    } 

}

void selecao(Aluno v[],int n){
    Movi=0,Compi=0;
    int i, j, min, aux=0;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            Compi++;
            if(v[j].chave<v[min].chave)
            min =j;

        }
            Movi+=3;
            aux = v[i].chave;
            v[i].chave=v[min].chave;
            v[min].chave=aux;    
    }

}

void insercao(Aluno v[],int n){
    Movi=0,Compi=0;    
    int i, j;
    struct Aluno aux;
    for(i=1;i<n;i++){
        Movi++;
        aux = v[i];
        j = i - 1;
        Compi++;
        while((j>=0)&&(aux.chave < v[j].chave)){
            Movi++;
            v[j + 1] = v[j];
            j--;
        }
     v[j+1] = aux;
    }
}