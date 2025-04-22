// Folha 4
// Exercício 13.3.2
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
	int numSocio, idade;
	char nome[STRING_SIZE], profissao[STRING_SIZE];
	char morada[STRING_SIZE];
	data_t dataInscricao;
	bool quota;
} socio_t;

typedef struct _list_node_t {
	socio_t socio;
	struct _list_node_t* proxNome;
	struct _list_node_t* proxAdesao;
} list_node_t;

typedef struct {
	list_node_t* frontNome;
	list_node_t* frontAdesao;
} list_t;

void init(list_t* list) {
	list->frontNome = NULL;
	list->frontAdesao = NULL;
}

void searchNome(list_t* list, char* nome, list_node_t** previous,
				list_node_t** current) {
	*previous = NULL;
	*current = list->frontNome;
	while (*current != NULL && strcmp((*current)->socio.nome, nome) < 0) {
		*previous = *current;
		*current = (*current)->proxNome;
	}
}

bool ordemAdesao(data_t data1, data_t data2) {
	if (data1.ano > data2.ano) return false;
	if (data1.ano < data2.ano) return true;

	if (data1.mes > data2.mes) return false;
	if (data1.mes < data2.mes) return true;

	if (data1.dia > data2.dia) return false;
	return true;
}

void searchAdesao(list_t* list, data_t data, list_node_t** previous,
				  list_node_t** current) {
	*previous = NULL;
	*current = list->frontAdesao;
	while (*current != NULL &&
		   ordemAdesao((*current)->socio.dataInscricao, data)) {
		*previous = *current;
		*current = (*current)->proxAdesao;
	}
}

void inserir(list_t* list, socio_t socio) {
	list_node_t* node = (list_node_t*)malloc(sizeof(list_node_t));
	if (node != NULL) {
		node->socio = socio;
		list_node_t* previous;
		list_node_t* current;
		searchNome(list, socio.nome, &previous, &current);
		if (previous == NULL) {
			list->frontNome = node;
		} else {
			node->proxNome = current;
		}
		node->proxNome = current;
		searchAdesao(list, socio.dataInscricao, &previous, &current);
		if (previous == NULL) {
			list->frontAdesao = node;
		} else {
			previous->proxAdesao = node;
		}
		node->proxAdesao = current;
	}
}

void printSocio(socio_t socio) {
	printf("Nome: %s", socio.nome);
	printf("Profissão: %s", socio.profissao);
	printf("Morada: %s", socio.morada);
	printf("Idade: %d\n", socio.idade);
	printf("Número de sócio: %d\n", socio.numSocio);
	data_t data = socio.dataInscricao;
	printf("Data de inscrição de sócio: %d/%d/%d\n", data.dia, data.mes,
		   data.ano);
	printf("\n");
}

void printListaNomes(list_t* lista) {
	list_node_t* node = lista->frontNome;
	while (node != NULL) {
		printSocio(node->socio);
		node = node->proxNome;
	}
}

void printListaDatas(list_t* lista) {
	list_node_t* node = lista->frontAdesao;
	while (node != NULL) {
		printSocio(node->socio);
		node = node->proxAdesao;
	}
}

void clean(list_t* lista) {
	while (lista->frontNome != NULL) {
		list_node_t* node = lista->frontNome;
		lista->frontNome = node->proxNome;
		free(node);
	}
	init(lista);
}

void erro(char* mensagem) {
	perror(mensagem);
	exit(1);
}

void inserirSocio(list_t* lista) {
	socio_t socio;
	char nome[STRING_SIZE], profissao[STRING_SIZE], morada[STRING_SIZE];
	int idade = 0, numSocio = 0;
	data_t data;
	int quota = true;

	printf("Nome do sócio: ");
	if (fgets(nome, STRING_SIZE, stdin) == NULL) erro("Algo correu mal.\n");
	printf("Profissão do sócio: ");
	if (fgets(profissao, STRING_SIZE, stdin) == NULL)
		erro("Algo correu mal.\n");
	printf("Morada do sócio: ");
	if (fgets(morada, STRING_SIZE, stdin) == NULL) erro("Algo correu mal.\n");
	printf("Idade do sócio: ");
	if (scanf("%d", &idade) != 1) erro("Tem de inserir um inteiro.\n");
	printf("Número do sócio: ");
	if (scanf("%d", &numSocio) != 1) erro("Tem de inserir um inteiro.\n");
	printf("Dia do mês da entrada to sócio: ");
	if (scanf("%d", &data.dia) != 1) erro("Tem de inserir um inteiro.\n");
	printf("Mês da entrada to sócio: ");
	if (scanf("%d", &data.mes) != 1) erro("Tem de inserir um inteiro.\n");
	printf("Ano da entrada to sócio: ");
	if (scanf("%d", &data.ano) != 1) erro("Tem de inserir um inteiro.\n");
	printf("Compriu a quota (1 se sim, 0 se não): ");
	if (scanf("%d", &quota) != 1) erro("Tem de inserir um inteiro.\n");

	strcpy(socio.nome, nome);
	strcpy(socio.profissao, profissao);
	strcpy(socio.morada, morada);
	socio.idade = idade;
	socio.numSocio = numSocio;
	socio.dataInscricao = data;
	socio.quota = quota;

	inserir(lista, socio);
}

void printSocioNumero(list_t* lista) {
	int numero = 0;
	printf("Número do sócio: ");
	if (scanf("%d", &numero) != 1) erro("Tem de inserir um inteiro.\n");
	list_node_t* node = lista->frontNome;
	while (node != NULL) {
		if (node->socio.numSocio == numero) printSocio(node->socio);
		node = node->proxNome;
	}
}

void printSocioNome(list_t* lista) {
	char nome[STRING_SIZE];
	printf("Nome do sócio: ");
	if (fgets(nome, STRING_SIZE, stdin) == NULL) erro("Algo correu mal.\n");
	list_node_t* node = lista->frontNome;
	while (node != NULL) {
		if (strcmp(node->socio.nome, nome) == 0) printSocio(node->socio);
		node = node->proxNome;
	}
}

void printSocioMorada(list_t* lista) {
	char morada[STRING_SIZE];
	printf("Morada do sócio: ");
	if (fgets(morada, STRING_SIZE, stdin) == NULL) erro("Algo correu mal.\n");
	list_node_t* node = lista->frontNome;
	while (node != NULL) {
		if (strcmp(node->socio.morada, morada) == 0) printSocio(node->socio);
		node = node->proxNome;
	}
}

void printSocioQuotaAtrasada(list_t* lista) {
	list_node_t* node = lista->frontNome;
	while (node != NULL) {
		if (!node->socio.quota) printSocio(node->socio);
		node = node->proxNome;
	}
}

void removerSocio(list_t* lista) {
	char nome[STRING_SIZE];
	printf("Nome do sócio: ");
	if (fgets(nome, STRING_SIZE, stdin) == NULL) {
		erro("Tem de inserir um inteiro.\n");
	}
	list_node_t* previous;
	list_node_t* current;
	searchNome(lista, nome, &previous, &current);
	if (strcmp(current->socio.nome, nome) == 0) {
		if (previous == NULL) {
			lista->frontNome = current->proxNome;
		} else if (current != NULL) {
			previous->proxNome = current->proxNome;
		}
		free(current);
	}
}

int main() {
	list_t lista;
	init(&lista);

	int escolha = 0;
	do {
		printf("Escolha 1 das seguintes opções:\n");
		printf("1. Inserir um sócio.\n");
		printf("2. Visualizar um sócio através do número.\n");
		printf("3. Visualizar um sócio através do nome.\n");
		printf("4. Visualizar um sócio através da morada.\n");
		printf("5. Mostrar os sócios com as quotas atrasadas.\n");
		printf("6. Remover um sócio da lista.\n");
		printf("7. Listar os sócios de ordem alfabética.\n");
		printf("8. Listar os sócios de ordem decrescente da data de "
			   "inscrição.\n");
		printf("Qualquer outro número: terminar.\n");
		printf("> ");
		if (scanf("%d", &escolha) != 1) erro("Tem de inserir um número.\n");
		while (getchar() != '\n');

		switch (escolha) {
		case 1:
			inserirSocio(&lista);
			break;
		case 2:
			printSocioNumero(&lista);
			break;
		case 3:
			printSocioNome(&lista);
			break;
		case 4:
			printSocioMorada(&lista);
			break;
		case 5:
			printSocioQuotaAtrasada(&lista);
			break;
		case 6:
			removerSocio(&lista);
			break;
		case 7:
			printListaNomes(&lista);
			break;
		case 8:
			printListaDatas(&lista);
			break;
		default:
			escolha = 0;
			break;
		}

		printf("\n");
	} while (escolha != 0);

	clean(&lista);
	return 0;
}
