/*
 * Programmer: Dom-1
 * Implemenation of a heap sort
 */
#include <stdio.h>

void heapSort(int unsorted[], size_t length);
void dopify(int segment[], int length, int mainIndex);
void swap(int* x, int* y);

int main() {
	int needsSorting[] = {10, 5, 7, 2, 1, 3, 4, 8, 9, 6};

	for(int i = 0; i < 10; i++) {
		printf("%i ", needsSorting[i]);
	}

	printf("\n");

	size_t length = sizeof(needsSorting)/sizeof(int);
	heapSort(needsSorting, length);

	for(int i = 0; i < 10; i++) {
		printf("%i ", needsSorting[i]);
	}
	
	printf("\n");

	return 0;
}

void heapSort(int unsorted[], size_t length) {
	//build max heap
	for (int i = length / 2 - 1; i >= 0; i--) 
        dopify(unsorted, length, i); 

	// start sorting
	for(int i = length - 1; i >= 0; i--) {
		swap(&unsorted[0], &unsorted[i]);

		dopify(unsorted, i, 0);
	}

}

// Everyone calls it heapify for some reason
// I'd rather give it a cooler name...
void dopify(int segment[], int length, int mainIndex) {
	int largest = mainIndex;
	int leftChildIndex = (2*mainIndex)+1;
	int rightChildIndex = (2*mainIndex)+2;

	if((leftChildIndex < length) && (segment[leftChildIndex] > segment[largest]))
		largest = leftChildIndex;
	
	if((rightChildIndex < length) && (segment[rightChildIndex] > segment[largest]))
		largest = rightChildIndex;


	// if the largest is not at the top of the tree
	if(largest != mainIndex) {
		swap(&segment[mainIndex], &segment[largest]);

		dopify(segment, length, largest);
	}

}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}