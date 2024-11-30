#include <stdio.h>
#include <stdlib.h>
#include "include/linkedLists.h"

int main() {
	struct Node* root = NULL;

	root = insert(root, 5);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 2);
	root = insert(root, 4);

	traverse(root);
}