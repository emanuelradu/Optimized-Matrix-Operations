/*
 * Tema 2 ASC
 * 2020 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	printf("NEOPT SOLVER\n");
	int i, j, k;
	double *C, *Atr, *Asq;
	C = malloc(N * N * sizeof(double));
	Atr = malloc(N * N * sizeof(double));
	Asq = malloc(N * N * sizeof(double));

	for (i = 0; i < N; i++){
	   	for (j = 0; j < N; j++){
			Atr[j * N + i] = A[i * N + j];
		}
	}

	for (i = 0; i < N; i++){
   		for (j = i; j < N; j++){
      		for (k = 0; k < N; k++){
				Asq[i * N + j] += A[i * N + k] * A[k * N + j];
      		}
   		}
	}

	for (i = 0; i < N; i++){
   		for (j = 0; j < N; j++){
      		for (k = 0; k < N; k++){
         		C[i * N + j] += B[i * N + k] * Atr[k * N + j] + Asq[i * N + k] * B[k * N + j];
      		}
   		}
	}

	free(Atr);
	free(Asq);
	
	return C;
}
