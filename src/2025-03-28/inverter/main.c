// Folha 4
// Exercício 12.1.2
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int numero;
} data_t;

typedef struct _s_pile_t {
	data_t data;
	struct _s_pile_t* next;
} s_pile_t;

void init(s_pile_t** stackPtr) {
	*stackPtr = NULL;
}

int empty(s_pile_t** stackPtr) {
	return *stackPtr == NULL;
}

void push(s_pile_t** stackPtr, data_t data) {
	s_pile_t* pile = (s_pile_t*)malloc(sizeof(s_pile_t));
	if (pile != NULL) {
		pile->data = data;
		pile->next = *stackPtr;
		*stackPtr = pile;
	}
}

void pop(s_pile_t** stackPtr) {
	if (*stackPtr != NULL) {
		s_pile_t* node = *stackPtr;
		*stackPtr = (*stackPtr)->next;
		free(node);
	}
}

data_t front(s_pile_t** stackPtr) {
	data_t pile = { -1 };
	if (!empty(stackPtr)) pile = (*stackPtr)->data;
	return pile;
}

void clean(s_pile_t** stackPtr) {
	while (!empty(stackPtr)) pop(stackPtr);
	init(stackPtr);
}

int perguntarInteiro(int min, int max) {
	int valor = min - 1;
	while (valor < min || valor > max) {
		if (scanf("%d", &valor) != 1) {
			perror("Algo correu mal.\n");
			exit(1);
		}
	}
	return valor;
}

void store(int tamanho, s_pile_t** stackPtr) {
	for (int i = 0; i < tamanho; i++) {
		printf("Elemento %d: ", i + 1);
		int numero = perguntarInteiro(-2100000000, 2100000000);
		data_t data = { numero };
		push(stackPtr, data);
	}
}

void lerStack(s_pile_t** stackPtr) {
	while (!empty(stackPtr)) {
		int numero = front(stackPtr).numero;
		pop(stackPtr);
		printf("%d ", numero);
	}
	printf("\n");
}

int main() {
	s_pile_t* stackPtr;
	init(&stackPtr);
	printf("Número de elementos do stack: ");
	int tamanho = perguntarInteiro(1, 100);

	store(tamanho, &stackPtr);
	lerStack(&stackPtr);

	clean(&stackPtr);
	return 0;
}
