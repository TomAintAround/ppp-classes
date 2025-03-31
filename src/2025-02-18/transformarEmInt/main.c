// Folha 2
// Exercício 6.1.5
#include <math.h>
#include <stdio.h>
#include <string.h>

#define TAMANHO 100

int eInt(char string[]) {
	int i = 0;
	if (string[0] == '-') { i++; }
	for (; i < (int)strlen(string) - 1; i++) {
		if (string[i] < '0' || string[i] > '9') { return 0; }
	}
	return 1;
}

int transformarEmInteiro(char string[]) {
	int tamanhoString = strlen(string) - 1;
	int resultado = 0;
	int sinal = 1;
	int i = 0;
	if (string[0] == '-') {
		sinal = -1;
		i++;
	}

	for (; i < tamanhoString; i++) {
		resultado += (string[i] - '0') * pow(10, tamanhoString - i - 1);
	}
	return resultado * sinal;
}

int main() {
	char string[TAMANHO];
	printf("Insire um número inteiro (32 bits com sinal): ");
	if (fgets(string, TAMANHO, stdin) == NULL) {
		printf("Algo correu mal.\n");
		return -1;
	}
	if (eInt(string)) {
		printf("O número: %d\n", transformarEmInteiro(string));
	} else {
		printf("Foi introduzido um número inválido.");
	}

	return 0;
}
