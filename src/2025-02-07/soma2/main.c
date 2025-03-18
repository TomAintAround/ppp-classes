// Folha 1
// Exercício 3.1.2
#include <stdio.h>

int main() {
	int limite = 0;
	int soma = 0;

	printf("Insire o limite: ");
	if (scanf("%d", &limite) != 1) {
		printf("Algo correu mal");
		return -1;
	}

	int i = 1;
	while (soma <= limite) {
		soma += i;
		i++;
	}

	printf("Cheguei até %d", soma);
	return 0;
}
