// Folha 2
// Exercício 5.1.7
#include <stdio.h>

void transporMatriz(int linhas, int colunas, int matrizTransposta[][linhas],
					int matriz[][colunas]) {
	int i = 0;
	int j = 0;
	for (int coluna = 0; coluna < colunas; coluna++) {
		for (int linha = 0; linha < linhas; linha++) {
			matrizTransposta[i][j] = matriz[linha][coluna];
			j++;
		}
		j = 0;
		i++;
	}
}

void printMatriz(int linhas, int colunas, int matriz[][colunas]) {
	for (int linha = 0; linha < linhas; linha++) {
		for (int coluna = 0; coluna < colunas; coluna++) {
			printf("%5d ", matriz[linha][coluna]);
		}
		printf("\n");
	}
}

void construirMatriz(int linhas, int colunas, int matriz[][colunas]) {
	for (int linha = 0; linha < linhas; linha++) {
		for (int coluna = 0; coluna < colunas; coluna++) {
			printf("Insire um número para a linha %d coluna %d: ", linha + 1,
				   coluna + 1);
			if (scanf("%d", &matriz[linha][coluna]) != 1) {
				printf("Algo correu mal e será definido como -1.");
				matriz[linha][coluna] = -1;
			}
		}
	}
}

int tamanhoMatriz(char dimensao[]) {
	int tamanho = 0;
	while (tamanho < 1 || tamanho > 20) {
		printf("Insire o número de %s: ", dimensao);
		if (scanf("%d", &tamanho) != 1) {
			printf("Algo correu mal e usarei 10 como predefinido.");
			tamanho = 10;
		}
	}
	return tamanho;
}

int main() {
	int linhas = tamanhoMatriz("linhas");
	int colunas = tamanhoMatriz("colunas");
	int matriz[linhas][colunas];
	int matrizTransposta[colunas][linhas];

	construirMatriz(linhas, colunas, matriz);
	printf("A sua matriz:\n");
	printMatriz(linhas, colunas, matriz);
	transporMatriz(linhas, colunas, matrizTransposta, matriz);
	printf("A sua matriz transposta:\n");
	printMatriz(colunas, linhas, matrizTransposta);

	return 0;
}
