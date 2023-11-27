#include <stdio.h>
#include <stdlib.h>
#include "conta.c"
#include "conta.h"

int main() {

    Conta *Cliente = criar();

    Cliente = inserir(Cliente);
    Cliente = inserir(Cliente);
    mostrar(Cliente);
    // cadastrar(&Cliente);
    // cadastrar(&Cliente);
    // cadastrar(&Cliente);
    // mostrar(Cliente);
    // remover(&Cliente);
    // mostrar(Cliente);


    return 0;
}