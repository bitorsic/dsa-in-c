#include <stdio.h>
#include <stdlib.h>

void insertAtIndex(int* arr, int* n, int element, int index) {
	if (index > (*n)) {
		printf("index out of range\n");
		return;
	}

	// base case - empty array
	if ((*n) == 0) {
		*arr = element;
		(*n)++;
		return;
	}

	// allocate extra space
	arr = realloc(arr, (*n + 1) * sizeof(int));
	(*n)++;

	// shifting elements to the right
	for (int i = (*n) - 1; i > index; i--) {
		arr[i] = arr[i-1];
	}

	// finally insert element at index
	arr[index] = element;
}

void deleteFromIndex(int* arr, int* n, int index) {
	if (index > (*n)) {
		printf("index out of range\n");
		return;
	}

	// base case - empty array
	if ((*n) == 0) {
		printf("no delete empty array\n");
		return;
	}

	// left shifting the elements
	for (int i = index; i < (*n) - 1; i++) {
		arr[i] = arr[i+1];
	}

	// shorten the array size
	arr = realloc(arr, (*n - 1) * sizeof(int));
	(*n)--;
}

int main() {
	int n = 0;
	int* arr = (int *) malloc(sizeof(int));

	insertAtIndex(arr, &n, 2, 0);
	insertAtIndex(arr, &n, 7, 1);
	insertAtIndex(arr, &n, 9, 1);
	insertAtIndex(arr, &n, 5, 0);

	deleteFromIndex(arr, &n, 0);

	// Traversal //
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}