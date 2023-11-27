typedef struct participantes Participantes;

void cadastro_P(Participantes **pessoa);
void mostrar_todos_artistas(Participantes *pessoas, char nome[100]);
void mostrar(Participantes *pessoas);
void liberarMem_P(Participantes *pessoas);