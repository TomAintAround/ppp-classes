// Folha 2
// Exercício 6.2.1
#include <stdio.h>
#include <string.h>

#define TAMANHO 52 // 50 + \n + \0

void transformarMaiusculas(char texto[]) {
	for (int i = 0; i < (int)strlen(texto) - 1; i++) {
		if (texto[i] >= 'a' && texto[i] <= 'z') {
			texto[i] -= 'a' - 'A';
		}
	}
}

void codificarTexto(char texto[]) {
	for (int i = 0; i < (int)strlen(texto) - 1; i++) {
		int numeroLetra = texto[i] - 'A' + 1;
		if (numeroLetra >= 1 && numeroLetra <= 2) texto[i] += 3;
		else if (numeroLetra == 3) texto[i] = 9 + 'A' - 1;
		else if (numeroLetra >= 4 && numeroLetra <= 6) texto[i] -= 3;
		else if (numeroLetra >= 7 && numeroLetra <= 9) texto[i] -= 1;
		else if (numeroLetra >= 13 && numeroLetra <= 26) texto[i] = 39 - numeroLetra + 'A' - 1;
	}
}

void descodificarTexto(char texto[]) {
	for (int i = 0; i < (int)strlen(texto) - 1; i++) {
		int numeroLetra = texto[i] - 'A' + 1;
		if (numeroLetra >= 1 && numeroLetra <= 3) texto[i] += 3;
		else if (numeroLetra >= 4 && numeroLetra <= 5) texto[i] -= 3;
		else if (numeroLetra >= 6 && numeroLetra <= 8) texto[i] += 1;
		else if (numeroLetra == 9) texto[i] = 3 + 'A' - 1;
		else if (numeroLetra >= 13 && numeroLetra <= 26) texto[i] = 39 - numeroLetra + 'A' - 1;
	}
}

int soMaiusculas(char texto[]) {
	for (int i = 0; i < (int)strlen(texto) - 1; i++) {
		if (texto[i] >= 'a' && texto[i] <= 'z') {
			return 0;
		}
	}
	return 1;
}

void encriptar() {
	char texto[TAMANHO];
	printf("Insire texto com menos de 50 caracteres:\n");
	if (fgets(texto, TAMANHO, stdin) == NULL) {
		printf("Algo correu mal.\n");
		while (getchar() != '\n');
		encriptar();
	}
	transformarMaiusculas(texto);
	codificarTexto(texto);
	printf("Codificado: %s", texto);
}

void desencriptar() {
	char texto[TAMANHO];
	printf("Insire texto com menos de 50 caracteres:\n");
	if (fgets(texto, TAMANHO, stdin) == NULL) {
		printf("Algo correu mal.\n");
		while (getchar() != '\n');
		desencriptar();
	}
	if (soMaiusculas(texto)) {
		descodificarTexto(texto);
		printf("Descodificado: %s", texto);
	}
	else {
		printf("O texto tem letras minúsculas.\n");
		desencriptar();
	}
}

int main() {
	int escolha = 1;
	do {
		printf("Insire 1 das seguintes opções:\n");
		printf("1: Encriptar texto.\n");
		printf("2: Desencriptar texto.\n");
		printf("3: Sair.\n");
		printf("> ");
		if (scanf("%d", &escolha) != 1) {
			escolha = 0;
		}
		while (getchar() != '\n');
		printf("\n");

		switch(escolha) {
			case 1:
				encriptar();
				break;
			case 2:
				desencriptar();
				break;
			case 3:
				break;
			default:
				printf("Insire uma das opções assinaladas.");
		}

		printf("\n");
	} while (escolha != 3);

	return 0;
}