#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "fazenda.h"
#include "criador.h"
#include "animal.c"
#include "fazenda.c"
#include "criador.c"

Criador *case1(Criador *a);
Criador *case2(Criador *a);
Fazenda *case3(Fazenda *a,Criador *b);

int main(){
    int op=0;
    Criador *listaCriador = criarListaDuplaCriadores();

    while(op!=4){
        printf("Escolha uma opcao:\n");
        printf("\n(1) Acessar pagina Criador.\n");
        printf("(2) Acessar pagina Fazenda.\n");
        printf("(3) Acessar pagina Animal.\n");
        printf("(4) Finalizar o processo.\n");
        scanf("%d", &op);

        switch (op){
            case 1:
                listaCriador = case1(listaCriador);
                op = 0;      
                break; 
            case 2:
                    if(validacao(listaCriador)==0){
                        getchar();
                        break;
                    }
                    int idcr;
                    Criador *Modificando_fazenda = NULL;
                    printf("\nPrimeiramente digite o id do Criador o qual deseja acessar as fazenda:\n");
                    do{
                        scanf("%d", &idcr);
                        Modificando_fazenda = acharporID(listaCriador,idcr);
                        if(Modificando_fazenda == NULL){
                            printf("\nCriador nao encontrado, tente novamente!\n");
                            idcr = -1;
                        }
                    }while(idcr == -1);
                    Modificando_fazenda = case2(Modificando_fazenda);
                    op = 0;                          
                    break;
            case 3:            
                if(validacao(listaCriador)==0){
                    getchar();
                    break;
                }
                Criador *Modificando_Animal = NULL;
                printf("\nPrimeiramente digite o id do Criador o qual deseja acessar as fazenda:\n");
                do{
                    scanf("%d", &idcr);
                    Modificando_Animal = acharporID(listaCriador,idcr);
                    if(Modificando_Animal == NULL){
                        printf("\nCriador nao encontrado, tente novamente!\n");
                        idcr = -1;
                    }
                }while(idcr == -1);

                if(Modificando_Animal->fazendas != NULL){
                    printf("LISTA DE FAZENDAS CADASTRADAS NO CRIADOR: \n");
                    listafazendas(Modificando_Animal->fazendas);
                }else{
                    printf("Criador em questao sem fazendas, cadastre uma antes de adicionar um rebanho a ela");
                    break;
                }
                int idf;
                Fazenda *modificando = NULL;
                printf("\n Agora diga o id da fazenda o qual deseja acessar os animais:\n");

                do{
                    scanf("%d",&idf);
                    modificando = buscarFazendaID(Modificando_Animal->fazendas,idf);
                    if(Modificando_Animal->fazendas == NULL){
                        printf("\nFazenda nao encontrada\n");
                        idf = -1;
                    }
                }while(idf == -1);
                modificando = case3(modificando,Modificando_Animal);
                Modificando_Animal->patrimonio += modificando->valor_fazenda;
                break;
            case 4:
                break;

            default:
                printf("\nEscolha uma opcao valida!\n");
                getchar();
                break;
            }

    }
    liberarMemCriador(listaCriador);
    return 0;
}


Criador *case1(Criador *listaCriador){
    int escolha = 0;
    printf("\n\nEscolha uma opcao:\n");
    printf("\n(1) Cadastrar criador.\n");
    printf("(2) Remover criador.\n");
    printf("(3) lista de criadores.\n");
    scanf("%d", &escolha);

    if(escolha == 1){
        listaCriador = cadastrar_criador(listaCriador);
    }else if(escolha == 2){
        int id;
        printf("Digite o id do Criador que deseja remover:\n");
        scanf("%d", &id);
        listaCriador = removerCriador(listaCriador, id);
    }else if(escolha == 3){
        printCriadores(listaCriador);
        getchar();
    }else{
        printf("\nescolha invalida!!!\n");
    }
    return listaCriador;      
}

Criador *case2(Criador *Modificando_fazenda){
    int escolha2 = 0;
    while(escolha2 != 5){
        printf("\n\n");
        printf("Escolha uma opcao:\n");
        printf("\n(1) Cadastrar Fazenda.");
        printf("\n(2) Remover Fazenda.");
        printf("\n(3) mostrar Fazendas.");
        printf("\n(4) Lista de animais por stats.");
        printf("\n(5) Caso queira voltar.\n");
        scanf("%d", &escolha2);

        switch(escolha2){
            case 1:        
                Modificando_fazenda->fazendas = cadastrarFazenda(Modificando_fazenda->fazendas);
                Modificando_fazenda->fazendas->id_criador = Modificando_fazenda->id_criador;
                getchar();
                break;
            case 2:
                if(Modificando_fazenda->fazendas != NULL){ 
                    listafazendas(Modificando_fazenda->fazendas); 
                    int id;
                    printf("Digite o id do Fazenda que deseja remover: \n");
                    scanf("%d", &id);
                    Modificando_fazenda->fazendas = removerFazenda(Modificando_fazenda->fazendas, id);
                }else{
                    printf("\nCriador sem fazendas!!!!");
                }
                getchar();
                break;
            case 3:
                if(Modificando_fazenda->fazendas != NULL){
                    listafazendas(Modificando_fazenda->fazendas); 
                }else{
                    printf("\nSem fazendas cadastradas!!!\n");
                }
                getchar();
                break;
            case 4:
                if(Modificando_fazenda->fazendas == NULL){
                    printf("\nlista vazia\n");
                    getchar();
                }else{
                    lista_animais_status(Modificando_fazenda->fazendas);
                    getchar();
                }
                getchar();
                break;

            case 5:
                break;

            default:
                escolha2 = 0;
                printf("\nEscolha invalida!!!\n");
                getchar();
                break;    
        }
    }
    return Modificando_fazenda;
}

Fazenda *case3(Fazenda *modificando, Criador *Modificando_Animal){
    int escolha3 = 0;
    while(escolha3 != 5){
        totalArroba(modificando);
        printf("Escolha uma opcao:\n");
        printf("\n(1) Cadastrar Animal.\n");
        printf("(2) permutar animal\n");
        printf("(3) remover Animal.\n");
        printf("(4) lista de animais\n");
        printf("(5) para voltar\n");
        scanf("%d", &escolha3);

        switch(escolha3){
            case 1:
                modificando->rebanho = cadastro(modificando->rebanho);
                modificando->rebanho->id_fazenda = modificando->id_fazenda;
                getchar();
                break;
            case 2:
                if(modificando->rebanho == NULL){
                    printf("\nsem rebanho cadastrado!!!!\n");
                    getchar();
                    
                }else{
                    printf("\nSERA POSTADO A LISTA REFENRENTE AS FAZENDAS REGISTRADAS NO CRIADOR E A LISTA DE ANIMAIS DESTA\n");
                    printf("FAZENDA PARA AUXILIAR A REALIZACAO DA PERMUTA\n");
                    getchar();
                    listaanimal(modificando->rebanho);
                    listafazendas(Modificando_Animal->fazendas);
                    int id, destino;
                    printf("Digite o id do Animal que deseja remover:\n");
                    scanf("%d", &id);
                    printf("Qual o id do fazenda de destino do animal? \n");
                    scanf("%d", &destino);
            
                    Fazenda *aux =  buscarFazendaID(Modificando_Animal->fazendas,modificando->id_fazenda);
                    Fazenda *aux2 = buscarFazendaID(Modificando_Animal->fazendas,destino);
                    
                    if(aux2 != NULL)
                        modificando->rebanho = permutasAnimais(aux->rebanho,&(aux2->rebanho), id);
                }
                getchar();
                break;        
            case 3:
                if(modificando->rebanho == NULL){
                    printf("\nsem rebanho cadastrado!!!!\n");
                    getchar();
                    
                }else{
                    int id;
                    listaanimal(modificando->rebanho);
                    printf("Digite o id do Animal que deseja remover:\n");
                    scanf("%d", &id);
                    modificando->rebanho = removerA(modificando->rebanho, id);
                }
                getchar();
                break;
            case 4:
                if(modificando->rebanho == NULL){
                    printf("\nlista vazia!!!\n");
                    getchar();
                    
                }else{
                    listaanimal(modificando->rebanho);
                    getchar();
                }
                getchar();
                break;
            case 5:
                break;

            default:
                printf("\nEsolha invalida!!\n");
                getchar();
                break;
            }
        }
    return modificando;
}