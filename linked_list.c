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

void traverse(struct Node* root) {
	struct Node* current = root;

	while (current != NULL) {
		printf("%d ", current->key);
		current = current->next;
	}

	printf("\n");
}
