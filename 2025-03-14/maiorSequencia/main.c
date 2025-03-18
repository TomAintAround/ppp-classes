// Folha 3
// Exercício 10.3.1
#include <stdio.h>
#include <stdlib.h>
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

	long numeroMaior = 0; long numero = 0;
	for (int i = 0; i <= MAX; i++) {
		if (string[i] >= '0' && string[i] <= '9') {
			numero *= 10;
			numero += string[i] - '0';
		}
		else numero = 0;
		if (numero > numeroMaior) numeroMaior = numero;
	}

	if (numeroMaior == 0) {
		printf("Não foi encontrado um inteiro.\n");
	}
	else {
		printf("Inteiro: %ld\n", numeroMaior);
	}

	free(string);
	return 0;
}