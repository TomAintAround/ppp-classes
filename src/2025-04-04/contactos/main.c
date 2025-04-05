// Folha 4
// Exercício 13.2.2
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 64

typedef struct {
	char name[NAME_LENGTH];
	int phoneNumber;
} data_t;

typedef struct _list_node {
	data_t data;
	struct _list_node* next;
} list_node;

list_node* create() {
	list_node* header = (list_node*)malloc(sizeof(list_node));
	if (header != NULL) {
		data_t data = {"Joaquim", 999999999};
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

void lower(char* string) {
	for (int letter = 0; string[letter] != '\n' && string[letter] != '\0';
		 letter++) {
		string[letter] = tolower(string[letter]);
	}
}

int alphabeticOrder(char* name1, char* name2) {
	lower(name1);
	lower(name2);
	for (int letter = 0; name1[letter] != '\n' && name1[letter] != '\0' &&
						 name2[letter] != '\n' && name2[letter] != '\0';
		 letter++) {
		if (name1[letter] < name2[letter]) return 1;
		if (name1[letter] > name2[letter]) return 0;
	}
	return 1;
}

void search(list_node* header, char* name, list_node** previous,
			list_node** current) {
	*previous = header;
	*current = header->next;
	while ((*current != NULL) && alphabeticOrder((*current)->data.name, name)) {
		*previous = *current;
		*current = (*current)->next;
	}
}

void delete(list_node* header, char* name) {
	list_node* previous;
	list_node* current;
	search(header, name, &previous, &current);
	if (current != NULL && strcmp(current->data.name, name)) {
		previous->next = current->next;
		free(current);
	}
}

void insert(list_node* header, data_t data) {
	list_node* node = (list_node*)malloc(sizeof(list_node));
	if (node != NULL) {
		list_node* previous;
		list_node* useless;
		search(header, data.name, &previous, &useless);
		node->data = data;
		node->next = previous->next;
		previous->next = node;
	}
}

void printPerson(data_t data) {
	printf("Nome: %sTelemóvel: %d\n\n", data.name, data.phoneNumber);
}

void printListInOrder(list_node* header) {
	list_node* node = header->next;
	while (node != NULL) {
		printPerson(node->data);
		node = node->next;
	}
}

void printListBackwards(list_node* node) {
	if (node->next != NULL) printListBackwards(node->next);
	printPerson(node->data);
}

void error() {
	perror("Algo correu mal.\n");
	exit(1);
}

int main() {
	list_node* header = create();

	int choice = 0;
	do {
		printf("Selecione a operação que deseja:\n");
		printf("1. Inserir uma pessoa.\n");
		printf("2. Tirar uma pessoa pelo nome.\n");
		printf("3. Consultar a lista de pessoas em ordem alfabética.\n");
		printf("4. Consultar a lista de pessoas em ordem contrária à "
			   "alfabética.\n");
		printf("Qualquer outra tecla: sair.\n");
		printf("> ");
		if (scanf("%d", &choice) != 1) error();
		while (getchar() != '\n');

		switch (choice) {
		case 1:
			data_t person;
			printf("Nome da pessoa: ");
			if (fgets(person.name, NAME_LENGTH, stdin) == NULL) error();
			printf("Número de telemóvel da pessoa: ");
			if (scanf("%d", &person.phoneNumber) != 1) error();
			insert(header, person);
			printf("\n");
			break;
		case 2:
			char name[NAME_LENGTH];
			printf("Nome da pessoa: ");
			if (fgets(name, NAME_LENGTH, stdin) == NULL) error();
			delete (header, name);
			printf("\n");
			break;
		case 3:
			printListInOrder(header);
			printf("\n");
			break;
		case 4:
			printListBackwards(header->next);
			printf("\n");
			break;
		default:
			choice = 5;
			break;
		}
	} while (choice != 5);

	header = clean(header);
	return 0;
}
