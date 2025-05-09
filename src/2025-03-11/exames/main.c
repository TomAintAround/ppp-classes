#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO 10

typedef struct {
	char nome[81];
	char epoca[13];
	int nota; // 0 - 20, -1 se desistiu ou -2 se faltou
} Exame;

void construirClassificacoes(int tamanho, Exame classificacoes[tamanho]) {
	strcpy(classificacoes[0].nome, "Tomás");
	strcpy(classificacoes[1].nome, "João");
	strcpy(classificacoes[2].nome, "Guilherme");
	strcpy(classificacoes[3].nome, "Henrique");
	strcpy(classificacoes[4].nome, "Gonçalo");
	strcpy(classificacoes[5].nome, "Gabriel");
	strcpy(classificacoes[6].nome, "Afonso");
	strcpy(classificacoes[7].nome, "Diogo");
	strcpy(classificacoes[8].nome, "André");
	strcpy(classificacoes[9].nome, "Pedro");

	for (int i = 0; i < tamanho; i++) {
		int epoca = rand() % 3;
		switch (epoca) {
			case 0: strcpy(classificacoes[i].epoca, "normal"); break;
			case 1: strcpy(classificacoes[i].epoca, "recurso"); break;
			case 2: strcpy(classificacoes[i].epoca, "especial"); break;
		}

		classificacoes[i].nota = rand() % 23 - 2;
	}
}

void printClassificacoes(int tamanho, Exame classificacoes[tamanho]) {
	for (int i = 0; i < tamanho; i++) {
		printf("Nome: %s, época: %s, classificação: %d ", classificacoes[i].nome,
			   classificacoes[i].epoca, classificacoes[i].nota);
		if (classificacoes[i].nota == -1) printf("(Desistiu)");
		if (classificacoes[i].nota == -2) printf("(Faltou)");
		printf("\n");
	}
}

void frequenciasAbsolutas(int tamanho, Exame classificacoes[tamanho],
						  int notas[], char epoca[]) {
	for (int i = 0; i < 11; i++) { notas[i] = 0; }
	for (int i = 0; i < tamanho; i++) {
		if (strcmp(classificacoes[i].epoca, epoca) != 0) continue;
		if (classificacoes[i].nota < 10) continue;
		notas[classificacoes[i].nota - 10]++;
	}
}

void printNotas(int notas[11], char epoca[13]) {
	printf("\nNotas da época %s:\n", epoca);
	for (int i = 0; i < 11; i++) { printf("%d: %d\n", i + 10, notas[i]); }
}

int main() {
	srand(time(NULL));
	Exame classificacoes[TAMANHO];
	int notas[11];
	construirClassificacoes(TAMANHO, classificacoes);
	printClassificacoes(TAMANHO, classificacoes);

	int epoca = rand() % 3;
	char epocaTexto[13];
	switch (epoca) {
		case 0: strcpy(epocaTexto, "normal"); break;
		case 1: strcpy(epocaTexto, "recurso"); break;
		case 2: strcpy(epocaTexto, "especial"); break;
	}
	frequenciasAbsolutas(TAMANHO, classificacoes, notas, epocaTexto);
	printNotas(notas, epocaTexto);

	return 0;
}
