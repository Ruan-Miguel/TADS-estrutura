/*TAMANHO MAXIMO DO VETOR*/

#define tamMax 100

typedef struct componente TAD;

int chartoint(char conteudo[tamMax]);

char *inttochar(int numero);

TAD *cria_tad();

void insere_tad(TAD *novo,char conteudo[tamMax]);

char *retorna_valor(TAD *alvo);
