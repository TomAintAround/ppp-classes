// Folha 2
// Exercício 6.1.6
#include <stdio.h>

#define TAMANHO 62 // 60 + \n + \0

int numeroPalavras(char frase[]) {
	int contador = 0;
	for (int i = 0; i < TAMANHO; i++) {
		if (frase[i] == ' ') contador++;
	}
	return contador + 1;
}

int main() {
	char frase[TAMANHO];
	printf("Insire a sua frase (máximo 60 caracteres):\n");
	if (fgets(frase, TAMANHO, stdin) == NULL) {
		printf("Algo correu mal.\n");
		return -1;
	}
	printf("A frase tem %d palavras.\n", numeroPalavras(frase));

	return 0;
}
