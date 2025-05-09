// Folha 1
// Exercício 5.1.3
#include <stdio.h>

#define TAMANHO 10

void inverter(const int vetor[], int vetorInvertido[]) {
	for (int i = 0; i < TAMANHO; i++) {
		vetorInvertido[i] = vetor[TAMANHO - 1 - i];
	}
}

void printVetor(int vetor[]) {
	for (int i = 0; i < TAMANHO; i++) {
		printf("Posição %d: %d\n", i, vetor[i]);
	}
}

void escreverVetor(int vetor[]) {
	for (int i = 0; i < TAMANHO; i++) {
		printf("Insire o número da posição %d: ", i);
		if (scanf("%d", &vetor[i]) != 1) {
			printf("Algo correu mal e o valor será -1");
			vetor[i] = -1;
		}
	}
}

int main() {
	int vetor[TAMANHO];
	int vetorInvertido[TAMANHO];
	escreverVetor(vetor);

	printf("O seu vetor:\n");
	printVetor(vetor);
	printf("O seu vetor invertido:\n");
	inverter(vetor, vetorInvertido);
	printVetor(vetorInvertido);

	return 0;
}
