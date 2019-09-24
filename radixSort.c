/*
 * Programmer: Dom-1
 * Implemenation of a radix sort
 */
#include <stdio.h>

void radixSort(int unsorted[], size_t length);
void countSort(int unsorted[], size_t length, int figure);

int main() {
	int needsSorting[] = {10, 5, 7, 2, 1, 3, 4, 8, 9, 6};

	for(int i = 0; i < 10; i++) {
		printf("%i ", needsSorting[i]);
	}

	printf("\n");

	size_t length = sizeof(needsSorting)/sizeof(int);
	radixSort(needsSorting, length);

	for(int i = 0; i < 10; i++) {
		printf("%i ", needsSorting[i]);
	}
	
	printf("\n");

	return 0;
}

void radixSort(int unsorted[], size_t length) {
	// Get the largest number in the array
	int max = unsorted[0];
	for(int i = 1; i < length; i++)
		if(unsorted[i] > max)
			max = unsorted[i];


	for(int fig = 1; max/fig > 0; fig *= 10)
		countSort(unsorted, length, fig);
}

// Radix sort is basically just a count sort based over sigFigs
void countSort(int unsorted[], size_t length, int figure) {
	int output[length]; // output array 
    int i, count[10] = {0};

    for (i = 0; i < length; i++) {
        count[ (unsorted[i]/figure)%10 ]++; 
    }

    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (i = length - 1; i >= 0; i--) { 
        output[count[ (unsorted[i]/figure)%10 ] - 1] = unsorted[i]; 
        count[ (unsorted[i]/figure)%10 ]--; 
    } 
  	
    // Copy the output array to unsorted[], so that unsorted[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < length; i++) 
        unsorted[i] = output[i]; 
}

