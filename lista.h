typedef struct lista Lista;

typedef struct nodo Nodo;

Lista *cria_lista();

int lista_vazia(Lista *lista);

void insere_ordenado(Lista *lista,char novoconteudo[100]);

void inserir_inicio(Lista *lista,char novochar[100]);

void inserir_final(Lista *lista,char novochar[100]);

void inserir_local(Lista *lista,char novochar[100],int local);

void retira(Lista *lista,char componente[100]);

char *retira_inicio(Lista *lista);

void imprimir_lista(Lista *lista);
