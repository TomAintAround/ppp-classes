// Folha 4
// Exercício 11.3.1
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int numero;
	int ocorrencias;
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

		if (!empty(queue))
			queue->last->next = node;
		else
			queue->first = node;
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
	data_t data = {0, 0};
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

void construirVetor(int* vetor, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		printf("Insire o valor %d: ", i + 1);
		vetor[i] = perguntarInteiro();
	}
}

int ocorrencias(int numero, int* vetor, int tamanho) {
	int counter = 0;
	for (int i = 0; i < tamanho; i++) {
		if (vetor[i] == numero) counter++;
	}
	return counter;
}

void armazenar(queue_t* fila, int* vetor, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		int contador = ocorrencias(vetor[i], vetor, tamanho);
		data_t node = {vetor[i], contador};
		push(fila, node);
	}
}

void printFila(queue_t* fila) {
	while (!empty(fila)) {
		data_t node = front(fila);
		printf("Número %d, que ocorre %d vezes.\n", node.numero,
			   node.ocorrencias);
		pop(fila);
	}
}

int main() {
	printf("Número de elementos no vetor: ");
	int tamanho = perguntarInteiro();
	int vetor[tamanho];
	construirVetor(vetor, tamanho);

	queue_t fila;
	init(&fila);
	armazenar(&fila, vetor, tamanho);
	printFila(&fila);

	clear(&fila);
	return 0;
}
