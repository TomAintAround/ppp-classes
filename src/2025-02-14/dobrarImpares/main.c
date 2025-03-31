// Folha 2
// Exercício 5.1.1
#include <stdio.h>

void dobrar(int array[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		array[i] = array[i] % 2 ? array[i] * 2 : array[i];
	}
}

void printArray(int array[], int tamanho) {
	for (int i = 0; i < tamanho; i++) { printf("%d: %d\n", i, array[i]); }
}

void construirArray(int array[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		printf("Insire o número da posição %d: ", i);
		if (scanf("%d", &array[i]) != 1) {
			printf("Algo correu mal e o valor será -1\n");
			array[i] = -1;
		}
	}
}

int definirTamanho() {
	int tamanho = 0;
	while (tamanho < 1 || tamanho > 20) {
		printf("Insire o tamanho do array de inteiros: ");
		if (scanf("%d", &tamanho) != 1) {
			printf("Algo correu mal e o tamanho será 10\n");
			tamanho = 10;
		}
	}
	return tamanho;
}

int main() {
	int tamanho = definirTamanho();
	int array[tamanho];
	construirArray(array, tamanho);

	printf("Array original:\n");
	printArray(array, tamanho);
	dobrar(array, tamanho);
	printf("Array com os números ímpares dobrados:\n");
	printArray(array, tamanho);

	return 0;
}
