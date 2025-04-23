#include <stdio.h>
#include <stdlib.h>

typedef struct _node_t {
	int number;
	struct _node_t* left;
	struct _node_t* right;
} node_t;

void init(node_t** root) {
	*root = NULL;
}

int empty(node_t** root) {
	return *root == NULL;
}

void clean(node_t* node) {
	if (node->left != NULL) clean(node->left);
	if (node->right != NULL) clean(node->right);
	free(node);
}

void search(node_t** previous, int number) {
	if (*previous == NULL) return;
	if (number < (*previous)->number && (*previous)->left != NULL) {
		*previous = (*previous)->left;
		search(previous, number);
	} else if (number > (*previous)->number && (*previous)->right != NULL) {
		*previous = (*previous)->right;
		search(previous, number);
	}
}

void push(node_t** root, int number) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node == NULL) return;
	node->number = number;
	node->left = NULL;
	node->right = NULL;

	node_t* previous = *root;
	search(&previous, number);
	if (previous == NULL) {
		*root = node;
		return;
	}
	if (number < previous->number) {
		previous->left = node;
	} else if (number > previous->number) {
		previous->right = node;
	} else {
		free(node);
		return;
	}
}

void inOrderTraversal(node_t* node) {
	if (node->left != NULL) inOrderTraversal(node->left);
	printf("%d ", node->number);
	if (node->right != NULL) inOrderTraversal(node->right);
}

void preOrderTraversal(node_t* node) {
	printf("%d ", node->number);
	if (node->left != NULL) preOrderTraversal(node->left);
	if (node->right != NULL) preOrderTraversal(node->right);
}

void postOrderTraversal(node_t* node) {
	if (node->left != NULL) postOrderTraversal(node->left);
	if (node->right != NULL) postOrderTraversal(node->right);
	printf("%d ", node->number);
}

int main() {
	node_t* treeRoot;
	init(&treeRoot);
	push(&treeRoot, 5);
	push(&treeRoot, 3);
	push(&treeRoot, 7);
	push(&treeRoot, 1);
	push(&treeRoot, 2);
	push(&treeRoot, 4);
	push(&treeRoot, 6);
	push(&treeRoot, 8);
	push(&treeRoot, 10);
	push(&treeRoot, 9);

	inOrderTraversal(treeRoot);
	printf("\n");
	preOrderTraversal(treeRoot);
	printf("\n");
	postOrderTraversal(treeRoot);
	printf("\n");

	clean(treeRoot);
	init(&treeRoot);
	return 0;
}
