#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int contagem;
    int cod;
    char nome[20];
    float locacao;
}registro;

registro reg = { 0, 0, "", 0.0 };

void formatacao();
void escrita();
void leitura();
void busca();

int main() {
   int resp;

    printf("Sistema de locacao baseado em arquivo\n");
    printf("Informe a opcao desejada (1-formatar, 2-escrever, 3-ler, 4-buscar, 0-finalizar):\n");

    while(resp!=0){
        printf("\n");
        scanf("%d",&resp);

        if(resp==1){
            formatacao();
        }else if(resp==2){
            escrita();        
        }else if(resp==3){
            leitura();    
        }else if(resp==4){
            busca();
        }
    }


    return 0;
}

void formatacao(){
    int i;

    FILE *fPtr;
    if ( ( fPtr = fopen( "dados.bin", "wb" ) ) == NULL ) {
        printf( "Arquivo nao porde ser aberto\n" );
    }
    else {
        for ( i = 1; i <= 1000; i++ ) {
            fwrite( &reg, sizeof(registro), 1, fPtr );
        }
        fclose ( fPtr );
        printf( "File created.\n" );
    }

}

void escrita(){
    
    FILE *cfPtr;
    
    if ( ( cfPtr = fopen( "dados.bin", "rb+" ) ) == NULL ) {
        printf( "Arquivo nao pode ser aberto\n" );
    }
    else{
    	
        printf( "Entre com o numero da conta"
                " ( de 1 ate 1000, 0 para fechar o input )\n? " );
        scanf( "%d", &reg.contagem );
        while ( reg.contagem != 0 ) {
            printf( "Enter codigo, nome, locacao\n? " );
            scanf( "%d%s%f",&reg.cod,reg.nome, &reg.locacao);
            fseek( cfPtr, ( reg.contagem - 1 ) * sizeof(registro), SEEK_SET );
            fwrite( &reg, sizeof(registro), 1, cfPtr );
            printf( "Enter account number\n? " );
            scanf( "%d",&reg.contagem);
        }
        printf("\n\tOperacao de escrita finalizada\n");
        fclose( cfPtr );
        
    }        
}

void leitura(){
    
    registro dados;
    system("cls");
    FILE *arq;
    int i = 0;
    arq = fopen("dados.bin","rb+");
    if(arq == NULL)
    {
        printf("\n\tArquivo nao pode ser aberto.");
    }

    while(!feof(arq))
    {
        fseek(arq, ((i) * sizeof(dados)), SEEK_SET);
        fread(&dados, sizeof(dados),1,arq);
        if (dados.cod != 0)
        {

            printf("\n\tCodigo de locacao: %i", dados.cod);
            printf("\n\tNome do Veiculo: %s", dados.nome);
            printf("\n\tValor da locacao: %.2f", dados.locacao);
            printf("\n");
        }
        i++;
    }
    printf("\n\tOperacao de leitura finalizada\n");
    fclose(arq);
}

void busca(){
    
    FILE *cfPtr;
    if ( ( cfPtr = fopen( "dados.bin", "rb" ) ) == NULL ) {
        printf( "Arquivo nao pode ser aberto\n" );
    }
    else {
        printf( "Entre com a locazicao da conta"
                " (de 1 ate 1000, 0 para fechar o input )\n? " );
        scanf( "%d", &reg.contagem);
        while ( reg.contagem != 0 ) {
            fseek( cfPtr, ( reg.contagem - 1 ) * sizeof(registro), SEEK_SET );
            fread( &reg, sizeof(registro), 1, cfPtr );
            printf( "Codigo          nome            locacao\n " );
            printf( "%-16d%-10s%10.2f\n",reg.cod, reg.nome, reg.locacao );            
            printf( "Entre com o numero da conta\n? ");
            scanf( "%d", &reg.contagem);
        }
        printf("\n\tOperacao de busca finalizada\n");
        fclose( cfPtr );
    }    
}