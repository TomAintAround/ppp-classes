// Folha 3
// Exercício 10.2.1
#include <stdio.h>
#include <string.h>
#include "main.h"

int lerConsola(char string[]) {
	printf("Insire a sua frase:\n");
	if (fgets(string, TAMANHO, stdin) == NULL) {
		printf("Algo correu mal.\n");
		return -1;
	}
	return 0;
}

int encontrarExpressao(int tamanhoString, char string[], int tamanhoExpressao, char expressao[]) {
	int progresso = 0;
	for (int i = 0; i < tamanhoString; i++) {
		if (progresso == tamanhoExpressao - 1) return i - progresso;
		if (string[i] == expressao[progresso]) progresso++;
		else if (string[i] != expressao[progresso && progresso > 0]) {
			i -= progresso;
			progresso = 0;
		}
	}
	return -1;
}

int main() {
	char string[TAMANHO];
	lerConsola(string);
	int posicaoWally = encontrarExpressao(TAMANHO, string, strlen("Wally"), "Wally");

	if (posicaoWally == -1) printf("Palavra não encontrada.\n");
	else printf("Esta cadeia tem a palavra Wally na posição %d.\n", posicaoWally);
	
	return 0;
}