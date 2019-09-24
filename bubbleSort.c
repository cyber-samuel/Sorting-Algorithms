/*
 * Programmer: Dom-1
 * Implemenation of a bubble sort
 */
#include <stdio.h>

void bubbleSort(int unsorted[], size_t length);

int main() {
	int needsSorting[] = {10, 5, 7, 2, 1, 3, 4, 8, 9, 6};

	for(int i = 0; i < 10; i++) {
		printf("%i ", needsSorting[i]);
	}

	printf("\n");

	size_t length = sizeof(needsSorting)/sizeof(int);
	bubbleSort(needsSorting, length);

	for(int i = 0; i < 10; i++) {
		printf("%i ", needsSorting[i]);
	}
	
	printf("\n");

	return 0;
}

void bubbleSort(int unsorted[], size_t length) {
	for(int i = 0; i < length - 1; i++) {
		for(int j = 0; j < length - i - 1; j++) {
			if(unsorted[j] > unsorted[j+1]) {
				int temp = unsorted[j];
				unsorted[j] = unsorted[j+1];
				unsorted[j+1] = temp;
			}
		}
	}
}