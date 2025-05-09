// Folha 4
// Exercício 11.2.1
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int number;
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
	data_t data = { 0 };
	if (!empty(queue)) data = queue->first->data;
	return data;
}

void clear(queue_t* queue) {
	while (!empty(queue)) pop(queue);
	init(queue);
}

int perguntarInteiro() {
	int valor = 0;
	if (scanf("%d", &valor) != 1) {
		printf("Algo correu mal.\n");
		exit(-1);
	}
	return valor;
}

void criarArray(int* vetor, int N) {
	for (int i = 0; i < N; i++) {
		printf("Insire o valor %d: ", i + 1);
		vetor[i] = perguntarInteiro();
	}
}

void armazenarArrays(int* vetor, int N, queue_t* fila) {
	for (int i = 0; i < N; i++) {
		data_t valor = { vetor[i] };
		push(fila, valor);
	}
}

void printFila(queue_t* fila) {
	while (!empty(fila)) {
		int valor = front(fila).number;
		pop(fila);
		printf("%d ", valor);
	}
	printf("\n");
}

int main() {
	queue_t fila;
	init(&fila);

	printf("Valor de N: ");
	int N = perguntarInteiro();
	int vetor[N];
	criarArray(vetor, N);
	armazenarArrays(vetor, N, &fila);
	printFila(&fila);

	clear(&fila);
	return 0;
}
