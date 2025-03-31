// Folha 2
// Exercício 5.1.6
#include <stdio.h>

void printTabela(int linhas, int colunas, int tabela[][colunas]) {
	for (int linha = 0; linha < linhas; linha++) {
		for (int coluna = 0; coluna < colunas; coluna++) {
			printf("%5d ", tabela[linha][coluna]);
		}
		printf("\n");
	}
}

void construirTabela(int linhas, int colunas, int tabela[][colunas]) {
	for (int linha = 0; linha < linhas; linha++) {
		for (int coluna = 0; coluna < colunas; coluna++) {
			printf("Insire um número para a linha %d coluna %d: ", linha + 1,
				   coluna + 1);
			if (scanf("%d", &tabela[linha][coluna]) != 1) {
				printf("Algo correu mal e será definido como -1.");
				tabela[linha][coluna] = -1;
			}
		}
	}
}

int tamanhoTabela(char dimensao[]) {
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
	int linhas = tamanhoTabela("linhas");
	int colunas = tamanhoTabela("colunas");
	int tabela[linhas][colunas];

	construirTabela(linhas, colunas, tabela);
	printTabela(linhas, colunas, tabela);

	return 0;
}
