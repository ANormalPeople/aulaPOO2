typedef struct temporadas Temporadas;


int cadastrarTemporada(Temporadas** raiz);
int insesrir_T(Temporadas **raiz,Temporadas *no);
void ordenado_T(Temporadas *raiz);
Temporadas* busca_codigo_T(Temporadas* raiz, int id);
void mostrar_artista(Temporadas *raiz,char nome[100]);
void liberatemp(Temporadas *a);