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

int insereTadPrioridade(Filaec *fila,char valor[maxcaracteres],int prioridade){
	int resposta;
	if(fila_cheia()){
		resposta=0;
	}else{
		resposta=1;
		int aux=inicio,aux2;
		switch(prioridade){
			case 1:
			case 2:
				if(fila_vazia()){
					if(inicio+numComponentes>=tamMax){
						aux2=inicio+numComponentes-tamMax;
					}else{
						aux2=inicio+numComponentes;
					}
					insere_tad(fila->vetorPrincipal,valor,prioridade,aux2);
				}else{
					while(retorna_prioridade(fila->vetorPrincipal,aux)<=prioridade){
						aux++;
						if(aux==tamMax){
							aux=0;
						}
					}
					if(inicio+numComponentes-1<tamMax){
						aux2=inicio+numComponentes-1;
					}else{
						aux2=inicio+numComponentes-tamMax-1;
					}
					if(aux==aux2){
						if(inicio+numComponentes>=tamMax){
							aux2=inicio+numComponentes-tamMax;
						}else{
							aux2=inicio+numComponentes;
						}
						insere_tad(fila->vetorPrincipal,valor,prioridade,aux2);
					}
					realoca(fila->vetorPrincipal,aux,aux2,tamMax);
					insere_tad(fila->vetorPrincipal,valor,prioridade,aux);
				}
				break;
			case 3:
				if(inicio+numComponentes>=tamMax){
					aux2=inicio+numComponentes-tamMax;
				}else{
					aux2=inicio+numComponentes;
				}
				insere_tad(fila->vetorPrincipal,valor,prioridade,aux2);
				break;
		}
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

void imprime_fila(Filaec *fila){
	char *conteudo;
	int rotacoes=inicio;
	while(rotacoes!=(inicio+numComponentes)%tamMax){
		conteudo=retorna_conteudo(fila->vetorPrincipal,rotacoes);
		printf("conteudo: %s\n",conteudo);
		rotacoes++;
		if(rotacoes==tamMax){
			rotacoes=0;
		}
	}
}
