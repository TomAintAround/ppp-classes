// Folha 2
// Exercício 6.1.1
#include <stdio.h>

#define TAMANHO 100

int main() {
	char string[TAMANHO];
	printf("Insire uma frase: ");
	if (fgets(string, TAMANHO, stdin) == NULL) {
		printf("Algo correu mal\n");
		return -1;
	}

	int i;
	for (i = 0; string[i] != '\0' && string[i] != '\n'; i++) {}
	printf("O tamanho é %d.\n", i);

	return 0;
}
