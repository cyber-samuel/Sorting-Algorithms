/*
 * Programmer: Dom-1
 * Implemenation of a merge sort
 */
#include <stdio.h>

void mergeSort(int segment[], int left, int right);
void merge(int segment[], int left, int middle, int right);

int main() {
	int needsSorting[] = {10, 5, 7, 2, 1, 3, 4, 8, 9, 6};
	size_t length = sizeof(needsSorting)/sizeof(int);
	
	for(int i = 0; i < length; i++) {
		printf("%i ", needsSorting[i]);
	}

	printf("\n");
	mergeSort(needsSorting, 0, length - 1);

	for(int i = 0; i < length; i++) {
		printf("%i ", needsSorting[i]);
	}
	printf("\n");
	return 0;
}

void mergeSort(int segment[], int left, int right) {
	if(left < right) {
		int middle = (left+right)/2;

		mergeSort(segment, left, middle);
		mergeSort(segment, middle+1, right);
		merge(segment, left, middle, right);
	}
}

void merge(int segment[], int left, int middle, int right) {
	
	int n1 = middle - left + 1;
	int n2 = right - middle;
	int LEFT[n1], RIGHT[n2];

	for(int i = 0; i < n1; i++) {
		LEFT[i] = segment[left + i];
	}

	for(int i = 0; i < n2; i++) {
		RIGHT[i] = segment[middle + i + 1];
	}

	int i = 0, j = 0, x = left;

	while((i < n1) && (j < n2)) {
		if(LEFT[i] <= RIGHT[j]) {
			segment[x] = LEFT[i];
			i++;
		} else {
			segment[x] = RIGHT[j];
			j++;
		}
		x++;
	}

	while(i < n1) {
		segment[x] = LEFT[i];
		i++;
		x++;
	}

	while(j < n2) {
		segment[x] = RIGHT[j];
		j++;
		x++;
	}
}