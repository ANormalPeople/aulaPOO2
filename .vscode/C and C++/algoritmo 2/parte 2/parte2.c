#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

int passos=0,passos2=0;

typedef struct{
    int codigo;
    char nome[20];
}registro;

typedef struct{
    registro itens[MAX+2];
    int tamanho;
}tabela;

tabela tab;

void inserireprintar();
void analise_desempenho_bi_e_se();
void insercao();
void pesquisaSequencial( int chave);
void pesquisabinaria(int chave);
void quantidaderepeticao();
void removerepeticao();
void pesquisanome();
void insere();


int main () {
    
    inserireprintar();

    analise_desempenho_bi_e_se();

    quantidaderepeticao();   

    removerepeticao();
    
    pesquisanome();

    insere();

                                  //COMENTARIO EM RELAÇÃO A COMPARAÇÃO.
    //O valor esperado para o caso medio da sequencial era 500 e para a binaria era 9, com o valor sequencial sendo
    //maior a maioria das vezes, a vezes batendo em 500 mas geralmente é mais talvez seja porque meu codigo ta errado mas tambem
    //talvez seja pela aleatorieddade existente e o valor da pesquisa binaria sendo sempre quase exatamente nove,
    ///com raramente acrescentando ou diminuindo 1.

    return 0;
}

void inserireprintar(){
    int i;

    srand(time(NULL));
    for(i = 1;i <= (MAX+1); i++){
        sprintf(tab.itens[i].nome, "Gol");
        tab.itens[i].codigo = rand() % 1001;
        tab.tamanho++;
    }
   
   insercao(); 

    for (i = 1; i < tab.tamanho; i++) {
        printf("%s: %d\n", tab.itens[i].nome, tab.itens[i].codigo);
    }
}

void analise_desempenho_bi_e_se() {
    int c, x;

    srand(time(NULL));
    for (c = 0; c < 100; c++) {
        x = rand() % 1001;    
        tab.itens[0].codigo = x;
        pesquisaSequencial(x);
    }

    for (c = 0; c < 100; c++) {
        x = rand() % 1001;    
        pesquisabinaria(x);
    }
    printf("\nPesquisa sequencial: a media de registros percorridos por pesquisa e %2.f\n", (float)passos/100);
    printf("Pesquisa binaria: a media de registros percorridos por pesquisa e %2.f\n\n",(float)passos2/100);
}

void pesquisaSequencial(int chave){
    int i;
    for (i = tab.tamanho;tab.itens[i].codigo != chave; i--,passos++){
    }
    
}

void pesquisabinaria(int chave) {
    int i, esq, dir;

        esq = 1;
        dir = tab.tamanho;
    do {
        i = (esq + dir) / 2;
        passos2++;
    if (chave > tab.itens[i].codigo) {
        esq = i + 1;
    } else {
        dir = i - 1;
    }

    } while((chave != tab.itens[i].codigo) && (esq <= dir));
        if (chave == tab.itens[i].codigo) {
           
        }
        else {
           
        } 
    }

void insercao() {
    int i, j;
    registro aux;
    for(i=1;i<tab.tamanho;i++){
        aux = tab.itens[i];
        j = i - 1;
        while((j>=0)&&(tab.itens[j].codigo > aux.codigo)){
            tab.itens[j + 1] = tab.itens[j];
            j--;
        }
     tab.itens[j+1] = aux;
    }
}

void quantidaderepeticao(){
    int i,N,Cont=0;

    printf("Escreva um numero de 0 a 1000 para saber a quantiade de repeticoes\n");
    scanf("%d",&N);
 
    for (i = 1; i < tab.tamanho; i++) {
        if(N==tab.itens[i].codigo){
            Cont++;
        }
    }
    printf("O codigo %d se repete %d vezes.\n",N,Cont);

}

void removerepeticao(){
    int i,N,cont=0; 

    printf("Escreva um numero de 0 a 1000 para ser removido\n");
    scanf("%d",&N);
 
    for (i = 1; i <tab.tamanho; i++) {
        if(N==tab.itens[i].codigo){
           cont++;
           tab.itens[i] = tab.itens[tab.tamanho];
           tab.tamanho -= 1;
        }
               
    }

    printf("\n %d registros com o codigo %d foram removidos\n\n",cont,N);
    quantidaderepeticao();

}

void pesquisanome(){    
   int i;
   char nome[20];
   
   printf("Diga o nome que deseja buscar\n");
   scanf("%s",nome);

    for (i = 1; i < tab.tamanho; i++) {
        if(strcmp(nome,tab.itens[i].nome)==0){
            printf("Registro encontrado, no numero %d",i);
            break;       
        }else{
            printf("Nome nao encontrado.");
            break;
        }
    }

}

void insere(){
   int i,Num,x;
   char nome[20];
   
   printf("\nDiga o codigo e o nome que deseja acrescentar\n");
   scanf("%d%s",&Num,nome);

    if(tab.tamanho == MAX){
        printf("Erro: tabela cheia\n");
    } else {

    for (i = 1; i < tab.tamanho; i++) {
        if(strcmp(nome,tab.itens[i].nome)==0){
            printf("Existem registros desse veiculo. Digite 0 para cancelar e 1 para confirmar a insercao:\n");
            scanf("%d",&x);
            if(x==0){
                printf("cancelado");                
                break;
            }else{
                tab.itens[i+1].codigo = Num;
                strcpy(tab.itens[i].nome,nome);
                tab.tamanho++;         
                break;
            }                       
        }else{
            printf("Nao existem registros desse veiculo. Digite 0 para cancelar e 1 para confirmar a insercao\n");
            scanf("%d",&x);
            if(x==0){
                printf("cancelado");                
                break;          
            }else{
                tab.itens[i+1].codigo = Num;
                strcpy(tab.itens[i].nome,nome);
                tab.tamanho++;
                break;
            }
        }
    }

    }

}