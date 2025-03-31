// Folha 2
// Exercício 6.1.3
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define TAMANHO 100

int main() {
	char stringA[TAMANHO];
	char stringB[TAMANHO];
	printf("Insire a frase A: ");
	if (fgets(stringA, TAMANHO, stdin) == NULL) {
		printf("Algo correu mal.");
		return -1;
	}
	printf("Insire a frase B: ");
	if (fgets(stringB, TAMANHO, stdin) == NULL) {
		printf("Algo correu mal.");
		return -1;
	}

	int tamanhoA = strlen(stringA) - 1; // Não conta com \n
	int tamanhoB = strlen(stringB) - 1;
	int progresso = 0, contador = 0;
	bool bContidoA = false;
	for (int i = 0; i < tamanhoA; i++) {
		contador += 1;

		if (stringA[i] != stringB[i - progresso]) {
			i = progresso;
			progresso += 1;
			contador = 0;
			continue;
		} else if (tamanhoB == contador) {
			bContidoA = true;
			break;
		}
	}

	if (bContidoA) {
		printf("A frase B está contida em A.\n");
	} else {
		printf("A frase B não está contida em A.\n");
	}

	return 0;
}
