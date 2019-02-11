//numero de lugares da fila
#define tamMax 15
//maximo de caracteres deve ser alterado em filaec e em questao5.h
#define maxcaracteres 100

typedef struct filaec Filaec;

Filaec *criaFilaec();

int fila_vazia();

int fila_cheia();

int insereTad(Filaec *fila,char valor[maxcaracteres]);

char *retiraTad(Filaec *fila);
