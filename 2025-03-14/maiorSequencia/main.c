// Folha 3
// Exercício 10.3.1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int eNumero(char letra) {
	return letra >= '0' && letra <= '9';
}

int main() {
	char* string = (char*)malloc((MAX + 1) * sizeof(char));
	printf("Insire a sua frase:\n");
	if (fgets(string, MAX + 1, stdin) == NULL) {
		printf("Algo correu mal.\n");
		return -1;
	}

	int maiorSequencia = 0, sequencia = 0;
	int maiorNumeroInicial = 0, numeroInicial = 0;
	int maiorNumeroFinal = 0, numeroFinal = 0;
	for (int i = 0; i < (int)strlen(string); i++) {
		if (eNumero(string[i])) {
			sequencia++;
			numeroFinal = i;
			if (i > 0 && !eNumero(string[i - 1])) {
				numeroInicial = i;
			}
		}
		if (sequencia > maiorSequencia) {
			maiorSequencia = sequencia;
			maiorNumeroInicial = numeroInicial;
			maiorNumeroFinal = numeroFinal;
		}
		if (!eNumero(string[i]) && sequencia > 0) sequencia = 0;
	}

	if (maiorSequencia > 0) {
		long numero = 0;
		for (int i = maiorNumeroInicial; i <= maiorNumeroFinal; i++) {
			numero *= 10;
			numero += string[i] - '0';
		}
		printf("Inteiro: %ld\n", numero);
	}
	else printf("Não foi introduzido um inteiro.\n");

	free(string);
	return 0;
}