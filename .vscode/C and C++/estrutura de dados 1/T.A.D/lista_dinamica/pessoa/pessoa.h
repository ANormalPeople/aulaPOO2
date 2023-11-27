typedef struct pessoa Pessoa;

Pessoa *criarlista();
void inserirPessoaInicio(Pessoa **lista);
void inserirPessoaFim(Pessoa **lista);
void inserirPessoaOrdenado(Pessoa **l); 
void mostrarPessoa(Pessoa *lista);
void mostrarTodasPessoas(Pessoa *lista);
int contarPessoasNaLista(Pessoa *lista);
void buscarPessoa(Pessoa *lista);
void removerPessoa(Pessoa **lista);
void liberarMemoria(Pessoa *lista);