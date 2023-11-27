#include <stdio.h>
#include "TAD_lista_estatica.h"
#include "TAD_lista_estatica.c"

int main(){
    Pessoa *p = criar();
    //inserirPessoaInicio(p);
    //inserirPessoaFim(p);
    inserirPessoaOrdenado(p);
    mostrarTodasPessoas(p);
    buscarPessoa(p);
    removerPessoa(p);
    mostrarTodasPessoas(p);
    liberarMemoria(p);
    return 0;
}