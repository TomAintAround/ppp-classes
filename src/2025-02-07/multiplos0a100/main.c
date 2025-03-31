// Folha 1
// Exercício 3.1.4
#include <stdio.h>

#define LIMITE 100

int main() {
	int valor = -1;
	while (valor <= 0 || valor > LIMITE) {
		printf("Insire um valor entre 0 (exclusivé) e 100 (inclusivé): ");
		if (scanf("%d", &valor) != 1) {
			printf("Algo correu mal");
			return -1;
		}
	}

	int multiplos[LIMITE] = {0};
	int comprimentoMultiplos = sizeof(multiplos) / sizeof(int);
	int i = 0;
	int multiplo = valor;
	while (multiplo <= LIMITE) {
		multiplos[i] = multiplo;
		multiplo += valor;
		i++;
	}

	printf("Valores: ");
	for (int j = 0; j < comprimentoMultiplos; j++) {
		if (multiplos[j] == 0) { break; }
		printf("%d ", multiplos[j]);
	}
	return 0;
}
