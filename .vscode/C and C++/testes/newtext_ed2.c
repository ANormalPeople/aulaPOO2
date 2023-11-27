
int soma_impar_folha(ARV *raiz, int *valor){

    if(raiz == NULL)
        return *valor;

    *valor = soma_impar_folha(raiz->esquerda,valor);
    *valor = soma_impar_folha(raiz->direita,valor);
    if(raiz->esquerda == NULL && raiz->direita == NULL && (raiz->valor % 2) != 0){
        (*valor)++;
    }
    return *valor;

}

int remover(ARV **raiz, int valor){

    if(*raiz == NULL){
        return NULL;
    }
    if(valor < (*raiz)->valor)
        remover((*raiz)->esquerda,valor);
    else if(valor > (*raiz)->valor)
        remover((*raiz)->direita,valor);
    else((*raiz)->valor == valor){
        arv *aux
        if(raiz->esquerda == NULL){

        }ekse if(raiz->direita == NULL){

        }
        *arv TEMPO = menor((*raiz)->direita);


        if((*raiz)->esquerda->direita != NULL){
            aux= (*raiz)->esquerda->direita;
            (*raiz)->esquerda = aux;
            aux = (*raiz)->esquerda->esquerda;
        }else{
            (*raiz)->esquerda = (*raiz)->esquerda->esquerda;
        }

    }

}


void embaralhar(int* array, int tamanho) {
    srand(time(NULL));
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    No* arvore = NULL; // Inicialize a árvore

    int numeros[10001]; // Array para armazenar os números de 0 a 10000

    // Preencha o array com os números de 0 a 10000
    for (int i = 0; i <= 10000; i++) {
        numeros[i] = i;
    }

    embaralhar(numeros, 10001);

    // Criar e cadastrar séries na árvore (insira o código aqui)

    // Medir o tempo inicial
    clock_t inicio = clock();

    // Inserir as séries (insira o código aqui)

    for(int i =0;i<=10000; i++){
    Arvore *no = (Series*)malloc(sizeof(Series));
    no->codigo = numeros[i];
    no->titulo = numeros[i];
    no->numTemporadas = 0;
	no->direita = NULL;
	no->esquerda = NULL;
	no->temporadas = NULL;
    insesrir_S(&arvore, no);
    }

    // Medir o tempo final
    clock_t fim = clock();

    // Calcular o tempo total em segundos
    double tempoTotal = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo total de insercao: %f segundos\n", tempoTotal);

    return 0;
}