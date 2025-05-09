// Folha 1
// Exercício 3.2.2
#include <stdio.h>

int mdc(int numero1, int numero2) {
	int resto = numero1 % numero2;

	if (resto == 0) return numero2;

	return mdc(numero2, resto);
}

int main() {
	int numero1 = 0;
	int numero2 = 1;

	printf("Vai ter de inserir 2 números, sendo 1 primeiro maior ou igual que "
		   "o segundo.\n");
	while (numero1 < numero2) {
		printf("Insire o primeiro número número: ");
		if (scanf("%d", &numero1) != 1) {
			printf("Algo correu mal");
			return -1;
		}
		printf("Insire o segundo número número: ");
		if (scanf("%d", &numero2) != 1) {
			printf("Algo correu mal");
			return -1;
		}
	}

	int resultado = mdc(numero1, numero2);
	printf("mdc(%d,%d) = %d", numero1, numero2, resultado);

	return 0;
}
