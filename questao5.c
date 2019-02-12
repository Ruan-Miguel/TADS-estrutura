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
	int prioridade;
};

TAD *cria_tad(int tamanho){
	return (TAD*)calloc(tamanho,sizeof(TAD));
}

void insere_tad(TAD *novo,char novoconteudo[maxcaracteres],int prioridade,int local){
	strcpy(novo[local].conteudo,novoconteudo);
	novo[local].prioridade=prioridade;
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

int retorna_prioridade(TAD *atual,int local){
	return atual[local].prioridade;
}

void realoca(TAD *atual,int inicio,int fim,int tamanho){
	while(fim!=inicio){
		printf("ue");
		if(fim+1==tamanho){
			atual[0]=atual[fim];
			fim--;
		}else if(fim==0){
			atual[fim+1]=atual[fim];
			fim=tamanho-1;
		}else{
			atual[fim+1]=atual[fim];
			fim--;
		}
	}
	if(fim+1==tamanho){
		atual[0]=atual[fim];
	}else{
		atual[fim+1]=atual[fim];
	}
}
