// Folha 2
// Exercício 7.2.1
#include <stdio.h>

typedef struct {
	int dia, mes, ano;
} Data;

int perguntarNumero(int min, int max, char texto[]) {
	int quantidade = min - 1;
	while (quantidade < min || quantidade > max) {
		printf("%s", texto);
		if (scanf("%d", &quantidade) != 1) {
			printf("Algo correu mal e será atribuido 5.\n");
			while (getchar() != '\n');
			quantidade = 5;
		}
	}
	return quantidade;
}

void perguntarDatas(Data datas[], int quantidadeDatas) {
	for (int data = 0; data < quantidadeDatas; data++) {
		printf("Insire a data do dia %d:\n", data + 1);
		datas[data].dia = perguntarNumero(1, 31, "Dia: ");
		datas[data].mes = perguntarNumero(1, 12, "Mês: ");
		datas[data].ano = perguntarNumero(-2100000000, 2100000000, "Ano: ");
		printf("\n");
	}
}

int comparar(Data data1, Data data2) {
	int comparacao = 0;
	if (data1.ano != data2.ano) {
		comparacao = data1.ano - data2.ano;
	}
	else if (data1.mes != data2.mes) {
		comparacao = data1.mes - data2.mes;
	}
	else {
		comparacao = data1.dia - data2.dia;
	}

	if (comparacao > 0) return 1;
	return 0;
}

void ordernar(Data datas[], int quantidadeDatas) {
	for (int data = 0; data < quantidadeDatas - 1; data++) {
		if (comparar(datas[data], datas[data + 1]) == 1) {
			Data data1 = datas[data];
			Data data2 = datas[data + 1];
			datas[data] = data2;
			datas[data + 1] = data1;
			data = -1;
		}
	}
}

int selecionarDatas(Data datas[], Data datasEspecificas[], int quantidadeDatas, int ano) {
	int lugar = 0;
	for (int data = 0; data < quantidadeDatas; data++) {
		if (datas[data].ano == ano) {
			datasEspecificas[lugar++] = datas[data];
		}
	}
	return lugar;
}

int main() {
	int quantidadeDatas = perguntarNumero(1, 1024, "Insire a quantidade de datas: ");
	printf("\n");

	Data datas[quantidadeDatas];
	perguntarDatas(datas, quantidadeDatas);

	ordernar(datas, quantidadeDatas);
	printf("Datas ordenadas por ordem crescente:\n");
	for (int data = 0; data < quantidadeDatas; data++) {
		printf("%d/%d/%d ", datas[data].dia, datas[data].mes, datas[data].ano);
	}
	printf("\n");

	printf("Menor data: %d/%d/%d.\n", datas[0].dia, datas[0].mes, datas[0].ano);

	int ano = perguntarNumero(-2100000000, 2100000000, "Insire o ano que quer ver: ");
	Data datasEspecificas[quantidadeDatas];
	int limite = selecionarDatas(datas, datasEspecificas, quantidadeDatas, ano);
	printf("Datas com esse ano: ");
	for (int data = 0; data < limite; data++) {
		Data estaData = datasEspecificas[data];
		printf("%d/%d/%d ", estaData.dia, estaData.mes, estaData.ano);
	}

	return 0;
}