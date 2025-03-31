// Folha 3
// Exercício 9.2.2
#include <stdio.h>

void int3(int* numero) {
	int contador = 0;
	char letra;
	while (contador < 3) {
		letra = getchar();
		if (letra >= '0' && letra <= '9') {
			*numero *= 10;
			*numero += letra - '0';
			contador++;
		}
	}
}

int main() {
	int numero = 0;
	int3(&numero);
	printf("%d\n", numero);
	return 0;
}
