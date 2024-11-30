#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

struct Node {
	int key;
	struct Node* next;
};

struct Node* insert(struct Node* root, int value);
void traverse(struct Node* root);

#endif