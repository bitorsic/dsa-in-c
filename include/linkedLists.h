#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

struct Node {
	int key;
	struct Node* next;
};

struct Node* insert(struct Node* root, int* n, int value, int index);
void traverse(struct Node* root);

#endif