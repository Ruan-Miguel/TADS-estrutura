#include<stdio.h>
#include<stdlib.h>
#include"filaec.h"

int main() {
	char valordeentrada[maxcaracteres],*valordesaida;
	int opcao,certificacao;
	Filaec *fila=criaFilaec();
	do{
		printf("inserir(1), retirar(2), sair(3):");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				printf("informe o valor:");
				fflush(stdin);
				gets(valordeentrada);
				certificacao=insereTad(fila,valordeentrada);
				if(!certificacao){
					printf("a fila esta cheia");
				}
				break;
			case 2:
				valordesaida=retiraTad(fila);
				printf("valor: %s",valordesaida);
				break;
			case 3:
				break;
			default:
				printf("voce informou uma opcao invalida");
		}
		system("pause");
		system("cls");
	}while(opcao!=3);
	return 0;
}
