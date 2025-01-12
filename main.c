#include <stdio.h>
#include <stdlib.h>
#include "include/linked_list.h"

int main() {
	int n = 0;
	struct Node* root = NULL;

	root = insert(root, &n, 5, 0);
	root = insert(root, &n, 1, 0);
	root = insert(root, &n, 6, 0);
	root = insert(root, &n, 7, 0);
	root = insert(root, &n, 2, 0);
	root = insert(root, &n, 4, 0);
	root = insert(root, &n, 3, 4);

	traverse(root);
	root = delete(root, &n, 5);
	traverse(root);
}