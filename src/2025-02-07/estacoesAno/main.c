// Folha 1
// Exercício 2.2.4
#include <stdio.h>

int main() {
	int dia = -1;
	int mes = -1;

	while (dia < 0 || dia > 31 || mes < 0 || mes > 12) {
		printf("Insire o dia: ");
		if (scanf("%d", &dia) != 1) {
			printf("Algo mal se passou");
			return -1;
		}
		printf("Insire o mes: ");
		if (scanf("%d", &mes) != 1) {
			printf("Algo mal se passou");
			return -1;
		}
	}

	switch (mes) {
		case 12:
			dia += 30;
		case 11:
			dia += 31;
		case 10:
			dia += 30;
		case 9:
			dia += 31;
		case 8:
			dia += 31;
		case 7:
			dia += 30;
		case 6:
			dia += 31;
		case 5:
			dia += 30;
		case 4:
			dia += 31;
		case 3:
			dia += 28;
		case 2:
			dia += 31;
	}

	if (dia < 79 || dia >= 355) { // Antes de 20 de março e depois de 20 de dezembro
		printf("Inverno");
	}
	else if (dia < 172) { // Antes de 21 de junho
		printf("Primavera");
	}
	else if (dia < 265) { // Antes de 22 de setembro
		printf("Verão");
	}
	else {
		printf("Outono");
	}

	return 0;
}
