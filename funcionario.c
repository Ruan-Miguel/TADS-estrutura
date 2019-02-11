#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funcionario.h"

struct funcionario{
	char nome[100];
	char cpf[20];
	int idade;
	float salario;
};

TAD *cria_tad(){
	return (TAD*)malloc(sizeof(TAD));
}

void insere_tad(TAD *novo){
	fflush(stdin);
	printf("informe o nome do funcionario:");
	gets((*novo).nome);
	printf("informe o cpf do funcionario:");
	gets((*novo).cpf);
	printf("informe a idade do funcionario:");
	scanf("%d",&(*novo).idade);
	printf("informe o salario do funcionario: R$ ");
	scanf("%f",&(*novo).salario);
}

void imprime_tad(TAD *atual){
	printf("nome: %s\n",atual->nome);
	printf("cpf: %s\n",atual->cpf);
	printf("idade: %d\n",atual->idade);
	printf("salario: R$ %.2f\n",atual->salario);
}

void retorna_nome(TAD *funcionario,char nome[100]){
	strcpy(nome,funcionario->nome);
}

