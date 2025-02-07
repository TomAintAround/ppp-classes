#include <stdio.h>

int main() {
	int idade;
	int peso;
	
	printf("A sua idade: ");
	if (scanf("%d", &idade) != 1) {
		printf("Algo correu mal");
	}
	printf("O seu peso: ");
	if (scanf("%d", &peso) != 1) {
		printf("Algo correu mal");
	}

	printf("Chamo-me Tomás, tenho %d anos e peso %d Kg.\n", idade, peso);
	return 0;
}