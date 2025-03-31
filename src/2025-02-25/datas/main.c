// Folha 2
// Exercício 7.1.1
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int dia, mes, ano;
} Data;

Data perguntar(Data data) {
	data.dia = 0;
	data.mes = 0;
	data.ano = 0;

	while (data.dia < 1 || data.dia > 31) {
		printf("Insire o dia: ");
		if (scanf("%d", &data.dia) != 1) {
			printf("Algo correu mal e será atribuido 1.\n");
			data.dia = 1;
			while (getchar() != '\n');
		}
	}
	while (data.mes < 1 || data.mes > 12) {
		printf("Insire o mês: ");
		if (scanf("%d", &data.mes) != 1) {
			printf("Algo correu mal e será atribuido 1.\n");
			data.mes = 1;
			while (getchar() != '\n');
		}
	}
	printf("Insire o ano: ");
	if (scanf("%d", &data.ano) != 1) {
		printf("Algo correu mal e será atribuido 1.\n");
		data.ano = 1;
		while (getchar() != '\n');
	}
	return data;
}

int comparar(Data data1, Data data2) {
	int comparacao = 0;
	if (data1.ano != data2.ano) {
		comparacao = data1.ano - data2.ano;
	} else if (data1.mes != data2.mes) {
		comparacao = data1.mes - data2.mes;
	} else {
		comparacao = data1.dia - data2.dia;
	}

	if (comparacao > 0) return 1;
	if (comparacao < 0) return -1;
	return 0;
}

Data diferenca(Data data1, Data data2) {
	Data diferencaDatas;
	diferencaDatas.dia = data1.dia - data2.dia;
	diferencaDatas.mes = data1.mes - data2.mes;
	diferencaDatas.ano = data1.ano - data2.ano;
	return diferencaDatas;
}

int calcularSeculo(Data data) {
	return (data.ano / 100) + 1;
}

int main() {
	printf("Insire a primeira data.\n");
	Data data1 = perguntar(data1);
	printf("\nInsire a segunda data.\n");
	Data data2 = perguntar(data2);
	printf("\n");

	if (comparar(data1, data2) == -1) {
		printf("A primeira data vem antes da segunda.\n");
	} else if (comparar(data1, data2) == 1) {
		printf("A primeira data vem antes da segunda.\n");
	} else {
		printf("As datas são as mesmas.\n");
	}

	Data diferencaDatas = diferenca(data1, data2);
	printf("A diferença é de %d dias, %d meses e %d anos.\n",
		   diferencaDatas.dia, diferencaDatas.mes, diferencaDatas.ano);

	printf("A primeira data situa-se no século %d e a segunda no século %d.",
		   calcularSeculo(data1), calcularSeculo(data2));

	return 0;
}
