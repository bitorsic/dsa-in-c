#include <stdio.h>
#include <stdlib.h>
#include "include/search.h"

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