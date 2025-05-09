// Folha 4
// Exercício 11.3.2
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int numero;
} data_t;

typedef struct _q_node_t {
	data_t data;
	struct _q_node_t* next;
} q_node_t;

typedef struct {
	q_node_t* first;
	q_node_t* last;
} queue_t;

void init(queue_t* queue) {
	queue->first = NULL;
	queue->last = NULL;
}

int empty(queue_t* queue) {
	return queue->first == NULL;
}

void push(queue_t* queue, data_t data) {
	q_node_t* node = (q_node_t*)malloc(sizeof(q_node_t));
	if (node != NULL) {
		node->data = data;
		node->next = NULL;

		if (!empty(queue)) {
			queue->last->next = node;
		} else {
			queue->first = node;
		}
		queue->last = node;
	}
}

void pop(queue_t* queue) {
	if (!empty(queue)) {
		q_node_t* node = queue->first;
		queue->first = node->next;
		free(node);
		if (empty(queue)) queue->last = NULL;
	}
}

data_t front(queue_t* queue) {
	data_t data = { -1 };
	if (!empty(queue)) data = queue->first->data;
	return data;
}

void clean(queue_t* queue) {
	while (!empty(queue)) pop(queue);
	init(queue);
}

int perguntarInteiro(int min, int max) {
	int valor = min - 1;
	int invalido = 0;
	do {
		if (scanf("%d", &valor) != 1) {
			printf("Algo correu mal.\n");
			exit(-1);
		}
		invalido = valor < min || valor > max;
		if (invalido) printf("Insire um valor válido ou não muito grande: ");
	} while (invalido);
	return valor;
}

void printFilas(queue_t** vetor, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		while (!empty(vetor[i])) {
			for (int j = i; j < tamanho - 1; j++) {
				push(vetor[j + 1], front(vetor[j]));
				pop(vetor[j]);
			}
			printf("%d ", front(vetor[tamanho - 1]).numero);
			pop(vetor[tamanho - 1]);
		}
	}
	printf("\n");
}

int main() {
	printf("Tamanho do vetor: ");
	int tamanho = perguntarInteiro(1, 100);
	printf("\n");
	queue_t* vetor[tamanho];
	for (int i = 0; i < tamanho; i++) {
		vetor[i] = (queue_t*)malloc(sizeof(queue_t));
		init(vetor[i]);
		printf("Número de elementos da fila %d: ", i + 1);
		int numeroElementos = perguntarInteiro(1, 100);
		for (int _ = 0; _ < numeroElementos; _++) {
			printf("Insire um número para a fila %d: ", i + 1);
			data_t valor = { perguntarInteiro(-2100000000, 2100000000) };
			push(vetor[i], valor);
		}
		printf("\n");
	}
	printFilas(vetor, tamanho);

	for (int i = 0; i < tamanho; i++) {
		clean(vetor[i]);
		free(vetor[i]);
	}
	return 0;
}
