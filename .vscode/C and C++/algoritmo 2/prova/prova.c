#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int contagem;
    int cod;
    char descricao[30];
    int quantidade;
}registro;

registro reg = {0,0, "", 0};

void formatacao();
void cadastrar(int i);
void vizualizar();
void busca();
void insercao();
void remover_registro();


int main () {
   int resp,i=0;
   FILE *arq;

    if ((arq = fopen("dadosalunomy.bin", "rb+")) == NULL){
        formatacao();
    }else{
        fread(&reg, sizeof(registro), 1, arq);
    }

   printf("1-cadastrar\n2-visualizar\n3-remover\n4-buscar\n5-finalizar\n");

    while(resp!=5){
        printf("\n");
        printf("Informe o modulo desejado:\n");
        scanf("%d",&resp);
        if(resp==1){
            i++;
            cadastrar(i);
        }else if(resp==2){
            vizualizar();        
        }else if(resp==3){
            remover_registro();
        }else if(resp==4){
            busca();          
        }
    }

    return 0;
}

void formatacao(){
    int i;

    FILE *arq;
    if ( ( arq = fopen( "dadosalunomy.bin", "wb" ) ) == NULL ) {
        printf( "Arquivo nao porde ser aberto\n" );
    }
    else {
        for ( i = 1; i <= 1000; i++ ) {
            fwrite( &reg, sizeof(registro), 1, arq );
        }
        fclose ( arq );
    }

}

void cadastrar(int i){
    int aux;
    registro dados;
    FILE *arq;
    
    if ((arq = fopen("dadosalunomy.bin", "rb+")) == NULL) {
        printf("Arquivo nao pode ser aberto\n");
        return;
    }

    printf("DIGA O CODIGO, QUANTIDADE E A DESCRICAO\n");
    scanf("%d%d %[^\n]", &aux, &reg.quantidade, reg.descricao);
        fseek(arq, 0, SEEK_SET); 

        while (fread(&dados, sizeof(dados), 1, arq)) { 
            if (aux == dados.cod) { 
                printf("\n\tCodigo ja foi cadastrado!\n");
                system("pause");
                fclose(arq);
                return; 
            }
        }

    reg.cod = aux; 
    fseek(arq, (i - 1) * sizeof(registro), SEEK_SET);
    fwrite(&reg, sizeof(registro), 1, arq);
    fclose(arq); 
    printf("\n\tOperacao de escrita finalizada\n");
    system("PAUSE");
}   

void vizualizar(){
    insercao();     
    registro dados;
    FILE *arq;
    int i = 0;
    if((arq = fopen("dadosalunomy.bin","rb+")) == NULL){
        printf("\n\tArquivo nao pode ser aberto.");
    }

    while(!feof(arq)){

        fseek(arq, ((i) * sizeof(dados)), SEEK_SET);
        if(fread(&dados, sizeof(dados),1,arq)){
            if (dados.cod != 0){

                printf("\n\t%i,%s,%d",dados.cod,dados.descricao,dados.quantidade);
                printf("\n");
            }
        i++;
        }
    }
    fclose(arq);
    printf("\n\tOperacao de leitura finalizada\n");
    system("PAUSE");
}

void busca(){
   registro dados;
    FILE *arq;
    int aux;
    if((arq = fopen("dadosalunomy.bin","rb+")) == NULL){
        printf("\n\tArquivo nao pode ser aberto.");
    }

    printf("diga a quantidade alvo:\n");
    scanf("%d",&aux);

    while (fread(&dados, sizeof(dados), 1, arq)) {
        if (aux > dados.quantidade) { 
 
            if (dados.cod != 0){

                printf("\n\t%i,%s,%d",dados.cod,dados.descricao,dados.quantidade);
                printf("\n");
            } 

            fseek(arq, 0, SEEK_CUR);    
        }
    }
    fclose(arq);
    printf("\n\tOperacao de busca finalizada\n");
    system("PAUSE");
     
}

void insercao() {
    FILE *arquivo = fopen("dadosalunomy.bin", "r+b");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo\n");
        return;
    }

    registro registros[1000];
    int num_registros = 0;
    while (fread(&registros[num_registros], sizeof(registro), 1, arquivo) == 1) {
        num_registros++;
    }

    int i, j;
    registro aux;
    for (i = 1; i < num_registros; i++) {
        aux = registros[i];
        j = i - 1;
        while ((j >= 0) && (strcmp(registros[j].descricao, aux.descricao) > 0)) {
            registros[j + 1] = registros[j];
            j--;
        }
        registros[j+1] = aux;
    }

    fseek(arquivo, 0, SEEK_SET);
    for (i = 0; i < num_registros; i++) {
        fwrite(&registros[i], sizeof(registro), 1, arquivo);
    }

    fclose(arquivo);
}

void remover_registro(){    
    registro dados;
    FILE *arq;
    int aux;
    char llun[30]={""};
    if((arq = fopen("dadosalunomy.bin","rb+")) == NULL){
        printf("\n\tArquivo nao pode ser aberto.");
    }

    printf("diga o codigo alvo:\n");
    scanf("%d",&aux);

    fseek(arq, 0, SEEK_SET); 

    while (fread(&dados, sizeof(dados), 1, arq)) { 
        if (aux == dados.cod) { 
            dados.cod=0;
            strcpy(dados.descricao,llun);
            dados.quantidade=0;
            fseek(arq, -sizeof(dados), SEEK_CUR);
            fwrite(&dados,sizeof(dados),1,arq);        
            break; 
        }
    }
    fclose(arq);
    printf("\n\tOperacao de remocao finalizada\n");
    system("PAUSE");

}