#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"filaec.h"
#include"questao5.h"

int inicio=0;
int numComponentes=0;

struct filaec {
	TAD *vetorPrincipal;
};

Filaec *criaFilaec(){
	Filaec *fila=(Filaec*)malloc(sizeof(Filaec));
	fila->vetorPrincipal=cria_tad(tamMax);
	return fila;
}

int fila_vazia(){
	if(numComponentes==0){
		return 1;
	}
	return 0;
}

int fila_cheia(){
	if(numComponentes==tamMax){
		return 1;
	}
	return 0;
}

int insereTad(Filaec *fila,char valor[maxcaracteres]){
	int resposta;
	if(fila_cheia()){
		resposta=0;
	}else{
		resposta=1;
		int local;
		if(inicio+numComponentes>=tamMax){
			local=inicio+numComponentes-tamMax;
		}else{
			local=inicio+numComponentes;
		}
		insere_tad(fila->vetorPrincipal,valor,local);
		numComponentes++;
	}
	return resposta;
}

char *retiraTad(Filaec *fila){
	char *resposta;
	if(fila_vazia()){
		resposta=(char*)calloc(6,sizeof(char));
		strcpy(resposta,"false");
	}else{
		resposta=retorna_conteudo(fila->vetorPrincipal,inicio);
		if(inicio==tamMax-1){
			inicio=0;
		}else{
			inicio++;
		}
		numComponentes--;
	}
	return resposta;
}
