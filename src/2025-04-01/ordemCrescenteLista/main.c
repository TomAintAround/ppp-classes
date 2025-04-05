// Folha 4
// Exercício 13.1.1
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double number;
} data_t;

typedef struct _list_node {
	data_t data;
	struct _list_node* next;
} list_node;

list_node* create() {
	data_t data = {-1.0};
	list_node* header = (list_node*)malloc(sizeof(list_node));
	if (header != NULL) {
		header->data = data;
		header->next = NULL;
	}
	return header;
}

/*
int empty(list_node* header) {
	return header->next == NULL;
}
*/

list_node* clean(list_node* header) {
	while (header != NULL) {
		list_node* first = header;
		header = first->next;
		free(first);
	}
	return NULL;
}

void search(list_node* header, double key, list_node** previous,
			list_node** current) {
	*previous = header;
	*current = (*previous)->next;
	while ((*current) != NULL && (*current)->data.number < key) {
		*previous = *current;
		*current = (*current)->next;
	}
}

/*
void delete(list_node* header, double key) {
	list_node* previous;
	list_node* current;
	search(header, key, &previous, &current);
	if (current != NULL && current->data.number == key) {
		previous->next = current->next;
		free(current);
	}
}
*/

void insert(list_node* header, data_t data) {
	list_node* previous;
	list_node* useless;
	list_node* node = (list_node*)malloc(sizeof(list_node));
	if (node != NULL) {
		node->data = data;
		search(header, data.number, &previous, &useless);
		node->next = previous->next;
		previous->next = node;
	}
}

void printList(list_node* header) {
	list_node* node = header->next;
	while (node != NULL) {
		printf("%lf ", node->data.number);
		node = node->next;
	}
}

void store(list_node* header, int size) {
	for (int i = 0; i < size; i++) {
		printf("Insire o elemento número %d: ", i + 1);
		double value = 0;
		if (scanf("%lf", &value) != 1) {
			perror("Algo correu mal.\n");
			exit(1);
		}
		data_t data = {value};
		insert(header, data);
	}
}

int main() {
	list_node* header = create();
	printf("Insire o número de doubles que quer colocar: ");
	int size = 0, minSize = 1, maxSize = 100;
	while (size < minSize || size > maxSize) {
		if (scanf("%d", &size) != 1) {
			perror("Algo correu mal.\n");
			exit(1);
		}
		if (size < minSize) printf("Insire um número maior que %d: ", minSize);
		if (size > maxSize) printf("Insire um número menor que %d: ", maxSize);
	}
	store(header, size);
	printList(header);

	header = clean(header);
	return 0;
}
