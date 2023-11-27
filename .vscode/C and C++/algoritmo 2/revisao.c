#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
     
    int cod;
    char descricao[30];
    float preco;
}registro;

registro reg = {0, "", 0.0 };

void formatacao();
void escrita(int i);
void leitura();
void remover_registro(); 
void remover_multiplos_registro(); 

int main() {
   int resp,i=0;
   FILE *arq;

    if ((arq = fopen("dados.bin", "rb+")) == NULL){
        formatacao();
    }else{
        fread(&reg, sizeof(registro), 1, arq);
    }

   printf("1-cadastrar\n2-visualizar\n3-remover registro\n4-remover multiplos registros\n5-finalizar\n");

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
            remover_registro();  
        }else if(resp==4){
            remover_multiplos_registro(); 
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
        printf("Enter codigo, descricao, preco\n? ");
        scanf("%d%s%f", &aux, reg.descricao, &reg.preco);

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
    system("cls");
    FILE *arq;
    int i = 0;
    if((arq = fopen("dados.bin","rb+")) == NULL){
        printf("\n\tArquivo nao pode ser aberto.");
    }

    while(!feof(arq))
    {

        fseek(arq, ((i) * sizeof(dados)), SEEK_SET);
        fread(&dados, sizeof(dados),1,arq);
        if (dados.cod != 0)
        {

            printf("\n\t%i,%s,%.2f",dados.cod,dados.descricao,dados.preco);
            printf("\n");
        }
        i++;
    }
    printf("\n\tOperacao de leitura finalizada\n");
    system("PAUSE");
    fclose(arq);
}

void remover_registro(){    
    registro dados;
    FILE *arq;
    int aux;
    char llun[30]={""};
    if((arq = fopen("dados.bin","rb+")) == NULL){
        printf("\n\tArquivo nao pode ser aberto.");
    }

    printf("diga o codigo do registro que deseja remover:\n");
    scanf("%d",&aux);

    fseek(arq, 0, SEEK_SET); 

    while (fread(&dados, sizeof(dados), 1, arq)) { 
        if (aux == dados.cod) { 
            dados.cod=0;
            strcpy(dados.descricao,llun);
            dados.preco=0.0;
            fseek(arq, -sizeof(dados), SEEK_CUR);
            fwrite(&dados,sizeof(dados),1,arq);        
            break; 
        }
    }
    printf("\n\tOperacao de remocao finalizada\n");
    system("PAUSE");
    fclose(arq);

}

void remover_multiplos_registro(){
   registro dados;
    FILE *arq;
    float aux;
    char llun[30]={""};
    if((arq = fopen("dados.bin","rb+")) == NULL){
        printf("\n\tArquivo nao pode ser aberto.");
    }

    printf("diga o valor do registro que deseja usar como base para a remocao:\n");
    scanf("%f",&aux);

    while (fread(&dados, sizeof(dados), 1, arq)) {
        if (aux > dados.preco) { 
            dados.cod=0;
            strcpy(dados.descricao,llun);
            dados.preco=0.0;
            fseek(arq, -sizeof(dados), SEEK_CUR);
            fwrite(&dados,sizeof(dados),1,arq);  
            fseek(arq, 0, SEEK_CUR);    
        }
    }
    printf("\n\tOperacao de remocao finalizada\n");
    system("PAUSE");
    fclose(arq);
    
} 