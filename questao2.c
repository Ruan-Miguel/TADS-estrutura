#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"questao2.h"

struct componente{
	char termo[10];
};

int chartoint(char conteudo[10]){
	int valorreal=0,numcasas;
	int aux=0;
	while(conteudo[aux]!='\0'){
		aux++;
	}
	numcasas=aux;
	do{
		aux--;
		valorreal+=((int)conteudo[aux]-48)*pow(10,numcasas-1-aux);
	}while(aux!=0);
	return valorreal;
}

char *inttochar(int numero){
	int casas=0,aux2;
	int copia=numero;
	while(copia!=0){
		copia/=10;
		casas++;
	}
	char *resposta=(char*)calloc(casas+1,sizeof(char));
	for(aux2=0;aux2<casas;aux2++){
		resposta[aux2]=48+(numero/((int)pow(10,casas-1-aux2)))%10;
	}
	return resposta;
}

TAD *cria_tad(){
	return (TAD*)malloc(sizeof(TAD));
}

void insere_tad(TAD *novo,char conteudo[10]){
	strcpy(novo->termo,conteudo);
}

char *retorna_valor(TAD *alvo){
	char *resposta=(char*)calloc(10,sizeof(char));
	strcpy(resposta,alvo->termo);
	return resposta;
}
