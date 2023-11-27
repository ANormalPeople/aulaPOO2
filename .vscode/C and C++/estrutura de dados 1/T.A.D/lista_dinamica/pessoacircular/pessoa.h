typedef struct pessoa Pessoa;

Pessoa *criarlista();
Pessoa *inserir(Pessoa *l);
void inserirPessoaInicio(Pessoa **lista);
void inserirPessoaFim(Pessoa **lista);
void inserirPessoaOrdenado(Pessoa **l); 
void mostrarPessoa(Pessoa *lista);
void mostrarTodasPessoas(Pessoa *lista);
int contarPessoasNaLista(Pessoa *lista);
void buscarPessoa(Pessoa *lista);
Pessoa *removerPessoa(Pessoa *lista,int id);
void liberarMemoria(Pessoa *lista);