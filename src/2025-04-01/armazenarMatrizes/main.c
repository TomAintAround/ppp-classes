// Folha 4
// Exercício 13.2.1
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 3

typedef struct {
	int matrix[MATRIX_SIZE][MATRIX_SIZE];
} data_t;

typedef struct _list_node {
	data_t data;
	struct _list_node* next;
} list_node;

list_node* create() {
	list_node* header = (list_node*)malloc(sizeof(list_node));
	data_t data = { { { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 } } };
	if (header != NULL) {
		header->data = data;
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

void insert(list_node* header, data_t data) {
	list_node* node = (list_node*)malloc(sizeof(list_node));
	node->data = data;
	node->next = header->next;
	header->next = node;
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

void store(list_node* header, int numberMatrixes) {
	for (int i = 0; i < numberMatrixes; i++) {
		printf("Matriz número %d:\n", i + 1);
		data_t data;
		for (int line = 0; line < MATRIX_SIZE; line++) {
			for (int column = 0; column < MATRIX_SIZE; column++) {
				printf("Linha %d, coluna %d: ", line + 1, column + 1);
				data.matrix[line][column] = askInt(-2100000000, 2100000000);
			}
		}
		insert(header, data);
		printf("\n");
	}
}

void printList(list_node* header) {
	for (list_node* node = header->next; node != NULL; node = node->next) {
		for (int line = 0; line < MATRIX_SIZE; line++) {
			for (int column = 0; column < MATRIX_SIZE; column++) {
				printf("%5d ", node->data.matrix[line][column]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

int main() {
	list_node* header = create();
	printf("Número de matrizes: ");
	int numberMatrixes = askInt(1, 100);
	store(header, numberMatrixes);
	printList(header);

	header = clean(header);
	return 0;
}
