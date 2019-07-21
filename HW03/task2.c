#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "output.h"



void randomT2(double* matrix, int DIM);

int DIM = 100;
int i,j=0;

double* A;
double* b;
double* c;

int main(int argc, char* argv[]) {
	
		
	// Allocate dynamic memory
	A = (double *)malloc(DIM * DIM * sizeof(double));
	//	int A[25] = {1, 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    b = (double *)malloc(DIM * sizeof(double));
    c = calloc(DIM, sizeof(double));

	// Check for successful allocation
    if (!(A && b && c)) {
        printf("Error allocating memory\n");
        return 1;
    }
	// Check for successful allocation
	if (DIM < 1) {
		printf("Dim must be greater than 0\n");
		return 1;
	}

	// Initialize A
	randomT2(A,DIM);

 //Schleife fuer Zeilen, Y-Achse
//	for (i = 0; i < DIM*DIM; i++) {
//	    printf("%f ", A[i]);
 //	    printf("\n");
//	}


    // Initialize b
	for (j = 0; j < DIM; j++) {
       if (j % 2 == 0) {
           b[j] = 0.5;
			}
	   else {
           b[j] = -0.5;
		    }
	}

	// Schleife fuer Zeilen, Y-Achse
//	for (i = 0; i < DIM; i++) {
//	  printf("%f ", b[i]);
//	 }
//	 printf("\n");
 

	// Start timer
	clock_t start = clock();

	// Multiply: c = Ab
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			if (DIM > 1) {
				c[i] += A[i * DIM + j] * b[j];
			}
		}
	}

	// Get norm2 of c
    double normc = 0;
    for (int i = 0; i < DIM; i++) {
		normc += c[i] * c[i];
	}
    normc = sqrt(normc);

 // Stop timer
    double end = clock();
    double total_time = (((double)(end - start)) / CLOCKS_PER_SEC);

 // Output norm and time
	outputT2(normc, total_time);

 // Free dynamic memory
   free(A);
   free(b);
   free(c);

    return 0;
}