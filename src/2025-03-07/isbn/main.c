// Folha 3
// Exercício 9.3.1
#include <stdio.h>
#include <string.h>
#include <math.h>

#define TAMANHO 10

int validoISBN(char *isbn) {
	int tamanhoReal = strlen(isbn) - 1; // -'\n'
	if (tamanhoReal < TAMANHO * 2 - 1) return 0;
	for (int i = 0; isbn[i] != '\n' && isbn[i] != '\0'; i += 2) {
		if (isbn[i + 1] != ' ' && i < tamanhoReal - 1) return 0;
		if (isbn[i] < '0' || isbn[i] > '9') return 0;
	}
	return 1;
}

void obterISBN(int *isbn) {
	int tamanho = TAMANHO * 2 + 1; // mais os espaços, mais o '\n' e mais o '\0'
	char isbnTexto[tamanho];
	printf("Inisire os dígitos do ISBN (separados por um espaço):\n");
	if (fgets(isbnTexto, tamanho, stdin) == NULL) {
		printf("Algo correu mal.\n");
		while (getchar() != '\n');
		obterISBN(isbn);
	}
	if (!validoISBN(isbnTexto)) {
		printf("ISBN completamente inválido.\n");
		obterISBN(isbn);
	}

	int contador = 0;
	for (int i = 0; i < tamanho - 2; i += 2) {
		isbn[contador++] = isbnTexto[i] - '0';
	}
}

void somaParcial(int *numeros, int *resultados) {
	int acumulador = 0;
	for (int i = 0; i < TAMANHO; i++) {
		acumulador += numeros[i];
		resultados[i] = acumulador;
	}
}

void printValores(int *numeros) {
	for (int i = 0; i < TAMANHO; i++) {
		printf("%d ", numeros[i]);
	}
	printf("\n");
}

int main() {
	int isbn[TAMANHO];
	int s1[TAMANHO];
	int s2[TAMANHO];
	obterISBN(isbn);
	somaParcial(isbn, s1);
	somaParcial(s1, s2);

	printf("Valores do ISBN: ");
	printValores(isbn);
	printf("Valores do s1: ");
	printValores(s1);
	printf("Valores do s2: ");
	printValores(s2);

	if (s2[TAMANHO - 1] % 11 == 0) {
		printf("O ISBN é correto, porque %d é divisível por 11.\n", s2[TAMANHO - 1]);
	}
	else {
		printf("O ISBN é incorreto, porque %d não é divisível por 11.\n", s2[TAMANHO - 1]);
	}

	return 0;
}