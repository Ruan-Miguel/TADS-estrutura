#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pilha.h"

#define maxCaracteres 500

int balanceamento(char vetor[maxCaracteres]){
	Pilha *pilha=criaPilha();
	char *vetoraux,comparador,aux2[2];
	aux2[1]='\0';
	int aux;
	for(aux=0;aux<strlen(vetor);aux++){
		switch(vetor[aux]){
			case ')':
			case ']':
			case '}':
				if(pilha_vazia(pilha)){
					return 0;
				}else{
					vetoraux=primeiroDaPilha(pilha);
					switch(vetor[aux]){
						case ')':
							comparador='(';
							break;
						case ']':
							comparador='[';
							break;
						default:
							comparador='{';
					}
					if(vetoraux[0]!=comparador){
						return 0;
					}else{
						pop(pilha);
					}
				}
				break;
			case '/':
				if(aux>0 && vetor[aux-1]=='*'){
					if(pilha_vazia(pilha)){
					return 0;
					}else{
						vetoraux=primeiroDaPilha(pilha);
						if(strcmp(vetoraux,"/*")!=0){
							return 0;
						}else{
							pop(pilha);
						}
					}
				}else if(vetor[aux+1]=='*'){
					push(pilha,"/*");
				}
				break;
			case '(':
			case '[':
			case '{':
				aux2[0]=vetor[aux];
				push(pilha,aux2);
				break;
		}
	}
	if(!pilha_vazia(pilha)){
		return 0;
	}
	return 1;
}

int main() {
	int resultado;
	char texto[maxCaracteres];
	printf("informe uma string:");
	gets(texto);
	resultado=balanceamento(texto);
	switch(resultado){
		case 1:
			printf("o texto esta balanceado");
			break;
		default:
			printf("o texto esta desbalanceado");
	}
}
