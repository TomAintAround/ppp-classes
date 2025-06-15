// Folha 4
// Exercío 12.3.1
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int number;
} data_t;

typedef struct _node_t {
	data_t data;
	struct _node_t* next;
} node_t;

typedef struct {
	node_t* first;
	node_t* last;
} queue_t;

void initQueue(queue_t* queue) {
	queue->first = NULL;
	queue->last = NULL;
}

void initStack(node_t** stack) {
	*stack = NULL;
}

int emptyQueue(queue_t* queue) {
	return queue->first == NULL;
}

int emptyStack(node_t** stack) {
	return *stack == NULL;
}

void pushQueue(queue_t* queue, data_t data) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node != NULL) {
		node->data = data;
		node->next = NULL;

		if (!emptyQueue(queue)) {
			queue->last->next = node;
		} else {
			queue->first = node;
		}
		queue->last = node;
	}
}

void pushStack(node_t** stack, data_t data) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node != NULL) {
		node->data = data;
		node->next = *stack;
		*stack = node;
	}
}

void popQueue(queue_t* queue) {
	if (!emptyQueue(queue)) {
		node_t* node = queue->first;
		queue->first = node->next;
		free(node);
	}
}

void popStack(node_t** stack) {
	if (!emptyStack(stack)) {
		node_t* node = *stack;
		*stack = node->next;
		free(node);
	}
}

data_t frontQueue(queue_t* queue) {
	data_t data = { -1 };
	if (!emptyQueue(queue)) data = queue->first->data;
	return data;
}

data_t frontStack(node_t** stack) {
	data_t data = { -1 };
	if (!emptyStack(stack)) data = (*stack)->data;
	return data;
}

void cleanQueue(queue_t* queue) {
	while (!emptyQueue(queue)) popQueue(queue);
	initQueue(queue);
}

void cleanStack(node_t** stack) {
	while (!emptyStack(stack)) popStack(stack);
	initStack(stack);
}

int askInt(const int min, const int max) {
	int value = min - 1;
	while (value < min || value > max) {
		if (scanf("%d", &value) != 1) {
			perror("Algo correu mal.\n");
			exit(1);
		}
	}
	return value;
}

void storeQueue(queue_t* queue, int size) {
	for (int i = 0; i < size; i++) {
		printf("Elemento %d: ", i + 1);
		data_t data = { askInt(-2100000000, 2100000000) };
		pushQueue(queue, data);
	}
}

void storeStack(node_t** stack, queue_t* queue) {
	while (!emptyQueue(queue)) {
		pushStack(stack, frontQueue(queue));
		popQueue(queue);
	}
}

void readStack(node_t** stack) {
	while (!emptyStack(stack)) {
		int number = frontStack(stack).number;
		popStack(stack);
		printf("%d ", number);
	}
	printf("\n");
}

int main() {
	queue_t queue;
	node_t* stack;
	initQueue(&queue);
	initStack(&stack);
	printf("Tamanho da fila: ");
	int size = askInt(1, 100);

	storeQueue(&queue, size);
	storeStack(&stack, &queue);
	readStack(&stack);

	cleanQueue(&queue);
	cleanStack(&stack);
	return 0;
}
