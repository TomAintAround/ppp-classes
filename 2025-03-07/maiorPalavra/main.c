// Folha 3
// Exercício 9.2.1
#include <stdio.h>
#include <string.h>

#define TAMANHO_STRING 1024

char *maiorPalavra(char *string) {
	char *pPalavra = strtok(string, " ");
	char *palavraMaior = string;
	int comprimentoMax = 0;
	int comprimento = 0;
	while (pPalavra != NULL) {
		char *letra = pPalavra;
		while (*letra != '\0') {
			if (comprimentoMax < ++comprimento) {
				comprimentoMax = comprimento;
				palavraMaior = pPalavra;
			}
			letra++;
		}
		comprimento = 0;
		pPalavra = strtok(NULL, " ");
	}
	return palavraMaior;
}

int main() {
	char string[TAMANHO_STRING];
	printf("Insire a sua string:\n");
	if (fgets(string, TAMANHO_STRING, stdin) == NULL) {
		printf("Algo correu mal.");
		return -1;
	}
	printf("Maior palavra: %s", maiorPalavra(string));

	return 0;
}