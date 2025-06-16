#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct SNode {
	int number;
	struct SNode* next;
} node_t;

void init(node_t** stack) {
	*stack = NULL;
}

bool empty(node_t** stack) {
	return *stack == NULL;
}

void push(node_t** stack, const int number) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node == NULL) return;
	node->number = number;
	node->next = *stack;
	*stack = node;
}

int front(node_t** stack) {
	return !empty(stack) ? (*stack)->number : -1;
}

void pop(node_t** stack) {
	if (!empty(stack)) {
		node_t* node = *stack;
		*stack = node->next;
		free(node);
	}
}

void clean(node_t** stack) {
	while (!empty(stack)) pop(stack);
	init(stack);
}

void printStack(node_t** stack) {
	node_t* node = *stack;
	while (node != NULL) {
		printf("%d ", node->number);
		node = node->next;
	}
	printf("\n");
}

void inserir(node_t** stack, int* array, const size_t tamanho) {
	bool temPar = false;
	for (size_t i = 0; i < tamanho; i++) {
		if (array[i] % 2 == 1 && temPar) {
			while (front(stack) % 2 == 0) { pop(stack); }
			push(stack, array[i]);
			for (size_t j = 0; j < i; j++) {
				if (array[j] % 2 == 0) push(stack, array[j]);
			}
			continue;
		}
		if (array[i] % 2 == 0 && !temPar) temPar = true;
		push(stack, array[i]);
	}
}

int main() {
	node_t* stack;
	init(&stack);
	int array[] = { 3, 6, 1, 2, 5, 64, 32, 1, 8 };
	const size_t tamanho = sizeof(array) / sizeof(int);
	inserir(&stack, array, tamanho);
	printStack(&stack);

	clean(&stack);
	return 0;
}
