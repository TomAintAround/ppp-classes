// Folha 1
// Exercício 4.2.2
#include <stdio.h>

unsigned long permutacao(int n, int k) {
	if (k <= 1) {
		return n;
	}
	return n * permutacao(n - 1, k - 1);
}

int main() {
	int n = -1;
	int k = -1;
	while (n < 0 || k < 0 || n < k) {
		printf("Insire o valor de n: ");
		if (scanf("%d", &n) != 1) {
			printf("Algo correu mal");
			return -1;
		}
		printf("Insire o valor de k: ");
		if (scanf("%d", &k) != 1) {
			printf("Algo correu mal");
			return -1;
		}
	}

	printf("A permutação de %d em %d é %lu.", n, k, permutacao(n, k));

	return 0;
}