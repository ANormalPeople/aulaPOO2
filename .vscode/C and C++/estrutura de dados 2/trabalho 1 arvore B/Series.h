typedef struct series Series;

int insesrir_S(Series **raiz,Series *no);
void cadastrarSerie(Series** raiz);
void liberaSerie(Series *a);
void ordenado_S(Series* raiz);
Series * busca_codigo_S(Series *raiz,int id);
void liberaTemporada(Series *a);