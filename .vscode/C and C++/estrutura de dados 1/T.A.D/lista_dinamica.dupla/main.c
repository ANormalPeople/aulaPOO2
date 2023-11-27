#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "pessoa.c"

int main () {

    Pessoa *l = criarlista();
    l = inserir(l);
    l = inserir(l);
    l = inserir(l);
    mostrarTodasPessoas(l);
    l = removerPessoa(l);
    mostrarTodasPessoas(l);
    return 0;
}