#include <stdio.h>
#include <stdlib.h>
#include "include/linked_list.h"

struct Node* insert(struct Node* root, int* n, int value, int index) {
	if (index > (*n)) {
		printf("index out of range\n");
		return root;
	}

	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->key = value;

	// insert at beginning
	if (index == 0) {
		temp->next = root;
		(*n)++;
		return temp;
	}

	// traverse to index - 1
	struct Node* curr = root;
	for (int i = 0; i < index - 1; i++) {
		curr = curr->next;
	}

	// insert at index (also works for insertion at end)
	temp->next = curr->next;
	curr->next = temp;
	(*n)++;
	return root;

}

struct Node* delete(struct Node* root, int* n, int index) {
	if (index >= (*n)) {
		printf("index out of range\n");
		return root;
	}

	struct Node* temp = NULL;

	// delete from beginning
	if (index == 0) {
		temp = root->next;
		free(root);
		(*n)--;
		return temp;
	}

	// traverse to index - 1
	struct Node* curr = root;
	for (int i = 0; i < index - 1; i++) {
		curr = curr->next;
	}

	// remove the node at index
	temp = curr->next;
	curr->next = temp->next;
	free(temp);
	(*n)--;
	return root;
}

void traverse(struct Node* root) {
	struct Node* current = root;

	while (current != NULL) {
		printf("%d ", current->key);
		current = current->next;
	}

	printf("\n");
}

int count(struct Node* root) {
	int sum = 0;

	struct Node* current = root;

	while (current != NULL) {
		sum++;
		current = current->next;
	}

	return sum;
}

struct Node* reverse(struct Node* root) {
	// base case - empty or single element
	if (root == NULL || root->next == NULL) {
		return root;
	}

	// let the 3 pointers be root, i, and j
	// initializing them one after another
	struct Node* i = root->next;
	struct Node* j = i;

	// converting root to the end element
	root->next = NULL;

	while (j != NULL) {
		j = i->next;
		i->next = root;
		root = i;
		i = j;
	}

	return root;
}
