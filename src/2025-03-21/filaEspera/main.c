// Folha 4
// Exercício 11.3.3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEM_TYPE char*
#define STRING_SIZE 16

typedef struct node_type {
	ITEM_TYPE condutor;
	struct node_type* next;
} QNODE_TYPE;

typedef QNODE_TYPE* QNODE_PTR;

typedef struct {
	QNODE_PTR rear;
	QNODE_PTR front;
} Q_TYPE;

void init(Q_TYPE* queue) {
	queue->rear = NULL;
	queue->front = NULL;
}

int empty(Q_TYPE* queue) {
	return queue->front == NULL;
}

void push(Q_TYPE* queue, ITEM_TYPE condutor) {
	QNODE_PTR node = (QNODE_PTR)malloc(sizeof(QNODE_TYPE));
	if (node != NULL) {
		node->condutor = condutor;
		node->next = NULL;

		if (!empty(queue))
			queue->rear->next = node;
		else
			queue->front = node;
		queue->rear = node;
	}
}

void pop(Q_TYPE* queue) {
	if (!empty(queue)) {
		QNODE_PTR node = queue->front;
		queue->front = node->next;
		free(node);
		if (empty(queue)) queue->rear = NULL;
	}
}

ITEM_TYPE front(Q_TYPE* queue) {
	ITEM_TYPE condutor = NULL;
	if (!empty(queue)) condutor = queue->front->condutor;
	return condutor;
}

void clean(Q_TYPE* queue) {
	while (!empty(queue)) pop(queue);
	init(queue);
}

void erro() {
	printf("Algo correu mal.\n");
	exit(-1);
}

int perguntarInt(int min, int max) {
	int valor = min - 1;
	int invalido = 0;
	do {
		if (scanf("%d", &valor) != 1) erro();
		while (getchar() != '\n');
		invalido = valor < min || valor > max;
		if (invalido) printf("Insire um valor válido ou não muito grande: ");
	} while (invalido);
	return valor;
}

void rotacao(Q_TYPE** dias, char* condutor, int dia) {
	int diaReal = dia - 1;
	int diaAnterior = (diaReal - 1) % 7;
	while (strcmp(front(dias[diaAnterior]), condutor) != 0) {
		for (int i = 0; i < 7; i++) {
			push(dias[(i + 1) % 7], front(dias[i]));
			pop(dias[i]);
		}
	}
	push(dias[diaReal], front(dias[diaAnterior]));
	pop(dias[diaAnterior]);
}

int main() {
	Q_TYPE* dias[7];
	for (int i = 0; i < 7; i++) {
		dias[i] = (Q_TYPE*)malloc(sizeof(Q_TYPE));
		init(dias[i]);
		printf("Número de elementos da fila %d: ", i + 1);
		int numeroElementos = perguntarInt(1, 100);
		for (int _ = 0; _ < numeroElementos; _++) {
			printf("Insire um nome para a fila %d: ", i + 1);
			char nome[STRING_SIZE];
			if (fgets(nome, STRING_SIZE, stdin) == NULL) erro();
			push(dias[i], strdup(nome));
		}
		printf("\n");
	}

	char condutor[STRING_SIZE];
	printf("Insire o nome de quem quer rodar. ");
	if (fgets(condutor, STRING_SIZE, stdin) == NULL) erro();
	printf("Em que dia da semana o quer mover? ");
	int diaSemana = perguntarInt(1, 7);
	rotacao(dias, condutor, diaSemana);
	printf("%s", front(dias[diaSemana - 1]));

	for (int i = 0; i < 7; i++) {
		clean(dias[i]);
		free(dias[i]);
	}
	return 0;
}
