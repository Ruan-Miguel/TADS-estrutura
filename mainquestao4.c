#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pilha.h"

int imprimirInverso(Pilha *pilha1,Pilha *pilha2){
	char vetoraux[2];
	int numcaracteres=0;
	while(!pilha_vazia(pilha1)){
		strcpy(vetoraux,pop(pilha1));
		push(pilha2,vetoraux);
		numcaracteres++;
		printf("%s",vetoraux);
	}
	return numcaracteres;
}

int palindromo(Pilha *pilha,int numcaracteres){
	Pilha *pilhaaux=criaPilha();
	int metade;
	metade=numcaracteres/2;
	while(metade!=0){
		push(pilhaaux,pop(pilha));
		metade--;
	}
	if(numcaracteres%2!=0){
		pop(pilha);
	}
	metade=numcaracteres/2;
	while(metade!=0){
		if(strcmp(pop(pilha),pop(pilhaaux))!=0){
			return 0;
		}
		metade--;
	}
	return 1;
}

int main(){
	Pilha *pilha1=criaPilha(),*pilha2=criaPilha();
	char letra,vetoraux[2];
	int numcaracteres=0;
	printf("informe uma \"string\",informar 0 para parar:");
	scanf("%c",&letra);
	while(letra!='0'){
		vetoraux[0]=letra;
		vetoraux[1]='\0';
		push(pilha1,vetoraux);
		fflush(stdin);
		scanf("%c",&letra);
	}
	printf("texto na ordem inversa:");
	numcaracteres=imprimirInverso(pilha1,pilha2);
	printf("\n");
	if(palindromo(pilha2,numcaracteres)){
		printf("essa \"string\" eh um palindromo");
	}else{
		printf("essa \"string\" nao eh um palindromo");
	}	
	return 0;
}
