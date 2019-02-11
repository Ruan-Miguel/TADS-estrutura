#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"questao3.h"

#define numStrings 3

char stringretorno[numStrings][tamMax];
int localstring=0;

struct componente{
	char termo[tamMax];
};

void complementoDoLocal(){
	if(localstring==numStrings-1){
		localstring=0;
	}else{
		localstring++;
	}
}

int chartoint(char conteudo[tamMax]){
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
	char *retorno=stringretorno[localstring];
	complementoDoLocal();
	for(aux2=0;aux2<casas;aux2++){
		retorno[aux2]=48+(numero/((int)pow(10,casas-1-aux2)))%10;
	}
	retorno[aux2]='\0';
	return retorno;
}

TAD *cria_tad(){
	return (TAD*)malloc(sizeof(TAD));
}

void insere_tad(TAD *novo,char conteudo[tamMax]){
	strcpy(novo->termo,conteudo);
}

char *retorna_valor(TAD *alvo){
	char *resposta=stringretorno[localstring];
	complementoDoLocal();
	strcpy(resposta,alvo->termo);
	return resposta;
}
