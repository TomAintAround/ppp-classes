// Folha 5
// Exercício 14.1.1
#include <stdio.h>
#include <string.h>

#define LINE_SIZE 256

int main() {
	FILE* file = fopen("./file.txt", "r");
	if (file == NULL) {
		perror("O ficheiro não foi lido.\n");
		return 1;
	}
	char linhaAtual[LINE_SIZE];
	char linhaMaisLonga[LINE_SIZE] = "";
	int numeroLinha = 0, numeroLinhaMaisLonga = 0;
	while (fgets(linhaAtual, LINE_SIZE, file)) {
		numeroLinha++;
		if (strlen(linhaAtual) > strlen(linhaMaisLonga)) {
			strcpy(linhaMaisLonga, linhaAtual);
			numeroLinhaMaisLonga = numeroLinha;
		}
	}
	fprintf(stdout, "%d: %s", numeroLinhaMaisLonga, linhaMaisLonga);

	fclose(file);
	return 0;
}
