#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _Temperaturas {
	size_t tamanho;
	int* valores;
} Temperaturas;

Temperaturas* criaTemperaturas(size_t tamanho) {
	Temperaturas* temperatura = (Temperaturas*)malloc(sizeof(Temperaturas));
	if (temperatura == NULL) return NULL;

	temperatura->tamanho = tamanho;
	temperatura->valores = (int*)malloc(tamanho * sizeof(int));
	if (temperatura->valores == NULL) {
		free(temperatura);
		return NULL;
	}

	return temperatura;
}

void contaPosNegTemperaturas(Temperaturas* temperatura, size_t* positivos, size_t* negativos) {
	for (size_t i = 0; i < temperatura->tamanho; i++) {
		if (temperatura->valores[i] > 0) {
			(*positivos)++;
		} else if (temperatura->valores[i] < 0) {
			(*negativos)++;
		}
	}
}

void destroiTemperaturas(Temperaturas* temperatura) {
	free(temperatura->valores);
	free(temperatura);
}

int main() {
	srand(time(NULL));
	size_t tamanho = 1;
	printf("Insire o número de temperaturas: ");
	if (scanf("%zu", &tamanho) != 1) {
		perror("Tinha de inserir um número inteiro.\n");
		return 1;
	}
	Temperaturas* temperatura = criaTemperaturas(tamanho);
	if (temperatura == NULL) {
		perror("Erro a criar temperaturas\n");
		return 1;
	}

	for (size_t i = 0; i < tamanho; i++) {
		temperatura->valores[i] = (rand() % 60) - 30;
	}
	size_t positivos, negativos;
	contaPosNegTemperaturas(temperatura, &positivos, &negativos);
	printf("Número de medições positivas: %zu\n", positivos);
	printf("Número de medições negativas: %zu\n", negativos);
	destroiTemperaturas(temperatura);
	temperatura = NULL;

	return 0;
}
