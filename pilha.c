#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"questao1.h"
#include"questao2.h"
#include"questao3.h"
#include"questao4.h"
#include"questao6.h"
#include"pilha.h"

struct nodo{
	TAD *conteudo;
	struct nodo *proximo;
};

struct pilha{
	Nodo *topo;
};

Pilha *criaPilha(){
	Pilha *pilha=(Pilha*)malloc(sizeof(Pilha));
	pilha->topo=NULL;
	return pilha;
}

void push(Pilha *pilha,char novochar[100]){
	Nodo *novo=(Nodo*)malloc(sizeof(Nodo));
	novo->conteudo=cria_tad();
	insere_tad(novo->conteudo,novochar);
	novo->proximo=pilha->topo;
	pilha->topo=novo;
}

int pilha_vazia(Pilha *pilha){
	if(pilha->topo==NULL){
		return 1;
	}
	return 0;
}

char *pop(Pilha *pilha){
	char *resultado;
	if(pilha_vazia(pilha)){
		resultado=(char*)calloc(6,sizeof(char));
		strcpy(resultado,"false");
	}else{
		Nodo *aux=pilha->topo;
		resultado=retorna_valor(aux->conteudo);
		pilha->topo=aux->proximo;
		free(aux->conteudo);
		free(aux);
	}
	return resultado;
}

char *primeiroDaPilha(Pilha *pilha){
	Nodo *aux=pilha->topo;
	return retorna_valor(aux->conteudo);
}

char *ultimoDaPilha(Pilha *pilha){
	Nodo *aux=pilha->topo;
	while(aux->proximo!=NULL){
		aux=aux->proximo;
	}
	return retorna_valor(aux->conteudo);
}

int numerodequebra(Pilha *estaca){
	Nodo *aux=estaca->topo;
	int num1,num2;
	num1=chartoint(retorna_valor(aux->conteudo));
	aux=aux->proximo;
	if(aux!=NULL){
		num2=chartoint(retorna_valor(aux->conteudo));
		while(num1-num2==-1 && aux->proximo!=NULL){
			num1=num2;
			aux=aux->proximo;
			num2=chartoint(retorna_valor(aux->conteudo));
		}
		if(aux->proximo==NULL){
			if(num1-num2==-1){
				num1=num2;
			}
		}
	}
	return num1;
}

void printestaca(Pilha *estaca){
	if(pilha_vazia(estaca)){
		printf("|\n");
	}else{
		Nodo *aux=estaca->topo;
		int valor;
		while(aux!=NULL){
			valor=chartoint(retorna_valor(aux->conteudo));
			while(valor>0){
				printf("*");
				valor--;
			}
				printf("\n");
			aux=aux->proximo;
		}
	}
}
