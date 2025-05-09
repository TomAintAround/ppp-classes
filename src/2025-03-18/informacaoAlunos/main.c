// Folha 4
// Exercíco 11.2.3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUMERO_ALUNOS 20
#define COMPRIMENTO_NOME 16
#define NUMERO_TESTES 3

typedef struct {
	char nome[COMPRIMENTO_NOME];
	int numero;
	int testes[NUMERO_TESTES];
} data_t;

typedef struct _q_node_t {
	data_t data;
	struct _q_node_t* next;
} q_node_t;

typedef struct {
	q_node_t* first;
	q_node_t* last;
	int n;
} queue_t;

void init(queue_t* queue) {
	queue->first = NULL;
	queue->last = NULL;
}

int empty(queue_t* queue) {
	return queue->first == NULL;
}

void push(queue_t* queue, data_t data) {
	q_node_t* node = (q_node_t*)malloc(sizeof(q_node_t));
	if (node != NULL) {
		node->data = data;
		node->next = NULL;

		if (!empty(queue)) {
			queue->last->next = node;
		} else {
			queue->first = node;
		}
		queue->last = node;
	}
}

void pop(queue_t* queue) {
	if (!empty(queue)) {
		q_node_t* node = queue->first;
		queue->first = node->next;
		free(node);
		if (empty(queue)) queue->last = NULL;
	}
}

data_t front(queue_t* queue) {
	data_t data;
	if (!empty(queue)) data = queue->first->data;
	return data;
}

void clear(queue_t* queue) {
	while (!empty(queue)) pop(queue);
	init(queue);
}

void armazenar(queue_t* fila) {
	srand(time(NULL));
	char nomes[NUMERO_ALUNOS][COMPRIMENTO_NOME] = {
		"Tomás",   "Gabriel",  "Simão", "Afonso",	 "Pedro",
		"Diogo",   "André",	   "João",	"Guilherme", "Gonçalo",
		"Mariana", "Henrique", "Joana", "Mara",		 "Lara",
		"Daniela", "Patrícia", "Vanda", "Sónia",	 "Sara"
	};
	for (int i = 0; i < NUMERO_ALUNOS; i++) {
		data_t aluno;
		strcpy(aluno.nome, nomes[i]);
		aluno.numero = i + 1;
		for (int nota = 0; nota < NUMERO_TESTES; nota++) {
			aluno.testes[nota] = rand() % 101;
		}
		push(fila, aluno);
	}
}

double media(queue_t* fila, data_t* melhorAluno) {
	double melhorMedia = 0;
	while (!empty(fila)) {
		double media = 0;
		data_t aluno = front(fila);
		pop(fila);
		for (int nota = 0; nota < NUMERO_TESTES; nota++) {
			media += aluno.testes[nota];
		}
		if (media > melhorMedia) {
			melhorMedia = media;
			strcpy(melhorAluno->nome, aluno.nome);
			melhorAluno->numero = aluno.numero;
			for (int nota = 0; nota < NUMERO_TESTES; nota++) {
				melhorAluno->testes[nota] = aluno.testes[nota];
			}
		}
	}
	return melhorMedia / NUMERO_TESTES;
}

int main() {
	queue_t fila;
	init(&fila);
	armazenar(&fila);
	data_t melhorAluno;
	double melhorMedia = media(&fila, &melhorAluno);
	printf("A melhor média é %.1f, do/a aluno/a %s, número %d.\n", melhorMedia,
		   melhorAluno.nome, melhorAluno.numero);

	clear(&fila);
	return 0;
}
