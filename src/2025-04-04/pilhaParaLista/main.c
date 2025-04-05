// Folha 4
// Exercício 13.2.4
#include <stdio.h>
#include <stdlib.h>

typedef struct _node_t {
	int number;
	struct _node_t* next;
} node_t;

void initStack(node_t** stack) {
	*stack = NULL;
}

node_t* initList() {
	node_t* header = (node_t*)malloc(sizeof(node_t));
	if (header != NULL) {
		header->number = -1;
		header->next = NULL;
	}
	return header;
}

int empty(node_t** stack) {
	return *stack == NULL;
}

void push(node_t** stack, int number) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node != NULL) {
		node->number = number;
		node->next = *stack;
		*stack = node;
	}
}

void insert(node_t* header, int number) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node != NULL) {
		node->number = number;
		node->next = header->next;
		header->next = node;
	}
}

void pop(node_t** stack) {
	if (!empty(stack)) {
		node_t* node = *stack;
		*stack = node->next;
		free(node);
	}
}

int front(node_t** stack) {
	return empty(stack) ? -1 : (*stack)->number;
}

void cleanStack(node_t** stack) {
	while (!empty(stack)) pop(stack);
	initStack(stack);
}

node_t* cleanList(node_t* header) {
	while (header != NULL) {
		node_t* node = header;
		header = node->next;
		free(node);
	}
	return NULL;
}

void printList(node_t* header) {
	node_t* node = header->next;
	while (node != NULL) {
		printf("%d ", node->number);
		node = node->next;
	}
	printf("\n");
}

int askInt(int min, int max) {
	int result = min - 1;
	while (result < min || result > max) {
		if (scanf("%d", &result) != 1) {
			perror("Algo correu mal.\n");
			exit(1);
		}
		if (result < min) printf("Insire um número maior que %d: ", min);
		if (result > max) printf("Insire um número menor que %d: ", max);
	}
	return result;
}

int main() {
	node_t* stack;
	node_t* header = initList();
	initStack(&stack);

	printf("Insire o número de elementos: ");
	int size = askInt(1, 100);
	for (int i = 0; i < size; i++) {
		printf("Insire o elemento número %d: ", i + 1);
		push(&stack, askInt(-2100000000, 2100000000));
	}
	while (!empty(&stack)) {
		insert(header, front(&stack));
		pop(&stack);
	}
	printList(header);

	cleanStack(&stack);
	header = cleanList(header);
	return 0;
}
