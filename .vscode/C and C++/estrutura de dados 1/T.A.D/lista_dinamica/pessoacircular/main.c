#include <stdio.h>
#include "pessoa.h"
#include "pessoa.c"

int main() {
    Pessoa *l;
    l = criarlista();
    l = Inserir(l);
    l = Inserir(l);
    l = Inserir(l);
    mostrarTodasPessoas(l);
    int id;
    scanf("%d",&id);
    l = removerPessoa(l,id);
    mostrarTodasPessoas(l);
    system("PAUSE");
    return 0;
}