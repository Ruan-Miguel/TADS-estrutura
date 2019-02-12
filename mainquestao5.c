#include<stdio.h>
#include<stdlib.h>
#include"filaec.h"

int main() {
	char valordeentrada[maxcaracteres],*valordesaida;
	int opcao,certificacao,prioridade;
	Filaec *fila=criaFilaec();
	do{
		printf("inserir(1), retirar(2), imprimir fila(3), sair(4):");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				printf("informe o valor:");
				fflush(stdin);
				gets(valordeentrada);
				printf("informe a prioridade(diretor(1),coordenador(2),funcionario(3)):");
				scanf("%d",&prioridade);
				certificacao=insereTadPrioridade(fila,valordeentrada,prioridade);
				if(!certificacao){
					printf("a fila esta cheia\n");
				}
				break;
			case 2:
				valordesaida=retiraTad(fila);
				printf("valor: %s\n",valordesaida);
				break;
			case 3:
				imprime_fila(fila);
				break;
			case 4:
				break;
			default:
				printf("voce informou uma opcao invalida\n");
		}
		system("pause");
		system("cls");
	}while(opcao!=4);
	return 0;
}
