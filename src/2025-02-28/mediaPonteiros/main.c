// Folha 3
// Exercício 8.1.2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 12

void definirVetor(int *vetor) {
	srand(time(NULL)); // Necessário para aleatoriedade
	int *pFinal = vetor + TAMANHO_VETOR - 1;
	for (int *p = vetor; p <= pFinal; p++) {
		*p = rand() % 100;
	}
}

void printVetor(int *vetor) {
	int *pFinal = vetor + TAMANHO_VETOR - 1;
	for (int *p = vetor; p < pFinal; p++) {
		printf("%d\n", *p);
	}
	printf("\n");
}

double media(int *vetor) {
	double resultado = 0.0;
	double *pResultado = &resultado;
	int *pFinal = vetor + TAMANHO_VETOR - 1;
	for (int *p = vetor; p < pFinal; p++) {
		*pResultado += *p;
	}
	return *pResultado / TAMANHO_VETOR;
}

int main() {
	int vetor[TAMANHO_VETOR];
	int *pVetor = &vetor[0];
	definirVetor(pVetor);
	printVetor(pVetor);
	printf("A média é: %.2f\n", media(pVetor));

	return 0;
}