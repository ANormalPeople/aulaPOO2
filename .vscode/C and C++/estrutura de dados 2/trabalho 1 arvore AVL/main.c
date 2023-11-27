#include <stdio.h>
#include <stdlib.h>
#include "Series.h"
#include "temporadas.h"
#include "participantes.h"
#include "Series.c"
#include "temporadas.c"
#include "participantes.c"

int main () {
    Series *arvore,*arvore_Temporada;
    Temporadas *lista_participante;
    int id,opcao,id_todos_artistas,v;
    char aux_personagem[100];

    lista_participante = NULL;
    arvore_Temporada = NULL;    
    arvore = NULL;

    while (1) {
        printf("\n==== Menu ====\n");
        printf("1. Cadastrar Serie\n");
        printf("2. Cadastrar Temporada\n");
        printf("3. Cadastrar Participante\n");
        printf("4. Imprimir series ordenadas por codigo\n");
        printf("5. Imprimir temporadas de uma serie\n");
        printf("6. Imprimir personagens de uma temporada\n");
        printf("7. Imprimir artistas que interpretaram um personagem\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:

                cadastrarSerie(&arvore);
                break;
            
            case 2:
            
                printf("Diga o id da serie que deseja acessar: ");
                scanf("%d",&id);
                arvore_Temporada = busca_codigo_S(arvore,id);
                if(arvore_Temporada == NULL){
                    printf("Serie nao encontrada!!\n");
                }
                else{
                    v = cadastrarTemporada(&arvore_Temporada->temporadas);
                    if(v == 1)
                    arvore_Temporada->numTemporadas += 1;   
                    v = 0;
                }
                break;

            case 3:
            
                printf("Diga o id da serie que deseja acessar:");
                scanf("%d",&id);
                arvore_Temporada = busca_codigo_S(arvore,id);

                if(arvore_Temporada == NULL)
                    printf("Serie nao encontrada!!\n");
                else{
                    printf("Agora diga o id da temporada: ");
                    scanf("%d",&id);
                    lista_participante = busca_codigo_T(arvore_Temporada->temporadas,id);

                    if(lista_participante == NULL)
                        printf("Temporada nao encontrada!!\n");
                    else{
                        cadastro_P(&lista_participante->participantes);
                    }
                }
                break; 
            case 4:

                ordenado_S(arvore);
                break;

            case 5:

                printf("Diga o id da serie que deseja acessar\n");
                scanf("%d",&id);
                arvore_Temporada = busca_codigo_S(arvore,id);
                
                if(arvore_Temporada != NULL)
                    ordenado_T(arvore_Temporada->temporadas);
                break;

            case 6:
            
                printf("Diga o id da serie que deseja acessar: ");
                scanf("%d",&id);
                arvore_Temporada = busca_codigo_S(arvore,id);

                if(arvore_Temporada == NULL)
                    printf("Serie nao encontrada!!\n");
                else{
                    printf("Agora diga o id da temporada: ");
                    scanf("%d",&id);
                    lista_participante = busca_codigo_T(arvore_Temporada->temporadas,id);

                    if(lista_participante == NULL)
                        printf("Temporada nao encontrada!!\n");
                    else
                        mostrar(lista_participante->participantes);
                }
                break;
            
            case 7:
                
                printf("Diga o id da serie: ");
                scanf("%d",&id_todos_artistas);

                printf("Diga o nome do personagem\n");
                scanf("%s",aux_personagem);	
                
                Series *aux = busca_codigo_S(arvore,id_todos_artistas);
                if(aux == NULL)
                    printf("Arvore nao encontrada!");
                else{
                    mostrar_artista(aux->temporadas,aux_personagem);
                }
                break;
            
            case 0:
            
                liberaSerie(arvore);
                return 0;
            
            default:
            
                printf("Opcao invalida. Por favor, escolha novamente.\n");
                getchar();

        }
    }

    return 0;
}

