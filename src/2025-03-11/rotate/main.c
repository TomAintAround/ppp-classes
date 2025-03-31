#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 5

void criarArray(int tamanho, int array[tamanho]) {
	for (int i = 0; i < tamanho; i++) { array[i] = rand() % 100; }
}

void rotate(int tamanho, int array[tamanho], int passos) {
	if (passos < 0) passos += tamanho;
	int novoArray[tamanho];
	for (int i = 0; i < tamanho; i++) {
		novoArray[(i + passos) % tamanho] = array[i];
	}
	for (int i = 0; i < tamanho; i++) { array[i] = novoArray[i]; }
}

void printArray(int tamanho, int array[tamanho]) {
	for (int i = 0; i < tamanho; i++) { printf("%2d ", array[i]); }
	printf("\n");
}

int main() {
	int array[TAMANHO];
	srand(time(NULL));
	criarArray(TAMANHO, array);
	printArray(TAMANHO, array);
	rotate(TAMANHO, array, -2);
	printArray(TAMANHO, array);

	return 0;
}
