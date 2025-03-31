// Folha 3
// Exercício 10.1.2
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int perguntarNumero(int min, int max) {
	int numero = min - 1;
	while (numero < min || numero > max) {
		if (scanf("%d", &numero) != 1) {
			printf("Algo correu mal e será usado número 2.\n");
			numero = 2;
			while (getchar() != '\n');
		}
	}
	return numero;
}

void definirMatriz(int** matriz, int tamanho) {
	for (int linha = 0; linha < tamanho; linha++) {
		for (int coluna = 0; coluna < tamanho; coluna++) {
			printf("Linha %d, coluna %d: ", linha + 1, coluna + 1);
			matriz[linha][coluna] = perguntarNumero(-2100000000, 2100000000);
		}
	}
}

void duplicarMatriz(int** matriz, int tamanho, int multiplicador) {
	for (int linha = 0; linha < tamanho; linha++) {
		for (int coluna = 0; coluna < tamanho; coluna++) {
			matriz[linha][coluna] *= multiplicador;
		}
	}
}

void printMatriz(int** matriz, int tamanho) {
	for (int linha = 0; linha < tamanho; linha++) {
		for (int coluna = 0; coluna < tamanho; coluna++) {
			printf("%5d ", matriz[linha][coluna]);
		}
		printf("\n");
	}
}

int main() {
	printf("Valor de N: ");
	int tamanho = perguntarNumero(1, 100);

	int** matriz = (int**)malloc(sizeof(int*) * tamanho);
	for (int i = 0; i < tamanho; i++) {
		matriz[i] = (int*)malloc(sizeof(int) * tamanho);
	}

	printf("Agora para definir os valores da matriz:\n");
	definirMatriz(matriz, tamanho);
	printf("Quanto quer multiplicar a matriz: ");
	int multiplicador = perguntarNumero(-2100000000, 2100000000);

	printf("Matriz inicial:\n");
	printMatriz(matriz, tamanho);
	duplicarMatriz(matriz, tamanho, multiplicador);
	printf("Matriz duplicada por %d:\n", multiplicador);
	printMatriz(matriz, tamanho);

	for (int i = 0; i < tamanho; i++) { free(matriz[i]); }
	free(matriz);
	return 0;
}
