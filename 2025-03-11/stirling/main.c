#include <stdio.h>

int stirling(int n, int k) {
	if (k == 0 || k > n) return 0;
	if (n == k) return 1;
	return k * stirling(n - 1, k) + stirling(n - 1, k - 1);
}

void stirling2(int m, int S[m + 1][m + 1]) {
	for (int n = 0; n <= m; n++) {
		for (int k = 0; k <= m; k++) {
			S[n][k] = stirling(n, k);
		}
	}
}

void printMatriz(int m, int S[m + 1][m + 1]) {
	for (int n = 0; n <= m; n++) {
		for (int k = 0; k <= m; k++) {
			printf("%5d ", S[n][k]);
		}
		printf("\n");
	}
}

int main() {
	int tamanho;
	printf("Insire o número de m: ");
	if (scanf("%d", &tamanho) != 1) {
		printf("Algo correu mal e será usado o número 5.\n");
		tamanho = 5;
		while (getchar() != '\n');
	}
	int matriz[tamanho + 1][tamanho + 1];
	stirling2(tamanho, matriz);
	printMatriz(tamanho, matriz);

	return 0;
}