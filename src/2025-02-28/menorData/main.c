// Folha 3
// Exercício 8.2.2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DATAS 10

typedef struct {
	int dia, mes, ano;
} Data;

void definirDatas(Data* datas) {
	srand(time(NULL));
	for (int _ = 0; _ < NUMERO_DATAS; _++) {
		datas->dia = rand() % 31 + 1;
		datas->mes = rand() % 12 + 1;
		datas->ano = rand();
		datas++;
	}
}

void printDatas(Data* datas) {
	for (int _ = 0; _ < NUMERO_DATAS; _++) {
		printf("%d/%d/%d\n", datas->dia, datas->mes, datas->ano);
		datas++;
	}
	printf("\n");
}

int ordemDataCorreta(Data* data1, Data* data2) {
	if (data1->ano < data2->ano) return 1;
	if (data1->ano > data2->ano) return 0;

	if (data1->mes < data2->mes) return 1;
	if (data1->mes > data2->mes) return 0;

	if (data1->dia < data2->dia) return 1;
	return 0;
}

Data* descubrirMenorData(Data* datas) {
	Data* menorData = datas;
	for (int _ = 1; _ < NUMERO_DATAS; _++) {
		if (ordemDataCorreta(datas, menorData)) menorData = datas;
		datas++;
	}
	return menorData;
}

int main() {
	Data datas[NUMERO_DATAS];
	definirDatas(datas);
	printDatas(datas);
	Data* menorData = descubrirMenorData(datas);
	printf("A menor data é: %d/%d/%d\n", menorData->dia, menorData->mes,
		   menorData->ano);

	return 0;
}
