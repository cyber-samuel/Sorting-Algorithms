/*
 * Programmer: Dom-1
 * Implemenation of an insertion sort
 */
#include <stdio.h>
#include <stdlib.h>

int* insertionSort(unsigned int *unsorted, size_t length);

int main() {
	int needsSorting[] = {10, 5, 7, 2, 1, 3, 4, 8, 9, 6};

	for(int i = 0; i < 10; i++) {
		printf("%i ", needsSorting[i]);
	}

	printf("\n");

	size_t length = sizeof(needsSorting)/sizeof(int);
	int* sorted;
	sorted = insertionSort(needsSorting, length);

	for(int i = 0; i < 10; i++) {
		printf("%i ", sorted[i]);
	}
	
	printf("\n");
	free(sorted);
	sorted = NULL;

	return 0;
}

int* insertionSort(unsigned int *unsorted, size_t length) {

	// get information regarding input array
	int *sorted = malloc(sizeof(int) * length);

	for(int i = 0; i < length; i++) {
		sorted[i] = unsorted[i];
	}

	for(int i = 1; i < length; i++) {
		int key = sorted[i];
		int j = i - 1;
		while((j > -1) && (sorted[j] > key)) {
			sorted[j + 1] = sorted[j];
			sorted[j] = key;
			j--;
		}
	}

	return sorted;
}
