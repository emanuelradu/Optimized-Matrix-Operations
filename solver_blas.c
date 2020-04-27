/*
 * Tema 2 ASC
 * 2020 Spring
 */
#include "utils.h"
#include "cblas.h"
#include <string.h>

/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {
	printf("BLAS SOLVER\n");
	int i, j;
	double *C, *mul1, *mul2, *old_A, *old_B, *copie_A;
	C = malloc(N * N * sizeof(double));
	mul1 = malloc(N * N * sizeof(double));
	mul2 = malloc(N * N * sizeof(double));

	old_A = malloc(N * N * sizeof(double));
	old_B = malloc(N * N * sizeof(double));
	copie_A = malloc(N * N * sizeof(double));

	memcpy(old_A, A, N * N * sizeof(double));
	memcpy(old_B, B, N * N * sizeof(double));
	memcpy(copie_A, A, N * N * sizeof(double));

	cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans,
	 CblasNonUnit, N, N, 1, copie_A, N, A, N);

	cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans,
	 CblasNonUnit, N, N, 1, A, N, B, N);

	memcpy(mul2, B,  N * N * sizeof(double));

	cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasTrans,
	 CblasNonUnit, N, N, 1, old_A, N, old_B, N);

	memcpy(mul1, old_B,  N * N * sizeof(double));

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			C[i * N + j] = mul1[i * N + j] + mul2[i * N + j];
		}
	}
	free(mul1);
	free(mul2);
	free(old_A);
	free(old_B);
	free(copie_A);

	return C;
}
