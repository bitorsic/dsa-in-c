#include <stdio.h>
#include <stdlib.h>

void insertAtEnd(int* arr, int* n, int element) {
	int index = (*n);
	
	// base case - empty array
	if (index == 0) {
		*arr = element;
		(*n)++;
		return;
	}

	arr = realloc(arr, (index + 1) * sizeof(int));
	arr[index] = element;

	(*n)++;
}

int main() {
	int n = 0;
	int* arr = (int *) malloc(sizeof(int));

	insertAtEnd(arr, &n, 2);
	insertAtEnd(arr, &n, 3);
	insertAtEnd(arr, &n, 4);
	insertAtEnd(arr, &n, 5);
	insertAtEnd(arr, &n, 6);
	insertAtEnd(arr, &n, 7);
	insertAtEnd(arr, &n, 8);

	// Traversal //
	for (int i = 0; i < n; i++) {
		printf("%d ", *arr + i);
	}
	printf("\n");
}