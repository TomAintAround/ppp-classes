// Folha 2
// Exercício 5.1.8
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void distancias(int colunas, int tabela[][colunas]) {
	while (true) {
		int cidade1 = 0;
		int cidade2 = 0;

		printf("Selecione 2 cidades para obter a distância entre elas.\nSe quiser sair, escreva qualquer letra.\n> ");
		if (scanf("%d", &cidade1) != 1) {
			break;
		}
		printf("> ");
		if (scanf("%d", &cidade2) != 1) {
			break;
		}

		if (cidade1 < 1 || cidade2 < 1 || cidade1 > 5 || cidade2 > 5) {
			continue;
		}

		printf("A distância entre a cidade %d e a %d é: %d\n\n", cidade1, cidade2, tabela[cidade1 - 1][cidade2 - 1]);
	}
}

void construirTabela(int linhas, int colunas, int tabela[][colunas]) {
	for (int linha = 0; linha < linhas; linha++) {
		for (int coluna = 0; coluna < colunas; coluna++) {
			if (linha == coluna) {
				tabela[linha][coluna] = 0;
			}
			else {
				tabela[linha][coluna] = (abs(linha - coluna) + 1) * 10;
			}
		}
	}
}

int main() {
	int distanciaCidades[5][5];
	construirTabela(5, 5, distanciaCidades);
	distancias(5, distanciaCidades);

	return 0;
}