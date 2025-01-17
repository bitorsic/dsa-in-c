#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
	int key;
	struct Node* next;
};

struct Node* insert(struct Node* root, int* n, int value, int index);
struct Node* delete(struct Node* root, int* n, int index);
void traverse(struct Node* root);
int count(struct Node* root);
struct Node* reverse(struct Node* root);

#endif