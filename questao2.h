typedef struct componente TAD;

int chartoint(char conteudo[10]);

char *inttochar(int numero);

TAD *cria_tad();

void insere_tad(TAD *novo,char conteudo[10]);

char *retorna_valor(TAD *alvo);
