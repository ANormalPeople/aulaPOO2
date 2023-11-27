#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int contagem;
    int cod;
    char descricao[30];
    float preco;
}registro;

registro reg = {0,0, "", 0.0 };

void formatacao();
void escrita(int i);
void leitura();
void leitura_unica();
void insercao();


int main () {
   int resp,i=0;
   FILE *arq;

    if ((arq = fopen("dados.bin", "rb+")) == NULL){
        formatacao();
    }else{
        fread(&reg, sizeof(registro), 1, arq);
    }

   printf("1-cadastrar\n2-visualizar\n3-vizualizar um registro\n4-ordenar por preco\n5-finalizar\n");

    while(resp!=5){
        printf("\n");
        printf("Informe o modulo desejado:\n");
        scanf("%d",&resp);
        if(resp==1){
            i++;
            escrita(i);
        }else if(resp==2){
            leitura();        
        }else if(resp==3){
            leitura_unica();  
        }else if(resp==4){
            insercao(); 
        }
    }

    return 0;
}

void formatacao(){
    int i;

    FILE *arq;
    if ( ( arq = fopen( "dados.bin", "wb" ) ) == NULL ) {
        printf( "Arquivo nao porde ser aberto\n" );
    }
    else {
        for ( i = 1; i <= 1000; i++ ) {
            fwrite( &reg, sizeof(registro), 1, arq );
        }
        fclose ( arq );
    }

}

void escrita(int i){
    int aux;
    registro dados;
    FILE *arq;
    
    if ((arq = fopen("dados.bin", "rb+")) == NULL) {
        printf("Arquivo nao pode ser aberto\n");
        return;
    }

    printf("Diga o codigo, preco e a descricao\n");
    scanf("%d%f %[^\n]", &aux, &reg.preco, reg.descricao);

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
    
    printf("\n\tOperacao de escrita finalizada\n");
    system("PAUSE");
    fclose(arq);
}   

void leitura(){
    
    registro dados;
    FILE *arq;
    int i = 0;
    if((arq = fopen("dados.bin","rb+")) == NULL){
        printf("\n\tArquivo nao pode ser aberto.");
    }

    while(!feof(arq))
    {

        fseek(arq, ((i) * sizeof(dados)), SEEK_SET);
        if(fread(&dados, sizeof(dados),1,arq)){
        if (dados.cod != 0){

            printf("\n\t%i,%s,%.2f",dados.cod,dados.descricao,dados.preco);
            printf("\n");
        }
        i++;
        }
    }
    printf("\n\tOperacao de leitura finalizada\n");
    system("PAUSE");
    fclose(arq);
}

void leitura_unica(){
    int codigo;
    FILE *cfPtr;
    if ( ( cfPtr = fopen( "dados.bin", "rb" ) ) == NULL ) {
        printf( "Arquivo nao pode ser aberto\n" );
    }
    else {
        printf( "Entre com o codigo da conta?\n");
        scanf( "%d", &codigo);
            while(fread( &reg, sizeof(registro), 1, cfPtr )){
                if(reg.cod==codigo){
                    printf("%d,%s,%.2f",reg.cod,reg.descricao,reg.preco);
                    break;
                }
            }
        fclose(cfPtr);
    }    
}

void insercao() {
    FILE *arquivo = fopen("dados.bin", "r+b");
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
        while ((j >= 0) && (registros[j].preco < aux.preco)) {
            registros[j + 1] = registros[j];
            j--;
        }
        registros[j+1] = aux;
    }

    fseek(arquivo, 0, SEEK_SET);
    for (i = 0; i < num_registros; i++) {
        fwrite(&registros[i], sizeof(registro), 1, arquivo);
    }

    printf("\n\tOperacao de ordenacao finalizada\n");
    system("PAUSE");    
    fclose(arquivo);
}