typedef struct series Series;

int insesrirAVL_S(Series **raiz,Series *no);
void cadastrarSerie(Series** raiz);
void liberaSerie(Series *a);
void ordenado_S(Series* raiz);
Series * busca_codigo_S(Series *raiz,int id);
void liberaTemporada(Series *a);
int Altura_S(Series *raiz);
void rotacaoEsquerda_S(Series **raiz);
void rotacaoDireita_S(Series **raiz);