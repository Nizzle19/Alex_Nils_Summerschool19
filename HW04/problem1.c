#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_doubles (double* a, double amin, double amax, size_t n, unsigned int seed);


int RADIUS;
int i;
int j;
double pi=3.1415;

void initializeWeights(double* weights, int RADIUS) {
	for (i = 0; i < 2*RADIUS; i++) {
		weights[i] = sqrt(2 / (pi * RADIUS * RADIUS)) * exp((-2.0 * ((i - RADIUS) * (i - RADIUS)) / (RADIUS * RADIUS)));
	}
}


void applyStencil1D(int sIdx, int eIdx, double* weights, double* in, double* out) {
	for (int i = sIdx; i < eIdx; i++) {
		out[i] = 0;
		//loop over all elements in the stencil
		for (int j = -RADIUS; j <= RADIUS; j++) {
			out[i] += weights[j + RADIUS] * in[i + j];
		}
		out[i] = out[i] / (2.0 * RADIUS + 1);
	}
}


int main(int argc, char* argv[]) {
	int N;
	int R;
	int seed;

	int s;


	if (argc != 5) {
		printf("Need four arguments to play.\n");
		exit(1);
	}

	N = atoi(argv[1]); // argv[0] is the program name

	if (N <= 0) {
		printf("Argument N has to be positiv (including 0).\n");
		exit(1);
	}
	printf("Argument N=%d - Length of the input array \n", N);

	R = atoi(argv[2]); // argv[0] is the program name

	if (R <= 0 || R > 21) {
		printf("The argument R has to be positiv (including 0) and not greater than 21.\n");
		exit(1);
	}
	printf("Argument R=%d - Radius of the stencil \n", R);

	seed = atoi(argv[3]); // argv[0] is the program name

	if (seed < 1 && seed > 1000) {
		printf("The argument seed has to be greater than 1 and less than 1000.\n");
		exit(1);
	}
	printf("Seed is %d\n", seed);

	s = atoi(argv[4]); // argv[0] is the program name

	if (s == 0) {
		printf("Argument s is %d. The program will use shared memory.\n", s);
	}
	else printf("Argument s is not equal 0. The program will not use shared memory.\n");

	if (N < 2*R + 1) {
		printf("The condition N >=2R+1 ist not met.\n");
		exit(1);
	}

	int size = N * sizeof(double);
	int wsize = (2 * R + 1) * sizeof(double);

	//allocate resources
	double* weights = (double*)malloc(wsize);
	double* in = (double*)malloc(size);
	double* out = (double*)malloc(size);

	initializeWeights(weights, R);

	//for (i = 0; i < (2*R); i++) {
//		printf("weights are %f\n", weights[i]);
	//}


	//initializeArray
		random_doubles(in, -1.0, 1.0, N, seed);

	//	for (i = 0; i < N; i++) {
	//		printf("Element of array in %f\n", in[i]);
	//	}
		
		// Start timer
		double start = clock();

		applyStencil1D(RADIUS, N - RADIUS, weights, in, out);

		// Get norm2 of out
		double norm2out = 0;
		for (int i = 0; i < N; i++) {
			norm2out += out[i] * out[i];
		}
		norm2out = sqrt(norm2out);

		// Stop timer
		double end = clock();
		double total_time = (((double)(end - start)) / CLOCKS_PER_SEC);


		printf("norm two:     %f\n", norm2out);
		printf("elapsed time: %f ms\n", total_time);

	//free resources
	free(weights);
	free(in);
	free(out);
}

