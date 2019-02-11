#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pilha.h"

#define tamMax 50

int operador(char objetoDeTeste){
	switch(objetoDeTeste){
		case '+':
		case '-':
		case '*':
		case '/':
			return 1;
			break;
		default:
			return 0;
	}
}

int quatroOperacoes(int num1,int num2,char operando){
	switch(operando){
		case '+':
			return num1+num2;
			break;
		case '-':
			return num1-num2;
			break;
		case '*':
			return num1*num2;
			break;
		default:
			return num1/num2;
	}
}

int postfix(char vetor[tamMax]){
	Pilha *pilha=criaPilha();
	int pontob=0;
	int pontoa=pontob;
	while(vetor[pontob]!='\0'){
		pontob=pontoa+1;
		while(vetor[pontob]!=','){
			if(vetor[pontob]=='\0'){
				break;
			}
			pontob++;
		}
		if((pontob-pontoa==1) && operador(vetor[pontob-1])){
			int num2=chartoint(pop(pilha));
			int num1=chartoint(pop(pilha));
			int resultado=quatroOperacoes(num1,num2,vetor[pontob-1]);
			char *pedaco=inttochar(resultado);
			push(pilha,pedaco);
		}else{
			char pedaco[10];
			int aux;
			for(aux=0;aux<pontob-pontoa;aux++){
				pedaco[aux]=vetor[pontoa+aux];
			}
			pedaco[aux]='\0';
			push(pilha,pedaco);
		}
		pontoa=pontob+1;
	}
	return chartoint(pop(pilha));
}

int main(){
	char operacao[tamMax];
	printf("informe uma operacao:");
	gets(operacao);
	int resultado=postfix(operacao);
	printf("resposta: %d",resultado);
	return 0;
}
