// Folha 1
// Exercício 2.2.1
#include <stdio.h>

int main() {
	int idade = -1;
	while (idade < 0) {
		printf("Insire a sua idade: ");
		if (scanf("%d", &idade) != 1) {
			printf("Algo correu mal");
			return -1;
		}
	}

	if (idade >= 13 && idade <= 24) {
		printf("O seu bilhete é o bilhete radical");
	}
	else if ((idade >= 25 && idade <= 36) || (idade >= 49 && idade <= 60)) {
		printf("O seu bilhete é o bilhete light");
	}
	else if (idade >= 37 && idade <= 48) {
		printf("O seu bilhete é o bilhete normal");
	}
	else {
		printf("Está isente de pagamento");
	}

	return 0;
}