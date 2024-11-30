#include <stdio.h>
#include <stdlib.h>
#include "include/arrays.h"
#include "include/search.h"
#include "include/sort.h"

int main() {
	int n = 0;
	int* arr = (int *) malloc(sizeof(int));

	insertAtIndex(arr, &n, 2, 0);
	insertAtIndex(arr, &n, 5, 1);
	insertAtIndex(arr, &n, 7, 2);
	insertAtIndex(arr, &n, 3, 3);
	insertAtIndex(arr, &n, 12, 4);
	insertAtIndex(arr, &n, 3, 5);

	// reverseArray(arr, n);

	selectionSort(arr, n);

	// Traversal //
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}