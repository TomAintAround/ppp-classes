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
	for (int i = 0; i < NUMERO_DATAS - 1; i++) {
		Data *data1 = datas;
		Data *data2 = datas + 1;
		int anoMaior = data1->ano > data2->ano;
		int anoIgual = data1->ano == data2->ano;
		int mesMaior = anoIgual && data1->mes > data2->mes;
		int mesIgual = anoIgual && data1->mes == data2->mes;
		int diaMaior = mesIgual && data1->dia > data2->dia;
		
		if (anoMaior || mesMaior || diaMaior) {
			*datas = *data2;
			*(datas + 1) = *data1;
			
			if (i == 0) {
				i -= 1;
				continue;
			}
			else {
				i -= 2;
				datas--;
				continue;
			}
		}
		datas++;
	}
	return datas - (NUMERO_DATAS - 1);
}

int main() {
	Data datas[NUMERO_DATAS];
	definirDatas(datas);
	printDatas(datas);
	Data *menorData = descubrirMenorData(datas);
	printf("A menor data é: %d/%d/%d\n", menorData->dia, menorData->mes, menorData->ano);

	return 0;
}