#include <stdio.h>
#include <string.h>

#define TAMANHO 1024

int contarNumeros(char *string) {
	int contadorPrincipal = 0;
	char *pPalavra = strtok(string, " ");
	while (pPalavra != NULL) {
		int contador = 0;
		char *letra = pPalavra;
		while (*letra != '\0' && *letra != '\n') {
			if (*letra >= '0' && *letra <= '9') {
				contador *= 10;
				contador += *letra - '0';
			}
			else contador = 0;
			letra++;
		}
		contadorPrincipal += contador;
		pPalavra = strtok(NULL, " ");
	}
	return contadorPrincipal;
}

int main() {
	char string[TAMANHO];
	printf("Insire a sua string:\n");
	if (fgets(string, TAMANHO, stdin) == NULL) {
		printf("Algo correu mesmo muito mal.\n");
		while (getchar() != '\n');
		return -1;
	}
	printf("O resultado é: %d\n", contarNumeros(string));

	return 0;
}