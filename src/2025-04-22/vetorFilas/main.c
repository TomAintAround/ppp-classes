#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMERO_FILAS 5
#define STRING_SIZE 64

typedef struct {
	char character;
	size_t index;
} element_t;

typedef struct _node_t {
	char character;
	struct _node_t* next;
} node_t;

typedef struct {
	size_t size;
	node_t* first;
	node_t* last;
} queue_t;

void cria(queue_t* queue) {
	queue->first = NULL;
	queue->last = NULL;
	queue->size = 0;
}

int vazia(queue_t* queue) {
	return queue->first == NULL;
}

void push(queue_t* queue, char character) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node == NULL) return;
	node->character = character;
	node->next = NULL;
	if (!vazia(queue)) {
		queue->last->next = node;
	} else {
		queue->first = node;
	}
	queue->last = node;
	queue->size++;
}

char front(queue_t* queue) {
	return vazia(queue) ? '\0' : queue->first->character;
}

void pop(queue_t* queue) {
	if (!vazia(queue)) {
		node_t* node = queue->first;
		queue->first = node->next;
		free(node);
		queue->size--;
		if (vazia(queue)) queue->last = NULL;
	}
}

void destroi(queue_t* queue) {
	while (!vazia(queue)) pop(queue);
	cria(queue);
}

void createString(queue_t* queue, char* string) {
	node_t* node = queue->first;
	int i = 0;
	while (node != NULL) {
		string[i++] = node->character;
		node = node->next;
	}
	string[i] = '\0';
}

size_t insert(queue_t* queueArray, size_t tamanhoElemArray, element_t* elemArray) {
	for (size_t i = 0; i < tamanhoElemArray; i++) {
		element_t element = elemArray[i];
		push(queueArray + element.index, element.character);
	}

	size_t maiorTamanho = 0;
	for (size_t i = 0; i < NUMERO_FILAS; i++) {
		if ((queueArray + i)->size > maiorTamanho) {
			maiorTamanho = (queueArray + i)->size;
		}
	}
	return maiorTamanho;
}

int main() {
	queue_t filas[NUMERO_FILAS];
	for (size_t i = 0; i < NUMERO_FILAS; i++) cria(filas + i);
	element_t elements[] = {
		{ .character = 'a', .index = 1 }, { .character = 'T', .index = 3 },
		{ .character = 'y', .index = 0 }, { .character = '8', .index = 1 },
		{ .character = 'a', .index = 0 }, { .character = '+', .index = 3 },
		{ .character = 'b', .index = 1 }, { .character = '2', .index = 0 },
		{ .character = 'h', .index = 1 }, { .character = '1', .index = 2 },
		{ .character = 'B', .index = 4 }, { .character = 'P', .index = 0 },
		{ .character = 'r', .index = 0 }, { .character = '*', .index = 4 },
		{ .character = 'A', .index = 2 }, { .character = ',', .index = 0 },
		{ .character = 'c', .index = 3 }, { .character = 'E', .index = 2 },
		{ .character = 'x', .index = 0 }, { .character = 'c', .index = 1 },
		{ .character = 'K', .index = 4 }, { .character = ')', .index = 2 },
	};
	size_t maiorTamanho = insert(filas, 22, elements);

	char string[STRING_SIZE];
	createString(filas + 4, string);
	printf("%s\n", string);

	for (size_t i = 0; i < NUMERO_FILAS; i++) {
		while (!vazia(filas + i)) {
			printf("%c", front(filas + i));
			pop(filas + i);
		}
		printf("\n");
	}
	printf("Tamanho: %zu\n", maiorTamanho);

	for (size_t i = 0; i < NUMERO_FILAS; i++) destroi(filas + i);
	return 0;
}
