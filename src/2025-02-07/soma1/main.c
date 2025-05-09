// Folha 1
// Exercício 3.1.1
#include <stdio.h>

int main() {
	int limite = 0;
	long soma = 0;

	printf("Insire o limite da soma: ");
	if (scanf("%d", &limite) != 1) {
		printf("\nAlgo correu mal");
		return -1;
	}

	for (int i = 1; i <= limite; i++) soma += i;

	printf("%ld\n", soma);
	return 0;
}
