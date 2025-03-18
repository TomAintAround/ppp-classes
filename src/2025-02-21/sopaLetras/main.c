// Folha 2
// Exercício 6.3.2
// This is full of bugs. I gave up
#include <stdio.h>
#include <math.h>
#include <string.h>

int perguntarTamanhos(char texto[]) {
	int resultado = 0;
	while (resultado <= 0 || resultado > 100) {
		printf("Insire o número de %s: ", texto);
		if (scanf("%d", &resultado) != 1) {
			printf("Algo correu mal. Tente de novo.\n");
			while (getchar() != '\n');
			return perguntarTamanhos(texto);
		}
	}
	while (getchar() != '\n');
	return resultado;
}

void construirSopa(int linhas, int colunas, char sopa[][colunas]) {
	for (int linha = 0; linha < linhas; linha++) {
		for (int coluna = 0; coluna < colunas; coluna++) {
			printf("Linha %d | Coluna %d: ", linha + 1, coluna + 1);
			if (scanf(" %c", &sopa[linha][coluna]) != 1) {
				printf("Algo correu mal e será usado 1.");
				while (getchar() != '\n');
				sopa[linha][coluna] = '1';
			}
		}
	}
	while (getchar() != '\n');
}

void printSopa(int linhas, int colunas, char sopa[][colunas]) {
	for (int linha = 0; linha < linhas; linha++) {
		for (int coluna = 0; coluna < colunas; coluna++) {
			printf("%2c ", sopa[linha][coluna]);
		}
		printf("\n");
	}
}

void procurarPalavra(int linhas, int colunas, char sopa[][colunas], char palavra[], int menor, int tamanho) {
	for (int linha = 0; linha < linhas; linha++) {
		for (int coluna = 0; coluna < colunas; coluna++) {
			int posicao = 0;
			while (sopa[linha][coluna] == palavra[posicao]) {
				posicao++;
				coluna++;
			}
			if (posicao >= tamanho) {
				printf("A palavra encontra-se na linha %d.\n", linha + 1);
				return;
			}
		}
		for (int coluna = colunas - 1; coluna >= 0; coluna--) {
			int posicao = 0;
			while (sopa[linha][coluna] == palavra[posicao]) {
				posicao++;
				coluna--;
			}
			if (posicao >= tamanho) {
				printf("A palavra encontra-se na linha %d.\n", linha + 1);
				return;
			}
		}
	}
	for (int coluna = 0; coluna < colunas; coluna++) {
		for (int linha = 0; linha < linhas; linha++) {
			int posicao = 0;
			while (sopa[linha][coluna] == palavra[posicao]) {
				posicao++;
				linha++;
			}
			if (posicao >= tamanho) {
				printf("A palavra encontra-se na coluna %d.\n", coluna + 1);
				return;
			}
		}
		for (int linha = linhas - 1; linha >= 0; linha--) {
			int posicao = 0;
			while (sopa[linha][coluna] == palavra[posicao]) {
				posicao++;
				linha--;
			}
			if (posicao >= tamanho) {
				printf("A palavra encontra-se na coluna %d.\n", coluna + 1);
				return;
			}
		}
	}
	for (int i = 0; i < menor; i++) {
		int posicao = 0;
		while (sopa[i][i] == palavra[posicao]) {
			posicao++;
			i++;
		}
		if (posicao >= tamanho) {
			printf("A palavra encontra-se na diagonal.\n");
			return;
		}
	}
	for (int i = menor - 1; i >= 0; i--) {
		int posicao = 0;
		while (sopa[i][i] == palavra[posicao]) {
			posicao++;
			i--;
		}
		if (posicao >= tamanho) {
			printf("A palavra encontra-se na diagonal.\n");
			return;
		}
	}
}

int main() {
	int linhas = perguntarTamanhos("linhas");
	int colunas = perguntarTamanhos("colunas");
	char sopa[linhas][colunas];
	construirSopa(linhas, colunas, sopa);
	printSopa(linhas, colunas, sopa);

	int menor = linhas < colunas ? linhas : colunas;
	char palavra[menor];
	printf("A palavra que está a procurar: ");
	if (fgets(palavra, menor, stdin) == NULL) {
		printf("Algo correu mal.\n");
		return -1;
	}
	int tamanho = strlen(palavra) - 1;

	procurarPalavra(linhas, colunas, sopa, palavra, menor, tamanho);

	return 0;
}
