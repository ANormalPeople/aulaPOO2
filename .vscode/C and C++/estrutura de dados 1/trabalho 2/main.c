#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cliente.h"
#include "rotas.h"
#include "transportadora.h"
#include "cliente.c"
#include "rotas.c"
#include "transportadora.c"

void showMenu();

int main(){
    srand((unsigned) time(NULL));

    Transportadora *transLog = criar();
    int option,x=0; 

    while(x!=1){
        showMenu(); scanf("%d", &option);

        switch(option){
            case 1:
                cadastrarClienteTransportadora(transLog);
                break;
            
            case 2:
                mostrarClientesTransportadora(transLog);
                break;

            case 3:
                cadastrarRotaTransportadora(transLog);
                break;

            case 4:
                mostrarRotasTransportadora(transLog);
                break;

            case 5:
                fazerEntrega(transLog);
                break;
            
            case 6:
                mostrarPilhaEntregasFalhas(transLog);
                break;

            case 7:
                mostrarEstatisticas(transLog);
                break;

            case 8:
                entregarPilhaFalhas(transLog);
                break;

            case 9:
                mostrarFilaDevolucao(transLog);
                break;

            case 10:
                x=1;
                break;

            default:
                printf("\nInsira uma opcao valida!\n");
        }
    }
    return 0;
}

void showMenu(){
    printf("\n1 - Cadastrar clientes\n2 - Mostrar clientes\n3 - Cadastrar entrega/rota\n4 - Mostrar rotas\n");
    printf("5 - Fazer entrega\n6 - Mostrar entregas nao efetuadas\n7 - Estatisticas\n8 - Tentar nova entrega\n9 - Mostrar fila de devolucao\n10 - Sair");
    printf("\n>>> ");
}