// Folha 5
// Exercício 14.2.1 e 15.2.2
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256

typedef struct _node_t {
	char* word;
	struct _node_t* next;
} node_t;

void init(node_t** list) {
	*list = NULL;
}

void clean(node_t** list) {
	while (*list != NULL) {
		node_t* node = *list;
		*list = node->next;
		free(node);
	}
	init(list);
}

void lower(char* dest, char* word) {
	for (size_t letter = 0; word[letter] != '\0'; letter++) {
		dest[letter] = tolower(word[letter]);
	}
}

void search(node_t** list, char* word, node_t** prev, node_t** curr) {
	*prev = NULL;
	*curr = *list;
	char lowerWord[MAX_INPUT];
	char lowerCurr[MAX_INPUT];
	lower(lowerWord, word);
	if (*curr != NULL) lower(lowerCurr, (*curr)->word);
	while (*curr != NULL && strcmp(lowerWord, lowerCurr) > 0) {
		*prev = *curr;
		*curr = (*curr)->next;
		if (*curr != NULL) lower(lowerCurr, (*curr)->word);
	}
}

void insert(node_t** list, char* word) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node == NULL) return;
	node->word = word;
	node_t* prev;
	node_t* curr;
	search(list, word, &prev, &curr);
	if (prev == NULL) {
		*list = node;
	} else {
		prev->next = node;
	}
	node->next = curr;
}

void error(char* errorMessage) {
	perror(errorMessage);
	exit(1);
}

bool palindrome(char* palavras) {
	int letraFinal = strlen(palavras) - 1;
	if (palavras[letraFinal] == '\n') letraFinal--;
	int i = 0;
	while (i < letraFinal) {
		if (palavras[i++] != palavras[letraFinal--]) return false;
	}
	return true;
}

void ordenarOrdemAlfabetica(FILE* palavras, node_t** lista) {
	node_t* node = *lista;
	while (node != NULL) {
		fprintf(palavras, "%s\n", node->word);
		node = node->next;
	}
}

void armazenarPalavras(char* input, FILE* palavras) {
	FILE* palindromes = fopen("./palin.txt", "w");
	if (palindromes == NULL) error("Ficheiro \"palavras\" não encontrado.");
	node_t* lista;
	init(&lista);
	char* pPalavra = strtok(input, " ");
	while (pPalavra != NULL) {
		insert(&lista, pPalavra);
		if (palindrome(pPalavra)) fprintf(palindromes, "%s\n", pPalavra);
		pPalavra = strtok(NULL, " ");
	}
	ordenarOrdemAlfabetica(palavras, &lista);
	fclose(palindromes);
	clean(&lista);
}

void palavraMaisCaracteres(FILE* palavras) {
	char palavraAtual[MAX_INPUT];
	char palavraMaior[MAX_INPUT] = "";
	fseek(palavras, 0, SEEK_SET);
	while (fgets(palavraAtual, MAX_INPUT, palavras) != NULL) {
		if (strlen(palavraAtual) > strlen(palavraMaior)) {
			strcpy(palavraMaior, palavraAtual);
		}
	}
	printf("Palavra maior: %s", palavraMaior);
}

int main() {
	FILE* palavras = fopen("./palavras.txt", "r+");
	if (palavras == NULL) {
		error("Ficheiro \"palavras.txt\" não encontrado.");
	}
	printf("Insire a sua frase:\n");
	char input[MAX_INPUT];
	if (fgets(input, MAX_INPUT, stdin) == NULL) {
		error("A leitura na consola foi feita sem sucesso.\n");
	}
	armazenarPalavras(input, palavras);
	palavraMaisCaracteres(palavras);
	fclose(palavras);
	return 0;
}
