#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PALAVRA_LEN 50
#define MAX_NUM_PALAVRAS 100000
#define MAX_NUM_STOPWORDS 10000

int contador = 0;


// Estrutura para armazenar as palavras e suas frequências
typedef struct {
    char _palavra[MAX_PALAVRA_LEN];
    int freq;
    int cont;
} PalavraFreq;


int leitura_stopwords(const char *arquivonome, char **stopwords);// Função para ler as stopwords do arquivo
int caso_stopword(char *palavra, char **stopwords, int num_stopwords);// Função para verificar se uma palavra é uma stopword
int comparacao_da_frequencia_de_palavras(const void *a, const void *b);// Função para comparar duas estruturas WordFreq pelo valor da frequência


int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Uso: %s <arquivo de entrada> <arquivo de stopwords> <quantidade de palavras> <arquivo de saída>\n", argv[0]);
        exit(1);
    }

    // Abrir o arquivo de entrada
    FILE *entrada_arquivo = fopen(argv[1], "r");
    if (entrada_arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada %s\n", argv[1]);
        exit(1);
    }

    // Ler as stopwords
    char *stopwords[MAX_NUM_STOPWORDS];
    int num_stopwords = leitura_stopwords(argv[2], stopwords);

    // Ler as palavras do arquivo de entrada e contar suas frequências
    char temp[MAX_PALAVRA_LEN];
    int num_pl = 0;
    PalavraFreq pl_freqs[MAX_NUM_PALAVRAS];
    while (fscanf(entrada_arquivo, "%s", temp) != EOF) {
        // Verificar se a palavra tem um caractere especial no fim
        int ultimo_char_tiraoponto = strlen(temp) - 1;
    while (ultimo_char_tiraoponto >= 0 && !isalnum(temp[ultimo_char_tiraoponto])) {
        temp[ultimo_char_tiraoponto] = '\0';
        ultimo_char_tiraoponto--;
    }

    // Transformar a palavra em minúsculas
    int i;
    for (i = 0; temp[i]; i++) {
        temp[i] = tolower(temp[i]);
    }

        // Ignorar as stopwords e as palavras com menos de três caracteres
        if (!caso_stopword(temp, stopwords, num_stopwords) && strlen(temp) >= 3) {
            //
            int j;
            for ( j = 0; j < num_pl; j++)
            {
                if (strcmp(temp,pl_freqs[j]._palavra) == 0)
                {
                    pl_freqs[j].cont ++;
                    break;
                }
                
            }
            if (j == num_pl)
            {
                strcpy(pl_freqs[num_pl]._palavra, temp);
                pl_freqs[num_pl].freq = 1;
                pl_freqs[num_pl].cont = 1;
                num_pl++;
            }
            
            
        }
    }
    qsort(pl_freqs, num_pl, sizeof(PalavraFreq), comparacao_da_frequencia_de_palavras);

    // Escrever as palavras mais frequentes no arquivo de saída
    FILE *saida_do_arquivo = fopen(argv[4], "w");
    if (saida_do_arquivo == NULL) {
        printf("Erro ao abrir o arquivo de saída %s\n", argv[4]);
        exit(1);
    }
    int quantidade_de_pl = atoi(argv[3]);
    int i;
        
    for (i = 0; i < quantidade_de_pl && i < num_pl; i++) {
        fprintf(saida_do_arquivo, "%s - %d\n", pl_freqs[i]._palavra,pl_freqs[i].cont);
        
    }

    // Fechar os arquivos e liberar a memória alocada
    fclose(entrada_arquivo);
    fprintf(saida_do_arquivo,"%d",contador);
    fclose(saida_do_arquivo);
    int j;
    for (j = 0; j < num_stopwords; j++) {
        free(stopwords[j]);
    }
    return 0;

}

int leitura_stopwords(const char *arquivonome, char **stopwords) {
    FILE *fp = fopen(arquivonome, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de stopwords %s\n", arquivonome);
        exit(1);
    }

    int i = 0;
    char aux[MAX_PALAVRA_LEN];
    while (fgets(aux, MAX_PALAVRA_LEN, fp) != NULL) {
        // Remove o caractere de nova linha
        strtok(aux, "\n");
        stopwords[i] = (char*) malloc(strlen(aux) + 1);
        strcpy(stopwords[i], aux);
        i++;
    }

    fclose(fp);
    return i;
}

int caso_stopword(char *palavra, char **stopwords, int num_stopwords) {//caso seja uma stopword
    int i;
    for (i = 0; i < num_stopwords; i++) {
        if (strcmp(palavra, stopwords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int comparacao_da_frequencia_de_palavras(const void *a, const void *b) {
    contador++;
    PalavraFreq *freq_palavra_a = (PalavraFreq*) a;
    PalavraFreq *freq_palavra_b = (PalavraFreq*) b;
    if (freq_palavra_a->cont > freq_palavra_b->cont) {
        return -1;
    } else if (freq_palavra_a->cont < freq_palavra_b->cont) {
        return 1;
    }else {
        return 0;
    }
    
}
