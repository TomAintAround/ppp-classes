// Folha 5
// Exercício 15.1.1 e 15.1.2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_NOME 50

typedef struct {
	char nome[TAMANHO_NOME];
	int anoNascimento;
} pessoa_t;

typedef struct _node_t {
	pessoa_t pessoa;
	struct _node_t* next;
} node_t;

void init(node_t** list) {
	*list = NULL;
}

int empty(node_t** list) {
	return *list == NULL;
}

void clean(node_t** list) {
	while (*list != NULL) {
		node_t* node = *list;
		*list = node->next;
		free(node);
	}
	init(list);
}

void search(node_t** list, char* nome, node_t** previous, node_t** current) {
	*previous = NULL;
	*current = *list;
	while (*current != NULL && strcmp(nome, (*current)->pessoa.nome) > 0) {
		*previous = *current;
		*current = (*current)->next;
	}
}

void insert(node_t** list, pessoa_t pessoa) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node == NULL) return;
	node->pessoa = pessoa;
	node_t* previous;
	node_t* current;
	search(list, pessoa.nome, &previous, &current);
	if (previous == NULL) {
		*list = node;
	} else {
		previous->next = node;
	}
	node->next = current;
}

void erro(char* mensagemErro) {
	perror(mensagemErro);
	exit(-1);
}

int perguntarInteiro(int min, int max) {
	int resultado = min - 1;
	while (resultado < min || resultado > max) {
		if (scanf("%d", &resultado) != 1) erro("Tem de inserir um inteiro.\n");
		if (resultado < min) printf("Insire um número maior que %d.\n", min);
		if (resultado > max) printf("Insire um número menor que %d.\n", max);
	}
	while (getchar() != '\n');
	return resultado;
}

void inserirPessoas(node_t** lista) {
	printf("Insire o número de pessoas: ");
	int numeroPessoas = perguntarInteiro(1, 200);
	for (int i = 0; i < numeroPessoas; i++) {
		pessoa_t pessoa;
		printf("Insire o nome da pessoa %d: ", i + 1);
		if (fgets(pessoa.nome, TAMANHO_NOME, stdin) == NULL) {
			erro("Algo correu mal.\n");
		}
		pessoa.nome[strlen(pessoa.nome) - 1] = '\0';
		printf("Insire o ano de nascimento da pessoa %d: ", i + 1);
		pessoa.anoNascimento = perguntarInteiro(-2100000000, 2100000000);
		insert(lista, pessoa);
	}
}

void escreverBinario(FILE* ficheiro, node_t** lista) {
	node_t* node = *lista;
	while (node != NULL) {
		fwrite(node->pessoa.nome, sizeof(char), TAMANHO_NOME, ficheiro);
		fwrite(&node->pessoa.anoNascimento, sizeof(int), 1, ficheiro);
		node = node->next;
	}
}

void lerOrdemInversa(FILE* ficheiro) {
	fseek(ficheiro, -TAMANHO_NOME - sizeof(int), SEEK_END);
	do {
		char nome[TAMANHO_NOME];
		int anoNascimento = 0;
		fread(nome, sizeof(char), TAMANHO_NOME, ficheiro);
		fread(&anoNascimento, sizeof(int), 1, ficheiro);
		printf("%s: %d\n", nome, anoNascimento);
	} while (fseek(ficheiro, 2 * (-TAMANHO_NOME - sizeof(int)), SEEK_CUR) == 0);
}

int main() {
	FILE* ficheiro = fopen("./ficheiro", "wb+");
	if (ficheiro == NULL) erro("Não foi encontrado o ficheiro.\n");
	node_t* lista;
	init(&lista);
	inserirPessoas(&lista);
	escreverBinario(ficheiro, &lista);
	lerOrdemInversa(ficheiro);

	fclose(ficheiro);
	clean(&lista);
	return 0;
}
