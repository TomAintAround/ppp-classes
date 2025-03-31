// Folha 1
// Exercício 5.2.1
#include <stdbool.h>
#include <stdio.h>

int perguntar(int min, int max, char pergunta[]) {
	int valor = min - 1;
	while (valor < min || valor > max) {
		printf("%s", pergunta);
		if (scanf("%d", &valor) != 1) { printf("Algo correu mal.\n"); }
	}
	return valor;
}

void introduzirValores(int sequencia[], int tamanho) {
	printf("Introduza os números:\n");
	for (int i = 0; i < tamanho; i++) {
		sequencia[i] = perguntar(-2100000000, 2100000000, "> ");
	}
}

void printValores(int sequencia[], int tamanho) {
	printf("Aqui tem a sua sequência:\n");
	for (int i = 0; i < tamanho; i++) { printf("%d ", sequencia[i]); }
	printf("\n");
}

int procurarMenorOuMaior(int sequencia[], int tamanho, bool maior) {
	int valor = sequencia[0];
	for (int i = 0; i < tamanho; i++) {
		if ((sequencia[i] < valor && !maior) ||
			(sequencia[i] > valor && maior)) {
			valor = sequencia[i];
		}
	}
	return valor;
}

int calcularSomatorio(int sequencia[], int tamanho) {
	int somatorio = 0;
	for (int i = 0; i < tamanho; i++) { somatorio += sequencia[i]; }
	return somatorio;
}

double calcularMedia(int sequencia[], int tamanho) {
	return (double)calcularSomatorio(sequencia, tamanho) / tamanho;
}

void subsequencia(int sequencia[], int tamanho, bool acima, char texto[]) {
	double media = calcularMedia(sequencia, tamanho);
	printf("Números %s da média (%.3f):\n", texto, media);
	for (int i = 0; i < tamanho; i++) {
		if ((sequencia[i] < media && !acima) ||
			(sequencia[i] > media && acima)) {
			printf("%d ", sequencia[i]);
		}
	}
	printf("\n");
}

int main() {
	int tamanho = perguntar(1, 50, "Com quantos elementos quer trabalhar: ");
	int sequencia[tamanho], escolha;
	bool valoresIntroduzidos = false;

	do {
		if (!valoresIntroduzidos) {
			introduzirValores(sequencia, tamanho);
			valoresIntroduzidos = true;
		}

		printf("\n");
		printf("Escolha 1 das seguintes opções:\n");
		printf("1. Introduzir uma sequência de %d números inteiros.\n",
			   tamanho);
		printf("2. Escrever no ecrã a sequência introduzida.\n");
		printf("3. Procurar o maior número da sequência.\n");
		printf("4. Procurar o menor número da sequência.\n");
		printf("5. Calcular o somatório da sequência.\n");
		printf("6. Calcular a média da sequência.\n");
		printf("7. Determinar a subsequência abaixo da média.\n");
		printf("8. Determinar a subsequência acima da média.\n");
		printf("9. Terminar o programa.\n");

		escolha = perguntar(1, 9, "> ");
		printf("\n");
		switch (escolha) {
		case 1:
			introduzirValores(sequencia, tamanho);
			break;
		case 2:
			printValores(sequencia, tamanho);
			break;
		case 3:
			printf("O maior número é %d.\n",
				   procurarMenorOuMaior(sequencia, tamanho, true));
			break;
		case 4:
			printf("O menor número é %d.\n",
				   procurarMenorOuMaior(sequencia, tamanho, false));
			break;
		case 5:
			printf("O somatório da sequência é %d.\n",
				   calcularSomatorio(sequencia, tamanho));
			break;
		case 6:
			printf("A média da sequência é %.3f.\n",
				   calcularMedia(sequencia, tamanho));
			break;
		case 7:
			subsequencia(sequencia, tamanho, false, "abaixo");
			break;
		case 8:
			subsequencia(sequencia, tamanho, true, "acima");
			break;
		case 9:
			break;
		default:
			printf("Algo correu mesmo muito mal.\n");
			break;
		}
	} while (escolha != 9);

	return 0;
}
