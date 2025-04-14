// Folha 4
// Exercício 13.3.4
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 64

typedef struct {
	int dia, mes, ano, hora, minuto;
} data_hora_t;

typedef struct {
	int estudante, jovem, normal;
} precos_t;

typedef struct {
	char artista[STRING_SIZE];
	data_hora_t data;
	precos_t precos;
} evento_t;

typedef struct _node_t {
	evento_t evento;
	struct _node_t* proxData;
	struct _node_t* proxPreco;
} node_t;

typedef struct {
	node_t* frontData;
	node_t* frontPreco;
} list_t;

void init(list_t* list) {
	list->frontData = NULL;
	list->frontPreco = NULL;
}

bool ordemCrescenteDatas(data_hora_t data1, data_hora_t data2) {
	if (data1.ano > data2.ano) return false;
	if (data1.ano < data2.ano) return true;

	if (data1.mes > data2.mes) return false;
	if (data1.mes < data2.mes) return true;

	if (data1.dia > data2.dia) return false;
	if (data1.dia < data2.dia) return true;

	if (data1.hora > data2.hora) return false;
	if (data1.hora < data2.hora) return true;

	if (data1.minuto > data2.minuto) return false;
	return true;
}

void searchData(list_t* list, data_hora_t data, node_t** previous,
				node_t** current) {
	*previous = NULL;
	*current = list->frontData;
	while (*current != NULL &&
		   ordemCrescenteDatas((*current)->evento.data, data)) {
		*previous = *current;
		*current = (*current)->proxData;
	}
}

void searchPreco(list_t* list, int preco, node_t** previous, node_t** current) {
	*previous = NULL;
	*current = list->frontPreco;
	while (*current != NULL && (*current)->evento.precos.normal < preco) {
		*previous = *current;
		*current = (*current)->proxPreco;
	}
}

void insert(list_t* list, evento_t evento) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node == NULL) return;
	node->evento = evento;
	node_t* previous;
	node_t* current;

	searchData(list, evento.data, &previous, &current);
	if (previous == NULL) {
		list->frontData = node;
	} else {
		previous->proxData = node;
	}
	node->proxData = current;

	searchPreco(list, evento.precos.normal, &previous, &current);
	if (previous == NULL) {
		list->frontPreco = node;
	} else {
		previous->proxPreco = node;
	}
	node->proxPreco = current;
}

void clean(list_t* list) {
	while (list->frontData != NULL) {
		node_t* node = list->frontData;
		list->frontData = node->proxData;
		free(node);
	}
	init(list);
}

void erro(char* mensagem) {
	perror(mensagem);
	exit(1);
}

int perguntarInt(int min, int max) {
	int value = min - 1;
	while (value < min || value > max) {
		if (scanf("%d", &value) != 1) erro("Tem de inserir um inteiro.\n");
		if (value < min) {
			printf("Tem de inserir um número maior que %d: ", min);
		}
		if (value > max) {
			printf("Tem de inserir um número menor que %d: ", max);
		}
	}
	return value;
}

void inserirEventos(list_t* list, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		evento_t evento;
		data_hora_t data;
		printf("Evento %d:\n", i + 1);

		printf("Nome do artista: ");
		if (fgets(evento.artista, STRING_SIZE, stdin) == NULL) {
			erro("Algo correu mal");
		}

		printf("Dia do evento: ");
		data.dia = perguntarInt(1, 31);
		printf("Mês do evento: ");
		data.mes = perguntarInt(1, 12);
		printf("Ano do evento: ");
		data.ano = perguntarInt(-2100000000, 2100000000);
		printf("Hora do evento: ");
		data.hora = perguntarInt(0, 23);
		printf("Minuto do evento: ");
		data.minuto = perguntarInt(0, 59);
		evento.data = data;

		printf("Preço do bilhete de estudante (€): ");
		evento.precos.estudante = perguntarInt(0, 2100000000);
		printf("Preço do bilhete de jovem não estudante (€): ");
		evento.precos.jovem = perguntarInt(0, 2100000000);
		printf("Preço do bilhete normal (€): ");
		evento.precos.normal = perguntarInt(0, 2100000000);

		insert(list, evento);
		while (getchar() != '\n');
		printf("\n");
	}
}

void imprimirEvento(evento_t evento) {
	data_hora_t data = evento.data;
	precos_t precos = evento.precos;
	printf("Artista: %s", evento.artista);
	printf("Data e hora: %d %d %d %d %d\n", data.dia, data.mes, data.ano,
		   data.hora, data.minuto);
	printf("Preço dos bilhetes (estudante, jovem, normal): %d %d %d\n",
		   precos.estudante, precos.jovem, precos.normal);
	printf("\n");
}

void imprimirPorData(list_t* list) {
	node_t* node = list->frontData;
	while (node != NULL) {
		imprimirEvento(node->evento);
		node = node->proxData;
	}
}

void imprimirPorPrecos(list_t* list) {
	node_t* node = list->frontPreco;
	while (node != NULL) {
		imprimirEvento(node->evento);
		node = node->proxPreco;
	}
}

int main() {
	list_t list;
	init(&list);
	printf("Número de eventos: ");
	int tamanho = perguntarInt(1, 100);
	while (getchar() != '\n');

	inserirEventos(&list, tamanho);
	printf("\nOrdem crescente de datas:\n\n");
	imprimirPorData(&list);
	printf("\nOrdem crescente dos preços normais:\n\n");
	imprimirPorPrecos(&list);

	clean(&list);
	return 0;
}
