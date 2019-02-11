#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"questao2.h"

struct componente{
	char termo[2];
};

TAD *cria_tad(){
	return (TAD*)malloc(sizeof(TAD));
}

void insere_tad(TAD *novo,char conteudo[2]){
	strcpy(novo->termo,conteudo);
}

char *retorna_valor(TAD *alvo){
	char *resposta=(char*)calloc(2,sizeof(char));
	strcpy(resposta,alvo->termo);
	return resposta;
}
