typedef struct nodo Nodo;

typedef struct pilha Pilha;

Pilha *criaPilha();

void push(Pilha *pilha,char novochar[100]);

int pilha_vazia(Pilha *pilha);

char *pop(Pilha *pilha);

char *primeiroDaPilha(Pilha *pilha);

char *ultimoDaPilha(Pilha *pilha);

int numerodequebra(Pilha *estaca);

void printestaca(Pilha *estaca);
