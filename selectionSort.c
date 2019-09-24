/*
 * Programmer: Dom-1
 * Implemenation of a selection sort
 */
#include <stdio.h>

void selectionSort(int unsorted[], size_t length);

int main() {
	int needsSorting[] = {10, 5, 7, 2, 1, 3, 4, 8, 9, 6};

	for(int i = 0; i < 10; i++) {
		printf("%i ", needsSorting[i]);
	}

	printf("\n");

	size_t length = sizeof(needsSorting)/sizeof(int);
	selectionSort(needsSorting, length);

	for(int i = 0; i < 10; i++) {
		printf("%i ", needsSorting[i]);
	}
	
	printf("\n");

	return 0;
}

void selectionSort(int unsorted[], size_t length) {
	for(int i = 0; i < length - 1; i++) {
		int minIndex = i, min = unsorted[i];
		
		for(int j = i+1; j < length; j++) {
			if(unsorted[j] <= min) {
				min = unsorted[j];
				minIndex = j;
			}
		}

		int temp = unsorted[i];
		unsorted[i] = unsorted[minIndex];
		unsorted[minIndex] = temp;
	}
}