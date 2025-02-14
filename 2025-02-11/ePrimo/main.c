// Folha 1
// Exeercício 4.2.4
#include <stdio.h>
#include <math.h>

int ePrimo(int numero) {
	for (int i = 2; i <= sqrt(numero); i++) {
		if (numero % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int numero = 0;
	while (numero < 2) {
		printf("Insire um número natural maior que 1: ");
		if (scanf("%d", &numero) != 1) {
			printf("Algo correu mal");
			return -1;
		}
	}

	if (ePrimo(numero)) {
		printf("É primo");
	}
	else {
		printf("Não é primo");
	}

	return 0;
}