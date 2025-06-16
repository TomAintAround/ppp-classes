// Folha 5
// Exercício 16.1.2
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_SIZE 1024

typedef struct SNode {
	char word[MAX_WORD_SIZE];
	struct SNode* next;
} Node;

void init(Node** list) {
	*list = NULL;
}

void clean(Node** list) {
	while (*list != NULL) {
		Node* node = *list;
		*list = node->next;
		free(node);
	}
	init(list);
}

void lower(char* dest, const char* word) {
	for (size_t letter = 0; word[letter] != '\0'; letter++) {
		dest[letter] = tolower(word[letter]);
	}
}

void search(Node** list, const char* word, Node** prev, Node** curr) {
	*prev = NULL;
	*curr = *list;
	char lowerWord[MAX_WORD_SIZE];
	char lowerCurr[MAX_WORD_SIZE];
	lower(lowerWord, word);
	if (*curr != NULL) lower(lowerCurr, (*curr)->word);
	while (*curr != NULL && strcmp(lowerWord, lowerCurr) > 0) {
		*prev = *curr;
		*curr = (*curr)->next;
		if (*curr != NULL) lower(lowerCurr, (*curr)->word);
	}
}

void insert(Node** list, const char* word, const bool alphabeticOrder) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) return;
	strcpy(node->word, word);
	if (alphabeticOrder) {
		Node* prev;
		Node* curr;
		search(list, word, &prev, &curr);
		if (prev == NULL) {
			*list = node;
		} else {
			prev->next = node;
		}
		node->next = curr;
	} else {
		node->next = NULL;
		if (*list == NULL) {
			*list = node;
		} else {
			Node* auxNode = *list;
			while (auxNode->next != NULL) auxNode = auxNode->next;
			auxNode->next = node;
		}
	}
}

void error(const char* errorMessage) {
	perror(errorMessage);
	exit(1);
}

void errorOpeningFile(const char* fileName) {
	char errorMessage[128] = "";
	sprintf(errorMessage, "Ficheiro \"%s\" não foi aberto com sucesso.\n", fileName);
	error(errorMessage);
}

bool isPalindrome(const char* word) {
	char lowerWord[MAX_WORD_SIZE] = "";
	lower(lowerWord, word);
	for (size_t i = 0; i < strlen(lowerWord); i++) {
		if (lowerWord[i] != lowerWord[strlen(lowerWord) - 1 - i]) return false;
	}
	return true;
}

int main(int argc, char* argv[]) {
	if (argc <= 1) error("É preciso de pelo menos 1 argumento.\n");
	FILE* origin = NULL;
	FILE* dest = NULL;
	FILE* palin = NULL;
	bool lineByLine = false;
	bool showBiggestWord = false;
	bool alphabeticOrder = false;
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-o") == 0 && origin == NULL) {
			if (i + 1 >= argc)
				error("Não foi encontrado nenhum ficheiro de origem.\n");
			origin = fopen(argv[i + 1], "r");
			if (origin == NULL) errorOpeningFile(argv[i + 1]);
			i++;
			continue;
		} else if (strcmp(argv[i], "-o") == 0 && origin != NULL) {
			error("Não pode abrir o mesmo ficheiro 2 vezes.\n");
		}

		if (strcmp(argv[i], "-d") == 0 && dest == NULL) {
			if (i + 1 >= argc)
				error("Não foi encontrado nenhum ficheiro de destino.\n");
			dest = fopen(argv[i + 1], "w");
			if (dest == NULL) errorOpeningFile(argv[i + 1]);
			i++;
			continue;
		} else if (strcmp(argv[i], "-d") == 0 && dest != NULL) {
			error("Não pode haver 2 destinos.\n");
		}

		if (strcmp(argv[i], "-p") == 0 && palin == NULL) {
			if (i + 1 >= argc)
				error("Não foi encontrado nenhum ficheiro de palindromas.\n");
			palin = fopen(argv[i + 1], "w");
			if (palin == NULL) errorOpeningFile(argv[i + 1]);
			i++;
			continue;
		} else if (strcmp(argv[i], "-p") == 0 && palin != NULL) {
			error("Não pode haver 2 ficheiros de palindromas.\n");
		}

		if (strcmp(argv[i], "-l") == 0) {
			lineByLine = true;
			continue;
		}

		if (strcmp(argv[i], "-c") == 0) {
			showBiggestWord = true;
			continue;
		}

		if (strcmp(argv[i], "-a") == 0) {
			alphabeticOrder = true;
			continue;
		}

		error("Argumentos inválidos.\n");
	}
	if (origin == NULL) error("Não foi submitido um ficheiro de origem.\n");
	if (dest == NULL) dest = fopen("./dest.txt", "w");
	if (palin == NULL) palin = fopen("./palin.txt", "w");

	Node* list;
	init(&list);
	char line[MAX_WORD_SIZE] = "";
	char biggestWord[MAX_WORD_SIZE] = "";
	while (fgets(line, MAX_WORD_SIZE, origin)) {
		line[strcspn(line, "\n")] = '\0';
		char* word = strtok(line, " ");
		while (word != NULL) {
			if (showBiggestWord && strlen(word) > strlen(biggestWord)) {
				strcpy(biggestWord, word);
			}
			insert(&list, word, alphabeticOrder);
			word = strtok(NULL, " ");
		}
	}
	if (showBiggestWord) printf("Maior palavra: \"%s\".\n", biggestWord);

	Node* node = list;
	char separator = '\0';
	if (lineByLine) {
		separator = '\n';
	} else {
		separator = ' ';
	}
	while (node != NULL) {
		fprintf(dest, "%s%c", node->word, separator);
		if (isPalindrome(node->word))
			fprintf(palin, "%s%c", node->word, separator);
		node = node->next;
	}

	clean(&list);
	fclose(origin);
	fclose(dest);
	fclose(palin);
	return 0;
}
