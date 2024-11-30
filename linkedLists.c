#include <stdio.h>
#include <stdlib.h>
#include "include/linkedLists.h"

struct Node* insert(struct Node* root, int value) {
	// insert at beginning
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->key = value;
	temp->next = root;
	return temp;

}

void traverse(struct Node* root) {
	struct Node* current = root;

	while (current != NULL) {
		printf("%d ", current->key);
		current = current->next;
	}

	printf("\n");
}
