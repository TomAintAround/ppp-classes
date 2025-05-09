// Folha 4
// Exercício 13.2.5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 64

typedef struct {
	char word[STRING_SIZE];
} data_t;

typedef struct _node_t {
	data_t data;
	struct _node_t* next;
} node_t;

node_t* create() {
	node_t* header = (node_t*)malloc(sizeof(node_t));
	if (header != NULL) {
		strcpy(header->data.word, "oi");
		header->next = NULL;
	}
	return header;
}

node_t* clean(node_t* header) {
	while (header != NULL) {
		node_t* node = header;
		header = node->next;
		free(node);
	}
	return NULL;
}

int empty(node_t* header) {
	return header->next == NULL;
}

void search(node_t* header, char* name, node_t** previous, node_t** current) {
	*previous = header;
	*current = header->next;
	while ((*current != NULL) && strcmp((*current)->data.word, name) < 0) {
		*previous = *current;
		*current = (*current)->next;
	}
}

void insert(node_t* header, data_t data) {
	node_t* previous;
	node_t* current;
	search(header, data.word, &previous, &current);
	if (current != NULL && strcmp(current->data.word, data.word) == 0) return;
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node != NULL) {
		node->data = data;
		node->next = previous->next;
		previous->next = node;
	}
}

data_t front(node_t* header) {
	data_t data = { "hay" };
	if (header->next != NULL) strcpy(data.word, header->next->data.word);
	return data;
}

void pop(node_t* header) {
	if (!empty(header)) {
		node_t* node = header->next;
		header->next = node->next;
		free(node);
	}
}

void printList(node_t* header) {
	node_t* node = header->next;
	while (node != NULL) {
		printf("%s", node->data.word);
		node = node->next;
	}
}

void error() {
	perror("Algo correu mal.\n");
	exit(1);
}

int askInt(int min, int max) {
	int result = min - 1;
	while (result < min || result > max) {
		if (scanf("%d", &result) != 1) error();
		if (result < min) printf("Insire um número maior que %d: ", min);
		if (result > max) printf("Insire um número menor que %d: ", max);
	}
	return result;
}

void armazenar(node_t* header, int size) {
	for (int i = 0; i < size; i++) {
		char word[STRING_SIZE];
		printf("Insire a palavra número %d: ", i + 1);
		if (fgets(word, STRING_SIZE, stdin) == NULL) error();
		data_t data;
		strcpy(data.word, word);
		insert(header, data);
	}
}

void concat(node_t* header1, node_t* header2) {
	while (!empty(header2)) {
		insert(header1, front(header2));
		pop(header2);
	}
}

int main() {
	node_t* header1 = create();
	node_t* header2 = create();
	printf("Insire o tamanho da lista 1: ");
	int size1 = askInt(1, 100);
	printf("Insire o tamanho da lista 2: ");
	int size2 = askInt(1, 100);
	while (getchar() != '\n');
	printf("Insire as palavras da lista 1:\n");
	armazenar(header1, size1);
	printf("Insire as palavras da lista 2:\n");
	armazenar(header2, size2);
	concat(header1, header2);
	printList(header1);

	header1 = clean(header1);
	header2 = clean(header2);
	return 0;
}
