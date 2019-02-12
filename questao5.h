//maximo de caracteres deve ser alterado em filaec e em questao5.h
#define maxcaracteres 100

typedef struct componente TAD;

TAD *cria_tad(int tamanho);

void insere_tad(TAD *novo,char novoconteudo[maxcaracteres],int prioridade,int local);

void imprime_tad(TAD *atual,int local);

char *retorna_conteudo(TAD *atual,int local);

int retorna_prioridade(TAD *atual,int local);

void realoca(TAD *atual,int inicio,int fim,int tamanho);
