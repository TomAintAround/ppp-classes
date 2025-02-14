#include <stdio.h>

unsigned long factorial(int numero) {
	if (numero <= 0) {
		return 1;
	}
	return numero * factorial(numero - 1);
}

int main() {
	int numero;

	printf("Insire um número natural ou 0: ");
	if (scanf("%d", &numero) != 1) {
		printf("Algo correu mal");
		return -1;
	}

	printf("O factorial de %d é %lu.", numero, factorial(numero));

	return 0;
}