#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"questao5.h"

#define numStrings 3

char stringretorno[numStrings][maxcaracteres];
int localstring=0;

void complementoDoLocal(){
	if(localstring==numStrings-1){
		localstring=0;
	}else{
		localstring++;
	}
}

struct componente{
	char conteudo[maxcaracteres];
};

TAD *cria_tad(int tamanho){
	return (TAD*)calloc(tamanho,sizeof(TAD));
}

void insere_tad(TAD *novo,char novoconteudo[maxcaracteres],int local){
	strcpy(novo[local].conteudo,novoconteudo);
}

void imprime_tad(TAD *atual,int local){
	printf("conteudo para impressao: %s\n",atual[local].conteudo);
}

char *retorna_conteudo(TAD *atual,int local){
	char *resposta=stringretorno[localstring];
	complementoDoLocal();
	strcpy(resposta,atual[local].conteudo);
	return resposta;
}

