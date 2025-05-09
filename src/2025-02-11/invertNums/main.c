// Folha 1
// Exercício 4.2.6
#include <stdio.h>

int inverte(int numero) {
	int valor = 0;
	while (numero > 0) {
		valor *= 10;
		valor += numero % 10;
		numero /= 10;
	}
	return valor;
}

int main() {
	int numero = -1;
	while (numero < 0) {
		printf("Insire um número inteiro maior que 0: ");
		if (scanf("%d", &numero) != 1) {
			printf("Algo correu mal");
			return -1;
		}
	}

	int numeroInvertido = inverte(numero);
	printf("O número invertido de %d é %d.\n", numero, numeroInvertido);
	if (numeroInvertido == numero) { printf("É uma capicua.\n"); }

	return 0;
}
