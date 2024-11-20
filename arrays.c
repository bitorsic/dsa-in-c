#include <stdio.h>
#include <stdlib.h>
#include "include/search.h"
#include "include/sort.h"

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

void deleteElement(int* arr, int* n, int element) {
	int index = linearSearch(arr, (*n), element);

	// unsuccessful search
	if (index == -1) {
		printf("%d was not found in the array\n", element);
		return;
	}

	deleteFromIndex(arr, n, index);
}

void reverseArray(int* arr, int n) {
	int left = 0;
	int right = n - 1;

	while (left < right) {
		// swapping elements at left and right (without temp var)
		arr[left] = arr[left] ^ arr[right];
		arr[right] = arr[left] ^ arr[right];
		arr[left] = arr[left] ^ arr[right];

		left++; right--;
	}
}

int main() {
	int n = 0;
	int* arr = (int *) malloc(sizeof(int));

	insertAtIndex(arr, &n, 2, 0);
	insertAtIndex(arr, &n, 5, 1);
	insertAtIndex(arr, &n, 7, 2);
	insertAtIndex(arr, &n, 3, 3);
	insertAtIndex(arr, &n, 12, 4);
	insertAtIndex(arr, &n, 3, 5);

	reverseArray(arr, n);

	bubbleSort(arr, n);

	// Traversal //
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}