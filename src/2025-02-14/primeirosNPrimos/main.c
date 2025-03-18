// Folha 2
// Exercício 5.1.5
#include <stdio.h>
#include <math.h>

void printPrimos(int primos[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		if (i == 0) {
			printf("%d", primos[i]);
		}
		else {
			printf(", %d", primos[i]);
		}
	}
	printf("\n");
}

void construirVetor(int primos[], int numero, int progresso, int tamanho) {
	for (int i = 1; i <= sqrt(numero); i++) {
		if (i == 1) {
			continue;
		}
		if (numero % i == 0) {
			construirVetor(primos, numero + 1, progresso, tamanho);
			return;
		}
	}
	primos[progresso] = numero;

	if (progresso == tamanho - 1) {
		return;
	}
	construirVetor(primos, numero + 1, progresso + 1, tamanho);
}

int perguntarTamanho() {
	int tamanho = 0;
	while (tamanho < 1 || tamanho > 1000) {
		printf("Insire a quantidade de números primos que quer ver: ");
		if (scanf("%d", &tamanho) != 1) {
			printf("Algo correu mal e o tamanho será 10.\n");
			tamanho = 10;
		}
	}
	return tamanho;
}

int main() {
	int tamanho = perguntarTamanho();
	int primos[tamanho];
	construirVetor(primos, 2, 0, tamanho);
	printPrimos(primos, tamanho);

	return 0;
}
