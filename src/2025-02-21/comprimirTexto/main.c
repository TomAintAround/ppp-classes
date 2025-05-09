// Folha 2
// Exercício 6.2.2
#include <stdio.h>

#define TAMANHO 2000

void comprimirTexto(const char texto[], char resultado[]) {
	int lugar = 0;
	int contador;
	for (int i = 0; texto[i] != '\n'; i++) {
		contador = 1;
		while (texto[i] == texto[i + 1]) {
			contador++;
			i++;
		}

		if (contador >= 4) {
			resultado[lugar++] = 'c';
			resultado[lugar++] = texto[i];
			char repeticoes[100];
			snprintf(repeticoes, 100, "%df", contador);
			for (int posicao = 0; repeticoes[posicao] != '\0'; posicao++) {
				resultado[lugar++] = repeticoes[posicao];
			}
		} else {
			for (int _ = 0; _ < contador; _++) {
				resultado[lugar++] = texto[i];
			}
		}
	}
	resultado[lugar] = '\0';
}

int main() {
	char texto[TAMANHO], resultado[TAMANHO];
	printf("Insire o texto:\n");
	if (fgets(texto, TAMANHO, stdin) == NULL) {
		printf("Algo correu mal.\n");
		while (getchar() != '\n');
		main();
	}
	comprimirTexto(texto, resultado);
	printf("Texto original: %s\nTexto comprimido: %s", texto, resultado);

	return 0;
}
