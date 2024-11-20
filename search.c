#include <stdio.h>
#include <stdlib.h>

// returns index of element, -1 if not found
int linearSearch (int* arr, int n, int element) {
	// base case - empty array
	if (n == 0) {
		printf("empty array\n");
		return -1;
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == element) {
			return i;
			break;
		}
	}

	return -1;
}

// requires SORTED array
// returns index of element, -1 if not found
int binarySearch (int* arr, int n, int element) {
	// base case - empty array
	if (n == 0) {
		printf("empty array\n");
		return -1;
	}

	int middle;
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		middle = (left + right) / 2;

		if (arr[middle] == element) {
			return middle;
		}

		if (arr[middle] > element) {
			right = middle - 1;
		} else if (arr[middle] < element) {
			left = middle + 1;
		}

	}

	return -1;
}