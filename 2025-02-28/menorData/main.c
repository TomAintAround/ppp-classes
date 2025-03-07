// Folha 3
// Exercício 8.2.2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DATAS 10

typedef struct {
	int dia, mes, ano;
} Data;

void definirDatas(Data *datas) {
	srand(time(NULL));
	for (int _ = 0; _ < NUMERO_DATAS; _++) {
		datas->dia = rand() % 31 + 1;
		datas->mes = rand() % 12 + 1;
		datas->ano = rand();
		datas++;
	}
}

void printDatas(Data *datas) {
	for (int _ = 0; _ < NUMERO_DATAS; _++) {
		printf("%d/%d/%d\n", datas->dia, datas->mes, datas->ano);
		datas++;
	}
	printf("\n");
}

Data *descubrirMenorData(Data *datas) {
	Data *menorData = datas;
	for (int i = 1; i < NUMERO_DATAS; i++) {
		int menorAno = datas->ano < menorData->ano;
		int igualAno = datas->ano == menorData->ano;
		int menorMes = igualAno && datas->mes < menorData->mes;
		int igualMes = igualAno && datas->mes == menorData->mes;
		int menorDia = igualMes && datas->dia < menorData->dia;
		if (menorAno || menorMes || menorDia) {
			menorData = datas;
		}
		datas++;
	}
	return menorData;
}

int main() {
	Data datas[NUMERO_DATAS];
	definirDatas(datas);
	printDatas(datas);
	Data *menorData = descubrirMenorData(datas);
	printf("A menor data é: %d/%d/%d\n", menorData->dia, menorData->mes, menorData->ano);

	return 0;
}