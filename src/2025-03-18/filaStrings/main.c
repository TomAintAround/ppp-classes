// Folha 4
// Exercício 11.1.2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 256

typedef struct {
	char string[STRING_SIZE];
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

		if (!empty(queue)) queue->last->next = node;
		else queue->first = node;
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
	data_t data = {"asdf"};
	if (!empty(queue)) data = queue->first->data;
	return data;
}

void clear(queue_t* queue) {
	while (!empty(queue)) pop(queue);
	init(queue);
}

int main() {
	queue_t fila;
	init(&fila);
	char stringInput[STRING_SIZE] = "tmp";
	while (1) {
		printf("Insire a sua string:\n");
		if (fgets(stringInput, STRING_SIZE, stdin) == NULL) {
			printf("Algo correu mal.\n");
			return -1;
		}
		if (strcmp(stringInput, "FIM\n") == 0) break;
		data_t stringInputData;
		strcpy(stringInputData.string, stringInput);
		push(&fila, stringInputData);
	}

	while (!empty(&fila)) {
		data_t stringOutputData = front(&fila);
		pop(&fila);
		printf("%s", stringOutputData.string);
	}

	clear(&fila);
	return 0;
}
