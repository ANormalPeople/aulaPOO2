typedef struct fazenda Fazenda;
typedef struct endereco Endereco;

Fazenda *criarListaEncadeadaCircularFazendas();
Fazenda *cadastrarFazenda(Fazenda *fazendas);
Fazenda *removerFazenda(Fazenda *fazendas, int id);//nao permitir remover fazenda se houver animais cadastrados
int buscarFazenda(Fazenda *fazendas, int id);

void quantTotalSexo(Fazenda *fazendas);
void calculaPeso(Fazenda *fazendas, int id);
void totalArroba(Fazenda *fazendas);
void lista_animais_status(Fazenda *fazendas);
void listaAnimais(Fazenda *fazendas);
void liberarMemoriaF(Fazenda *fazendas);
Fazenda *buscarFazendaID(Fazenda *fazendas, int id);
void listafazendas(Fazenda *f);