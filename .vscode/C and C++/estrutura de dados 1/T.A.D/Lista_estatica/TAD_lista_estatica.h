typedef struct pessoa Pessoa;
Pessoa *criar();
void inserirPessoaInicio(Pessoa *lista);
void inserirPessoaFim(Pessoa *lista);
void inserirPessoaOrdenado(Pessoa *lista); //utilizar a idade para inserir em ordem crescente

void mostrarPessoa(Pessoa p);
void mostrarTodasPessoas(Pessoa *lista);
int contarPessoasNaLista(Pessoa *lista);
void buscarPessoa(Pessoa *lista);
void removerPessoa(Pessoa *lista);
void liberarMemoria(Pessoa *lista);