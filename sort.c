#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j+1]) {
				// swap
				arr[j] = arr[j] ^ arr[j+1];
				arr[j+1] = arr[j] ^ arr[j+1];
				arr[j] = arr[j] ^ arr[j+1];
			}
		}
	}
}

void selectionSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}

		if (min != i) {
			// swap
			arr[i] = arr[min] ^ arr[i];
			arr[min] = arr[min] ^ arr[i];
			arr[i] = arr[min] ^ arr[i];
		}
	}
}

void insertionSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[i+1] < arr[i]) {
			// start swapping
			for (int j = i; j >= 0; j--) {
				if (arr[j] < arr[j+1]) {
					break;
				}

				// swap
				arr[j] = arr[j] ^ arr[j+1];
				arr[j+1] = arr[j] ^ arr[j+1];
				arr[j] = arr[j] ^ arr[j+1];
			}
		}
	}
}