#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "pessoa.c"

int main () {
    Pessoa *P = criarlista();
    inserirPessoaInicio(&P);
    inserirPessoaFim(&P);
    inserirPessoaOrdenado(&P);
    mostrarTodasPessoas(P);
    printf("\ninserção\n");
    // buscarPessoa(P);
    removerPessoa(&P);
    mostrarTodasPessoas(P);
    printf("%d",contarPessoasNaLista(P));
    liberarMemoria(P);
    return 0;
}