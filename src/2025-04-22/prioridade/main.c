#include <stdio.h>
#include <stdlib.h>

typedef struct _node_t {
	double data;
	int priority;
	struct _node_t* next;
} node_t;

typedef struct {
	node_t* first;
	node_t* last;
} queue_t;

void init(queue_t* queue) {
	queue->first = NULL;
	queue->last = NULL;
}

int emptyQueue(queue_t* queue) {
	return queue->first == NULL;
}

void addItemPriority(queue_t* queue, double data, int priority) {
	node_t* previous = NULL;
	node_t* current = queue->first;
	while (current != NULL && current->priority < priority) {
		previous = current;
		current = current->next;
	}

	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node == NULL) return;
	node->priority = priority;
	node->data = data;
	if (previous == NULL) {
		queue->first = node;
	} else {
		previous->next = node;
	}
	node->next = current;
	if (current == NULL) queue->last = node;
}

double front(queue_t* queue) {
	return emptyQueue(queue) ? -1.0 : queue->first->data;
}

void pop(queue_t* queue) {
	if (!emptyQueue(queue)) {
		node_t* node = queue->first;
		queue->first = node->next;
		free(node);
		if (emptyQueue(queue)) queue->last = NULL;
	}
}

void clear(queue_t* queue) {
	while (!emptyQueue(queue)) pop(queue);
	init(queue);
}

int main() {
	queue_t fila;
	init(&fila);

	addItemPriority(&fila, 2.0, 10);
	addItemPriority(&fila, 2.65, 4);
	addItemPriority(&fila, 1.015, 0);
	addItemPriority(&fila, 0.43, 2);
	addItemPriority(&fila, -20.43, -2);

	while (!emptyQueue(&fila)) {
		printf("%.3f ", front(&fila));
		pop(&fila);
	}
	printf("\n");

	clear(&fila);
	return 0;
}
