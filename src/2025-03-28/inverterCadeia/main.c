// Folha 4
// Exercício 12.2.3
#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 256

typedef struct {
	char character;
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
	if (!empty(stackPtr)) {
		s_pile_t* pile = *stackPtr;
		*stackPtr = pile->next;
		free(pile);
	}
}

data_t front(s_pile_t** stackPtr) {
	data_t data = { 'a' };
	if (!empty(stackPtr)) data = (*stackPtr)->data;
	return data;
}

void clean(s_pile_t** stackPtr) {
	while (!empty(stackPtr)) pop(stackPtr);
	init(stackPtr);
}

void store(s_pile_t** stackPtr, char* string) {
	for (int letter = 0; string[letter] != '\n' && string[letter] != '\0'; letter++) {
		data_t data = { string[letter] };
		push(stackPtr, data);
	}
	data_t data = { '\0' };
	push(stackPtr, data);
}

void readInverse(s_pile_t** stackPtr) {
	while (!empty(stackPtr)) {
		char letter = front(stackPtr).character;
		pop(stackPtr);
		printf("%c", letter);
	}
	printf("\n");
}

int main() {
	s_pile_t* stack;
	init(&stack);
	char string[STRING_SIZE];
	printf("Insire a sua string:\n");
	if (fgets(string, STRING_SIZE, stdin) == NULL) {
		printf("Algo correu mal.\n");
		exit(1);
	}
	store(&stack, string);
	readInverse(&stack);

	clean(&stack);
	return 0;
}
