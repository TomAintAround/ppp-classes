// Folha 4
// Exercício 13.3.3
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 64

typedef struct {
	int dia, mes, ano;
} data_t;

typedef struct {
	char nome[STRING_SIZE];
	int numero;
	data_t dataNascimento;
	int pontuacao;
} atleta_t;

typedef struct _node_t {
	atleta_t atleta;
	struct _node_t* proxNome;
	struct _node_t* proxNum;
	struct _node_t* proxNascimento;
	struct _node_t* proxPontuacao;
} node_t;

typedef struct {
	node_t* frontNome;
	node_t* frontNum;
	node_t* frontNascimento;
	node_t* frontPontuacao;
} list_t;

void init(list_t* list) {
	list->frontNome = NULL;
	list->frontNum = NULL;
	list->frontNascimento = NULL;
	list->frontPontuacao = NULL;
}

void clean(list_t* list) {
	while (list->frontNome != NULL) {
		node_t* node = list->frontNome;
		list->frontNome = node->proxNome;
		free(node);
	}
	init(list);
}

void lower(char* string) {
	for (int letra = 0; string[letra] != '\n' && string[letra] != '\0';
		 letra++) {
		string[letra] = tolower(string[letra]);
	}
}

bool ordemAlfabetica(char* string1, char* string2) {
	char tempString1[STRING_SIZE];
	char tempString2[STRING_SIZE];
	strcpy(tempString1, string1);
	strcpy(tempString2, string2);
	int tamanhoMenor = strlen(tempString1) < strlen(tempString2)
						   ? strlen(tempString1)
						   : strlen(tempString2);
	for (int letra = 0; letra < tamanhoMenor; letra++) {
		if (tempString1[letra] < tempString2[letra]) return true;
		if (tempString1[letra] > tempString2[letra]) return false;
	}
	return true;
}

bool ordemData(data_t data1, data_t data2) {
	if (data1.ano < data2.ano) return true;
	if (data1.ano > data2.ano) return false;

	if (data1.mes < data2.mes) return true;
	if (data1.mes > data2.mes) return false;

	if (data1.dia < data2.dia) return true;
	return false;
}

void searchNome(list_t* list, char* nome, node_t** previous, node_t** current) {
	*previous = NULL;
	*current = list->frontNome;
	while (*current != NULL && ordemAlfabetica((*current)->atleta.nome, nome)) {
		*previous = *current;
		*current = (*current)->proxNome;
	}
}

void searchNum(list_t* list, int numero, node_t** previous, node_t** current) {
	*previous = NULL;
	*current = list->frontNum;
	while (*current != NULL && (*current)->atleta.numero < numero) {
		*previous = *current;
		*current = (*current)->proxNum;
	}
}

void searchNascimento(list_t* list, data_t dataNascimento, node_t** previous,
					  node_t** current) {
	*previous = NULL;
	*current = list->frontNascimento;
	while (*current != NULL &&
		   ordemData((*current)->atleta.dataNascimento, dataNascimento)) {
		*previous = *current;
		*current = (*current)->proxNascimento;
	}
}

void searchPontuacao(list_t* list, int pontuacao, node_t** previous,
					 node_t** current) {
	*previous = NULL;
	*current = list->frontPontuacao;
	while (*current != NULL && (*current)->atleta.pontuacao < pontuacao) {
		*previous = *current;
		*current = (*current)->proxPontuacao;
	}
}

void inserir(list_t* list, atleta_t atleta) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node == NULL) return;
	node->atleta = atleta;
	node_t* previous;
	node_t* current;

	searchNome(list, atleta.nome, &previous, &current);
	if (previous == NULL) {
		list->frontNome = node;
	} else {
		previous->proxNome = node;
	}
	node->proxNome = current;

	searchNum(list, atleta.numero, &previous, &current);
	if (previous == NULL) {
		list->frontNum = node;
	} else {
		previous->proxNum = node;
	}
	node->proxNum = current;

	searchNascimento(list, atleta.dataNascimento, &previous, &current);
	if (previous == NULL) {
		list->frontNascimento = node;
	} else {
		previous->proxNascimento = node;
	}
	node->proxNascimento = current;

	searchPontuacao(list, atleta.pontuacao, &previous, &current);
	if (previous == NULL) {
		list->frontPontuacao = node;
	} else {
		previous->proxPontuacao = node;
	}
	node->proxPontuacao = current;
}

void printAtleta(atleta_t atleta) {
	data_t data = atleta.dataNascimento;
	printf("Nome: %s", atleta.nome);
	printf("Número: %d\n", atleta.numero);
	printf("Data de nascimento: %d/%d/%d\n", data.dia, data.mes, data.ano);
	printf("Pontuação: %d\n", atleta.pontuacao);
	printf("\n");
}

void printListaNome(list_t* list) {
	node_t* node = list->frontNome;
	while (node != NULL) {
		printAtleta(node->atleta);
		node = node->proxNome;
	}
}

void printListaNum(list_t* list) {
	node_t* node = list->frontNum;
	while (node != NULL) {
		printAtleta(node->atleta);
		node = node->proxNum;
	}
}

void printListaNascimento(list_t* list) {
	node_t* node = list->frontNascimento;
	while (node != NULL) {
		printAtleta(node->atleta);
		node = node->proxNascimento;
	}
}

void printListaPontuacao(list_t* list) {
	node_t* node = list->frontPontuacao;
	while (node != NULL) {
		printAtleta(node->atleta);
		node = node->proxPontuacao;
	}
}

void erro(char* mensagem) {
	perror(mensagem);
	exit(1);
}

void inserirAtleta(list_t* list) {
	atleta_t atleta;
	printf("Insire o nome do atleta: ");
	if (fgets(atleta.nome, STRING_SIZE, stdin) == NULL)
		erro("Algo correu mal.\n");
	printf("Insire o número do atleta: ");
	if (scanf("%d", &atleta.numero) != 1) erro("Algo correu mal.\n");
	printf("Insire o dia do nascimento do atleta: ");
	if (scanf("%d", &atleta.dataNascimento.dia) != 1)
		erro("Algo correu mal.\n");
	printf("Insire o mês do nascimento do atleta: ");
	if (scanf("%d", &atleta.dataNascimento.mes) != 1)
		erro("Algo correu mal.\n");
	printf("Insire o ano do nascimento do atleta: ");
	if (scanf("%d", &atleta.dataNascimento.ano) != 1)
		erro("Algo correu mal.\n");
	printf("Insire a pontuação do atleta: ");
	if (scanf("%d", &atleta.pontuacao) != 1) erro("Algo correu mal.\n");

	inserir(list, atleta);
}

int main() {
	list_t list;
	init(&list);
	int escolha = 0;

	do {
		printf("Selecione uma das seguintes opções.\n");
		printf("1. Inserir um atleta.\n");
		printf("2. Ver todos os atletas por ordem alfabética.\n");
		printf("3. Ver todos os atletas por ordem crescente dos números.\n");
		printf("4. Ver todos os atletas por ordem crescente das datas de "
			   "nascimento.\n");
		printf("5. Ver todos os atletas por ordem crescente das pontuações.\n");
		printf("Qualquer outra letra: terminar o programa.\n");
		printf("> ");
		if (scanf("%d", &escolha) != 1) erro("Tem de inserir um inteiro.\n");
		while (getchar() != '\n');

		switch (escolha) {
		case 1:
			inserirAtleta(&list);
			break;
		case 2:
			printListaNome(&list);
			break;
		case 3:
			printListaNum(&list);
			break;
		case 4:
			printListaNascimento(&list);
			break;
		case 5:
			printListaPontuacao(&list);
			break;
		default:
			escolha = 0;
			break;
		}

		printf("\n");
	} while (escolha != 0);

	clean(&list);
	return 0;
}
