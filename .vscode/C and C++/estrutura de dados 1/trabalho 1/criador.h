typedef struct criador Criador;
Criador *criarListaDuplaCriadores();
Criador *cadastrar(Criador *criadores);
Criador *removerCriador(Criador *criadores, int id);//nao é permitido remover criador com fazendas cadastradas
int buscar(Criador *criadores, int id);

//Funções Ciradas pela Dupla
int validacao(Criador *c);
void liberarMemCriador(Criador *criadores);
float calcPatrimonio(Criador *criadores, int id);
void printCriadores(Criador *criadores);
Criador *acharporID(Criador *c,int idcr);