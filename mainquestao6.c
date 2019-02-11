#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pilha.h"

int nummovimentos=0;

Pilha *auxilio1,*auxilio2,*auxilio3;

void printestacas(){
	system("cls");
	printestaca(auxilio1);
	printf("\n\n");
	printestaca(auxilio2);
	printf("\n\n");
	printestaca(auxilio3);
	printf("\n\n");
	system("pause");
}

void criaTorre(Pilha *estaca,int numdiscos){
	char vetoraux[2];
	while(numdiscos>0){
		vetoraux[0]=(char)(numdiscos+48);
		vetoraux[1]='\0';
		push(estaca,vetoraux);
		numdiscos--;
	}
}

void empilhar(Pilha *estaca1,Pilha *estaca2,Pilha *estaca3,int numdiscos){
	void desempilhar(Pilha *estaca1,Pilha *estaca2,Pilha *estaca3,int numdiscos);
	push(estaca3,pop(estaca1));
	printestacas();
	nummovimentos++;
	desempilhar(estaca2,estaca1,estaca3,numdiscos-1);
}

void desempilhar(Pilha *estaca1,Pilha *estaca2,Pilha *estaca3,int numdiscos){
	int cont;
	if(numdiscos==1){//caso 1
		printf("1\n");
		push(estaca3,pop(estaca1));
		printestacas();
		nummovimentos++;
	}else{//caso 2
		if(numdiscos%2==0){//caso 2.1
			printf("2.1\n");
			push(estaca2,pop(estaca1));
			printestacas();
			cont=0;
			nummovimentos++;
		}else{//caso 2.2
			printf("2.2\n");
			push(estaca3,pop(estaca1));
			printestacas();
			cont=1;
			nummovimentos++;
		}
		while(chartoint(primeiroDaPilha(estaca1))!=numdiscos || (!pilha_vazia(estaca3))){
			if((!pilha_vazia(estaca1)) && (!pilha_vazia(estaca3))){
				if(chartoint(primeiroDaPilha(estaca1))-chartoint(primeiroDaPilha(estaca3))==-1){
					break;
				}
			}
			if(cont==0){//caso 3
				if(pilha_vazia(estaca3)){//caso 3.1
					printf("3.1\n");
					push(estaca3,pop(estaca1));
					printestacas();
					nummovimentos++;
					cont=1;
				}else if(chartoint(primeiroDaPilha(estaca1))<chartoint(primeiroDaPilha(estaca3))){//caso 3
					printf("3.2\n");
					push(estaca3,pop(estaca1));
					printestacas();
					nummovimentos++;
					cont=1;
				}else{//caso 3.3
					printf("3.3\n");
					desempilhar(estaca3,estaca1,estaca2,numerodequebra(estaca3));
				}
			}else{//caso 4
				if(pilha_vazia(estaca2)){//caso 4.1
					printf("4.1\n");
					push(estaca2,pop(estaca1));
					printestacas();
					nummovimentos++;
					cont=0;
				}else if(chartoint(primeiroDaPilha(estaca1))<chartoint(primeiroDaPilha(estaca2))){//caso 4.2
					printf("4.2\n");
					push(estaca2,pop(estaca1));
					printestacas();
					nummovimentos++;
					cont=0;
				}else{//caso 4.3
					printf("4.3\n");
					desempilhar(estaca2,estaca1,estaca3,numerodequebra(estaca2));
				}
			}
			//system("pause");
		}
		//caso 5
		printf("5\n");
		empilhar(estaca1,estaca2,estaca3,numdiscos);
	}
}

int main(){
	Pilha *estaca1=criaPilha(),*estaca2=criaPilha(),*estaca3=criaPilha();
	auxilio1=estaca1;
	auxilio2=estaca2;
	auxilio3=estaca3;
	int numdiscos;
	printf("informe o numero de discos(de 1 a 9):");
	scanf("%d",&numdiscos);
	criaTorre(estaca1,numdiscos);
	printestacas();
	desempilhar(estaca1,estaca2,estaca3,numdiscos);
	printf("nummovimentos: %d",nummovimentos);
	return 0;
}
