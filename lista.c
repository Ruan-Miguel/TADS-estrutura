#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"
#include"questao1.h"

struct lista{
	Nodo *inicio;
};

struct nodo{
	TAD *conteudo;
	struct nodo *proximo;
};

Lista *cria_lista(){
	Lista *nova=(Lista*)malloc(sizeof(Lista));
	nova->inicio=NULL;
	return nova;
}

int lista_vazia(Lista *lista){
	if(lista->inicio==NULL){
		return 1;
	}
	return 0;
}

void insere_ordenado(Lista *lista,char novoconteudo[100]){
	Nodo *novo=(Nodo*)malloc(sizeof(Nodo));
	novo->proximo=NULL;
	novo->conteudo=cria_tad();
	insere_tad(novo->conteudo,novoconteudo);
	if(lista->inicio==NULL){
		lista->inicio=novo;
	}else{
		Nodo *aux=lista->inicio;
		Nodo *anterior;
		char nome_aux[100];
		strcpy(nome_aux,retorna_valor(aux->conteudo));
		while(aux->proximo!=NULL){
			if(strcmp(novoconteudo,nome_aux)>0){
				anterior=aux;
				aux=aux->proximo;
				strcpy(nome_aux,retorna_valor(aux->conteudo));
			}else{
				break;
			}
		}
		if(strcmp(novoconteudo,nome_aux)<0){
			novo->proximo=aux;
			if(lista->inicio!=aux){
				anterior->proximo=novo;
			}else{
				lista->inicio=novo;
			}
		}else if(strcmp(novoconteudo,nome_aux)==0){
			printf("ja ha um funcionario com esse nome");
			free(novo);
		}else{
			aux->proximo=novo;
		}
	}
}

void inserir_inicio(Lista *lista,char novoconteudo[100]){
	Nodo *novo=(Nodo*)malloc(sizeof(Nodo));
	novo->conteudo=cria_tad();
	insere_tad(novo->conteudo,novoconteudo);
	if(lista->inicio==NULL){
		lista->inicio=novo;
		novo->proximo=NULL;
	}else{
		novo->proximo=lista->inicio;
		lista->inicio=novo;
	}
}

void inserir_final(Lista *lista,char novochar[100]){
	Nodo *novo=(Nodo*)malloc(sizeof(Nodo));
	novo->conteudo=cria_tad();
	insere_tad(novo->conteudo,novochar);
	novo->proximo=NULL;
	if(lista->inicio==NULL){
		lista->inicio=novo;
	}else{
		Nodo *aux=lista->inicio;
		while(aux->proximo!=NULL){
			aux=aux->proximo;
		}
		aux->proximo=novo;
	}
}

void inserir_local(Lista *lista,char novochar[100],int local){
	Nodo *novo=(Nodo*)malloc(sizeof(Nodo));
	novo->conteudo=cria_tad();
	insere_tad(novo->conteudo,novochar);
	if(lista->inicio==NULL){
		printf("posicao nao esxiste");
	}else{
		Nodo *aux=lista->inicio;
		local--;
		while(aux->proximo!=NULL && local>1){
			aux=aux->proximo;
			local--;
		}
		if(local==1){
			novo->proximo=aux->proximo;
			aux->proximo=novo;
		}else{
			printf("posicao nao esxiste");
		}
	}
}

char *retira_inicio(Lista *lista){
	if(lista->inicio==NULL){
		printf("a lista esta vazia");
	}else{
		Nodo *aux=lista->inicio;
		char *retorno=retorna_valor(aux->conteudo);
		lista->inicio=aux->proximo;
		free(aux->conteudo);
		free(aux);
		return retorno;
	}
}

void retira(Lista *lista,char componente[100]){
	char nome_aux[100];
	Nodo *aux=lista->inicio;
	Nodo *anterior=NULL;
	while(aux!=NULL){
		strcpy(nome_aux,retorna_valor(aux->conteudo));
		if(strcmp(componente,nome_aux)!=0){
			anterior=aux;
			aux=aux->proximo;
		}else{
			break;
		}
	}
	if(aux==NULL){
		printf("esse nome nao esta na lista");
	}else{
		if(lista->inicio==aux){
			lista->inicio=aux->proximo;
		}else{
			anterior->proximo=aux->proximo;
		}
		free(aux->conteudo);
		free(aux);
	}
}

void imprimir_lista(Lista *lista){
	if(lista->inicio!=NULL){
		char *valor;
		Nodo *aux=lista->inicio;
		while(aux!=NULL){
			valor=retorna_valor(aux->conteudo);
			aux=aux->proximo;
		}
	}
}
