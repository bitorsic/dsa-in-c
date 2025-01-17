#ifndef SEARCH_H
#define SEARCH_H
#include "linked_list.h"

int linearSearch (int* arr, int n, int element);
int binarySearch (int* arr, int n, int element);
int linkedListSearch (struct Node* root, int n, int element);

#endif