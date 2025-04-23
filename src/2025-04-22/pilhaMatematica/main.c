#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 64

typedef struct _node_t {
	char math[STRING_SIZE];
	struct _node_t* next;
} node_t;

typedef node_t* pPilha;

void cria(pPilha* stack) {
	*stack = NULL;
}

int vazia(pPilha* stack) {
	return *stack == NULL;
}

void push(pPilha* stack, char* math) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node == NULL) return;
	strcpy(node->math, math);
	node->next = *stack;
	*stack = node;
}

char* pop(pPilha* stack) {
	char* math = (char*)malloc(sizeof(char) * STRING_SIZE);
	if (!vazia(stack)) {
		node_t* node = *stack;
		strcpy(math, node->math);
		*stack = node->next;
		free(node);
	} else {
		math = NULL;
	}
	return math;
}

void destroi(pPilha* stack) {
	while (!vazia(stack)) pop(stack);
	cria(stack);
}

int verificaParentesis(pPilha* stack) {
	int resultado = 0;
	node_t* nodeAuxiliar = *stack;
	char* math = nodeAuxiliar->math;

	for (size_t i = 0; math[i] != '\0'; i++) {
		if (math[i] == '(') resultado++;
		if (math[i] == ')') resultado--;
	}
	if (resultado < 0) {
		return -1;
	} else {
		return resultado;
	}
}

int main() {
	pPilha stack;
	cria(&stack);
	push(&stack, "(5+4x(6-3))x4-((6+11)/2)");
	push(&stack, "5+4x(6-3))x4-((6+11)/2)");
	push(&stack, "(5+4x(6-3x4-((6+11)/2)");
	push(&stack, "2x7/(5-(3+7))");

	while (!vazia(&stack)) {
		int resultado = verificaParentesis(&stack);
		char* math = pop(&stack);
		printf("%s: %d\n", math, resultado);
		free(math);
	}

	destroi(&stack);
	return 0;
}
