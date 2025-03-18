// Folha 1
// Exercício 1.1.2
#include <stdio.h>

int main() {
	char nome[100];
	int idade;
	int peso;
	
	printf("O seu nome: ");
	if (scanf("%s", nome) != 1) {
		printf("\nAlgo correu mal");
		return -1;
	}
	printf("A sua idade: ");
	if (scanf("%d", &idade) != 1) {
		printf("\nAlgo correu mal");
		return -1;
	}
	printf("O seu peso: ");
	if (scanf("%d", &peso) != 1) {
		printf("\nAlgo correu mal");
		return -1;
	}

	printf("Chamo-me %s, tenho %d anos e peso %d Kg.\n", nome, idade, peso);
	return 0;
}