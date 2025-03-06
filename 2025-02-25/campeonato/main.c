// Folha 2
// Exercício 7.2.2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QUANTIDADE_EQUIPAS 20

typedef struct {
	char nome[4];
	int numeroJogos, pontos, golos;
} Equipa;

typedef struct {
	int equipa1;
	int golos1;
	int equipa2;
	int golos2;
} Resultado;

void criarEquipas(Equipa equipas[]) {
	for (int i = 0; i < QUANTIDADE_EQUIPAS; i++) {
		equipas[i].numeroJogos = 0;
		equipas[i].pontos = 0;
		equipas[i].golos = 0;
	}
	strcpy(equipas[0].nome, "HDO");
	strcpy(equipas[1].nome, "OQP");
	strcpy(equipas[2].nome, "FMW");
	strcpy(equipas[3].nome, "BYR");
	strcpy(equipas[4].nome, "KFP");
	strcpy(equipas[5].nome, "ERY");
	strcpy(equipas[6].nome, "JFP");
	strcpy(equipas[7].nome, "KFM");
	strcpy(equipas[8].nome, "LAZ");
	strcpy(equipas[9].nome, "SNA");
	strcpy(equipas[10].nome, "IDK");
	strcpy(equipas[11].nome, "OMG");
	strcpy(equipas[12].nome, "ICA");
	strcpy(equipas[13].nome, "PLE");
	strcpy(equipas[14].nome, "STO");
	strcpy(equipas[15].nome, "ENO");
	strcpy(equipas[16].nome, "SOB");
	strcpy(equipas[17].nome, "GAG");
	strcpy(equipas[18].nome, "SLB");
	strcpy(equipas[19].nome, "PPP");
}

void criarResultados(Resultado resultados[]) {
	srand(time(NULL));
	for (int i = 0; i < QUANTIDADE_EQUIPAS; i++) {
		resultados[i].equipa1 = i;
		resultados[i].golos1 = rand() % 10;
		resultados[i].equipa2 = (i + 1) % QUANTIDADE_EQUIPAS;
		resultados[i].golos2 = rand() % 10;
	}
}

void printGolos(Equipa equipas[], Resultado resultados[]) {
	printf("Jogos e respetivos golos:\n");
	for (int i = 0; i < QUANTIDADE_EQUIPAS; i++) {
		Resultado resultado = resultados[i];
		printf("%s: %d | %s: %d\n", equipas[resultado.equipa1].nome, resultado.golos1, equipas[resultado.equipa2].nome, resultado.golos2);
	}
	printf("\n");
}

void calcularPontos(Equipa equipas[], Resultado resultados[]) {
	for (int i = 0; i < QUANTIDADE_EQUIPAS; i++) {
		Resultado resultado = resultados[i];
		if (resultado.golos1 > resultado.golos2) {
			equipas[resultado.equipa1].pontos += 2;
		}
		else if (resultado.golos1 < resultado.golos2) {
			equipas[resultado.equipa2].pontos += 2;
		}
		else {
			equipas[resultado.equipa1].pontos++;
			equipas[resultado.equipa2].pontos++;
		}
		equipas[resultado.equipa1].numeroJogos++;
		equipas[resultado.equipa1].golos += resultado.golos1;
		equipas[resultado.equipa2].golos += resultado.golos2;
		equipas[resultado.equipa2].numeroJogos++;
	}
}

void printPontos(Equipa equipas[]) {
	printf("Pontuação:\n");
	for (int i = 0; i < QUANTIDADE_EQUIPAS; i++) {
		printf("%s: %d (%d golos)\n", equipas[i].nome, equipas[i].pontos, equipas[i].golos);
	}
	printf("\n");
}

int verificarOrdemAlfabetica(char equipa1[4], char equipa2[4]) {
	for (int i = 0; i < 4; i++) {
		if (equipa1[i] < equipa2[i]) return 1;
		else if (equipa1[i] > equipa2[i]) return 0;
	}
	return 1;
}

void ordernarEquipas(Equipa equipas[]) {
	for (int i = 0; i < QUANTIDADE_EQUIPAS - 1; i++) {
		Equipa equipa1 = equipas[i];
		Equipa equipa2 = equipas[i + 1];
		int vitoriaPontos = equipa1.pontos > equipa2.pontos;
		int empatePontos = equipa1.pontos == equipa2.pontos;
		int vitoriaGolos = empatePontos && equipa1.golos > equipa2.golos;
		int empateGolos = empatePontos && equipa1.golos == equipa2.golos;
		int naoOrdemAlfabetica = empateGolos && !verificarOrdemAlfabetica(equipa1.nome, equipa2.nome);

		if (vitoriaPontos || vitoriaGolos || naoOrdemAlfabetica) {
			equipas[i] = equipa2;
			equipas[i + 1] = equipa1;
			if (i == 0) i -= 1;
			else i -= 2;
		}
	}
}

int main() {
	Equipa equipas[QUANTIDADE_EQUIPAS];
	Resultado resultados[QUANTIDADE_EQUIPAS];

	criarEquipas(equipas);
	criarResultados(resultados);
	printGolos(equipas, resultados);
	calcularPontos(equipas, resultados);
	ordernarEquipas(equipas);
	printPontos(equipas);

	return 0;
}