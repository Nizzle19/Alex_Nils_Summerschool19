#include <stdio.h>
#include <stdlib.h>
#include "output.h"

void outputT5(int* arr, unsigned int count);

int int_sorter(const void* first_arg, const void* second_arg) {
	// cast the pointers to the right type
	int first = *(int*)first_arg;
	int second = *(int*)second_arg;
	// carry out the comparison
	if (first < second) {
		return -1;
	}
	else if (first == second) {
		return 0;
	}
	else {
		return 1;
	}
}


int main(int argc, char* argv[]) {
	int count;
	int i;

	if (argc != 2) {
		printf("Need one argument to play.\n");
		exit(1);
	}

	int arg1 = atoi(argv[1]); // argv[0] is the program name

	if (arg1 < 1 || arg1 >= 100) {
		printf("The argument has to be positiv (not including 0) and less than 100.\n");
		exit(1);
	}

	int* storageArray = (int*)malloc(arg1 * sizeof(int));


	// fill array; from largest to smallest //
	for (i = 0; i < arg1; ++i) {
		storageArray[i] = arg1 - i;
	}

	// get entries rearranged
	qsort(storageArray, arg1, sizeof(int), int_sorter);

	count = arg1;
    printf("Total numer of Elements in Array  %d \n", count);
	
	outputT5(storageArray, count);

	free(storageArray);
}
