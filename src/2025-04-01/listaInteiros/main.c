// Folha 4
// Exercício 13.1.2
#include <stdio.h>
#include <stdlib.h>

typedef struct _list_node {
	int number;
	struct _list_node* next;
} list_node;

list_node* create() {
	list_node* header = (list_node*)malloc(sizeof(list_node));
	if (header != NULL) {
		header->number = -1;
		header->next = NULL;
	}
	return header;
}

list_node* clean(list_node* header) {
	while (header != NULL) {
		list_node* node = header;
		header = node->next;
		free(node);
	}
	return NULL;
}

void search(list_node* header, int number, list_node** previous) {
	*previous = header;
	list_node* current = header->next;
	while (current != NULL && current->number < number) {
		*previous = current;
		current = current->next;
	}
}

void insert(list_node* header, int number) {
	list_node* node = (list_node*)malloc(sizeof(list_node));
	if (node != NULL) {
		list_node* previous;
		search(header, number, &previous);
		node->number = number;
		node->next = previous->next;
		previous->next = node;
	}
}

int askInt(int min, int max) {
	int value = min - 1;
	while (value < min || value > max) {
		if (scanf("%d", &value) != 1) {
			perror("Algo correu mal.\n");
			exit(1);
		}
		if (value < min) printf("Insire um número maior que %d: ", min);
		if (value > max) printf("Insire um número menor que %d: ", max);
	}
	return value;
}

int smallestElement(list_node* header) {
	return header->next->number;
}

int biggestElement(list_node* header) {
	list_node* node = header;
	while (node->next != NULL) node = node->next;
	return node->number;
}

double average(list_node* header, int size) {
	double sum = 0;
	for (list_node* node = header->next; node != NULL; node = node->next) {
		sum += node->number;
	}
	return sum / size;
}

int main() {
	list_node* header = create();
	printf("Número de elementos: ");
	int size = askInt(1, 100);
	for (int i = 0; i < size; i++) {
		printf("Insire o elemento número %d: ", i + 1);
		insert(header, askInt(-2100000000, 2100000000));
	}
	printf("Menor elemento: %d\nMaior elemento: %d\nMédia aritmética: %lf\n",
		   smallestElement(header), biggestElement(header), average(header, size));

	header = clean(header);
	return 0;
}
