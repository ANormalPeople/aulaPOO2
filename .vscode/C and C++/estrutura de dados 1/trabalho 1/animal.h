typedef struct animal Animal;
Animal *criaListaEncadeadaSimplesAnimais();
Animal *cadastro(Animal *rebanho);
Animal *permutasAnimais(Animal *origem, Animal **destino, int id_animal);//obervar para atualizar o status do animal na fazenda de destino
Animal *removerA(Animal *fazenda, int id_animal);


//Funções Desenvolvidadas pela Dupla
float calcArroba(Animal *rebanho);
void liberarMem(Animal *rebanho);
int buscarAnimal(Animal *rebanho, int id_animal);
void listaanimal(Animal *a);
void mostrar(Animal *a);
/*
Desenvolva funcoes que:

Done - Funcao para liberar a memoria
*/