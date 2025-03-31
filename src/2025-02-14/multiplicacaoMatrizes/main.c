// Folha 2
// Exercício 5.2.5
#include <stdio.h>

int perguntar(char linhasOuColunas[], int matriz) {
	int resultado = 0;
	while (resultado < 1 || resultado > 100) {
		printf("Quantas %s quer que a matriz %d tenha: ", linhasOuColunas,
			   matriz);
		if (scanf("%d", &resultado) != 1) {
			printf("Algo correu mal e será usado o valor 3.\n");
			resultado = 3;
		}
	}
	return resultado;
}

void definirMatriz(int linhas, int colunas, int matriz[][colunas],
				   int numeroMatriz) {
	printf("Matriz %d:\n", numeroMatriz);
	for (int linha = 0; linha < linhas; linha++) {
		for (int coluna = 0; coluna < colunas; coluna++) {
			printf("Valor da linha %d, coluna %d: ", linha + 1, coluna + 1);
			if (scanf("%d", &matriz[linha][coluna]) != 1) {
				printf("Algo correu mal e o valor será -1.\n");
				matriz[linha][coluna] = -1;
			}
		}
	}
	printf("\n");
}

void printMatriz(int linhas, int colunas, int matriz[][colunas],
				 char qualMatriz[]) {
	printf("Matriz %s:\n", qualMatriz);
	for (int linha = 0; linha < linhas; linha++) {
		for (int coluna = 0; coluna < colunas; coluna++) {
			printf("%4d ", matriz[linha][coluna]);
		}
		printf("\n");
	}
	printf("\n");
}

int definirValor(int linha1, int coluna2, int colunas1, int colunas2,
				 int matriz1[][colunas1], int matriz2[][colunas2]) {
	int resultado = 0;
	for (int i = 0; i < colunas1; i++) {
		resultado += matriz1[linha1][i] * matriz2[i][coluna2];
	}
	return resultado;
}

void multiplicar(int linhas1, int colunas1, int colunas2,
				 int matriz1[][colunas1], int matriz2[][colunas2],
				 int resultado[][colunas2]) {
	for (int linha = 0; linha < linhas1; linha++) {
		for (int coluna = 0; coluna < colunas2; coluna++) {
			resultado[linha][coluna] = definirValor(linha, coluna, colunas1,
													colunas2, matriz1, matriz2);
		}
	}
}

int main() {
	int linhas1 = perguntar("linhas", 1);
	int colunas1 = perguntar("colunas", 1);
	printf("Então matriz 2 terá %d linhas.\n", colunas1);
	int linhas2 = colunas1;
	int colunas2 = perguntar("linhas", 2);
	int matriz1[linhas1][colunas1];
	int matriz2[linhas2][colunas2];
	int resultado[linhas1][colunas2];

	definirMatriz(linhas1, colunas1, matriz1, 1);
	definirMatriz(linhas2, colunas2, matriz2, 2);
	printMatriz(linhas1, colunas1, matriz1, "1");
	printMatriz(linhas2, colunas2, matriz2, "2");
	multiplicar(linhas1, colunas1, colunas2, matriz1, matriz2, resultado);
	printMatriz(linhas1, colunas2, resultado, "resultado");

	return 0;
}
