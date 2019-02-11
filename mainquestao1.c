#include<stdio.h>
#include"pilha.h"
#include"lista.h"

void imprimir(Lista *lista){
	char valor[100];
	Pilha *pilha=criaPilha();
	while(!lista_vazia(lista)){
		strcpy(valor,retira_inicio(lista));
		push(pilha,valor);
	}
	while(!pilha_vazia(pilha)){
		strcpy(valor,pop(pilha));
		printf("\n%s",valor);
	}
}

void main(){
	char valor[100];
	int escolha;
	Lista *inicio=cria_lista();
	printf("voce quer uma lista ordenada(1/0)?");
	scanf("%d",&escolha);
	if(escolha==1){
		while(escolha!=2){
			system("pause");
			system("cls");
			printf("inserir(1) ou sair(2):");
			scanf("%d",&escolha);
			switch(escolha){
				case 1:
					printf("informe o conteudo:");
					fflush(stdin);
					gets(valor);
					insere_ordenado(inicio,valor);
					break;
				case 2:
					break;
				default:
					printf("voce informou um numero invalido");
			}
		}
	}else{
		while(escolha!=4){
			int local;
			system("pause");
			system("cls");
			printf("inserir no inicio(1),inserir no final(2),inserir no local indicado(3),acabou(4):");
			scanf("%d",&escolha);
			switch(escolha){
				case 1:
					printf("informe o conteudo:");
					fflush(stdin);
					gets(valor);
					inserir_inicio(inicio,valor);
					break;
				case 2:
					printf("informe o conteudo:");
					fflush(stdin);
					gets(valor);
					inserir_final(inicio,valor);
					break;
				case 3:
					printf("informe o conteudo:");
					fflush(stdin);
					gets(valor);
					printf("informe o local:");
					scanf("%d",&local);
					inserir_local(inicio,valor,local);
					break;
				case 4:
					break;
				default:
					printf("voce informou um numero invalido");
			}
		}
	}
	imprimir(inicio);
}
