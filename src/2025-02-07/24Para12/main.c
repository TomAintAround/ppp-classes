// Folha 1
// Exercício 2.2.2
#include <stdio.h>

int main() {
	int hora = -1;
	int minuto = -1;

	while (hora < 0 || hora > 23 || minuto < 0 || hora > 59) {
		printf("Insire a hora: ");
		if (scanf("%d", &hora) != 1) {
			printf("Algo de errado aconteceu");
			return -1;
		}
		printf("Insire o minuto: ");
		if (scanf("%d", &minuto) != 1) {
			printf("Algo de errado aconteceu");
			return -1;
		}
	}

	if (hora > 12) {
		hora -= 12;
		printf("%d:%d pm\n", hora, minuto);
	} else {
		printf("%d:%d am\n", hora, minuto);
	}

	return 0;
}
