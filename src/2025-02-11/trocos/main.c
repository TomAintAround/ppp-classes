// Folha 1
// Exercício 1.2.1
#include <stdio.h>

int main() {
	double preco = -1;
	double dinheiro = -1;
	while (preco < 0.0 || preco >= 100.0 || dinheiro < 0.0 || dinheiro - preco < 0) {
		printf("Insire o preço: ");
		if (scanf("%le", &preco) != 1) {
			printf("Algo correu mal");
			return -1;
		}
		printf("Insire o dinheiro a dar: ");
		if (scanf("%le", &dinheiro) != 1) {
			printf("Algo correu mal");
			return -1;
		}
	}
	double troco = dinheiro - preco;
	printf("\nO troco é %.2f€\n", troco);

	if (troco > 0) {
		double dinheiros[15] = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
		int trocos[15] = {0};
		
		for (int i = 0; i < 15; i++) {
			trocos[i] = troco / dinheiros[i];
			troco -= dinheiros[i] * trocos[i];
			printf("Notas de %.2f€: %d\n", dinheiros[i], trocos[i]);
		}
	}
	else {
		printf("Não tenho nada para te dar.");
	}
	return 0;
}