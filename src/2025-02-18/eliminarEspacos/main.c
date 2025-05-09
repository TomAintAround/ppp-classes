// Folha 2
// Exercício 6.1.8
#include <stdio.h>

#define TAMANHO 200

void eliminarEspacos(const char frase[TAMANHO], char fraseSemEspacos[TAMANHO]) {
	int progresso = 0;
	for (int i = 0; i < TAMANHO; i++) {
		if (frase[i] != ' ' && frase[i] != '\t') {
			fraseSemEspacos[progresso] = frase[i];
			progresso++;
		}
	}
	fraseSemEspacos[progresso] = '\0';
}

int main() {
	char frase[TAMANHO];
	char fraseSemEspacos[TAMANHO];
	printf("Insire a sua frase: ");
	if (fgets(frase, TAMANHO, stdin) == NULL) {
		printf("Algo correu mal.\n");
		return -1;
	}
	eliminarEspacos(frase, fraseSemEspacos);
	printf("A sua frase sem espaços em branco:\n%s\n", fraseSemEspacos);

	return 0;
}
