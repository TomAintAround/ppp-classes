// Folha 5
// Exercício 14.2.4
#include <stdio.h>
#include <stdlib.h>

void erro(char* mensagemErro) {
	perror(mensagemErro);
	exit(1);
}

size_t numeroLinhas(FILE* inteirosFicheiro) {
	fseek(inteirosFicheiro, 0, SEEK_SET);
	size_t numeroDeLinhas = 0;
	char character;
	do {
		character = fgetc(inteirosFicheiro);
		if (character == '\n') numeroDeLinhas++;
	} while (character != EOF);
	fseek(inteirosFicheiro, 0, SEEK_SET);
	return numeroDeLinhas;
}

void armazenarInteiros(FILE* inteirosFicheiro, int* inteiros, size_t tamanho) {
	size_t i = 0;
	while (i < tamanho) {
		if (fscanf(inteirosFicheiro, "%d", &inteiros[i++]) != 1) {
			erro("O ficheiro apenas pode conter inteiros.\n");
		}
	}
}

void escreverResultado(FILE* resultado, int* inteiros, size_t tamanho,
					   int* maiorNumero, int* menorNumero) {
	fprintf(resultado, "Números lidos: ");
	for (size_t i = 0; i < tamanho; i++) {
		if (*maiorNumero < inteiros[i]) *maiorNumero = inteiros[i];
		if (*menorNumero > inteiros[i]) *menorNumero = inteiros[i];
		fprintf(resultado, "%d ", inteiros[i]);
	}
	fprintf(resultado, "\n");
	fprintf(resultado, "Maior número: %d\n", *maiorNumero);
	fprintf(resultado, "Menor número: %d\n", *menorNumero);
}

void diferenca(const int* maiorNumero, const int* menorNumero) {
	printf("Diferença entre maior e menor números: %d.\n", *maiorNumero - *menorNumero);
}

double calcularMedia(const int* inteiros, size_t tamanho) {
	double media = 0;
	for (size_t i = 0; i < tamanho; i++) media += inteiros[i];
	return media / tamanho;
}

void armazenarAcimaMedia(FILE* acimaMedia, int* inteiros, size_t tamanho, double media) {
	for (size_t i = 0; i < tamanho; i++) {
		if (inteiros[i] > media) fprintf(acimaMedia, "%d\n", inteiros[i]);
	}
}

int main() {
	FILE* inteirosFicheiro = fopen("./inteiros.txt", "r");
	FILE* resultado = fopen("./resultado.txt", "w");
	FILE* acimaMedia = fopen("./acimaMedia.txt", "w");
	if (inteirosFicheiro == NULL) {
		erro("O ficheiro \"inteiros.txt\" não foi lido.\n");
	}
	if (resultado == NULL) erro("O ficheiro \"resultado.txt\" não foi lido.\n");
	if (acimaMedia == NULL) {
		erro("O ficheiro \"acimaMedia.txt\" não foi lido.\n");
	}

	size_t numeroDeLinhas = numeroLinhas(inteirosFicheiro);
	int inteiros[numeroDeLinhas];
	armazenarInteiros(inteirosFicheiro, inteiros, numeroDeLinhas);
	int maiorNumero = inteiros[0];
	int menorNumero = inteiros[0];
	escreverResultado(resultado, inteiros, numeroDeLinhas, &maiorNumero, &menorNumero);
	diferenca(&maiorNumero, &menorNumero);
	double media = calcularMedia(inteiros, numeroDeLinhas);
	armazenarAcimaMedia(acimaMedia, inteiros, numeroDeLinhas, media);

	fclose(inteirosFicheiro);
	fclose(resultado);
	fclose(acimaMedia);
	return 0;
}
