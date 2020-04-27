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

	for (i = 0; i < N; ++i){
		double *at = &A[i * N];
	   	for (j = 0; j < N; j++){
			Atr[j * N + i] = *at;

			at++;
		}
	}

	for (i = 0; i < N; ++i){
		double *orig_p1 = &A[i * N];
   		for (j = i; j < N; ++j) {

			double *p1 = orig_p1;
    		double *p2 = &A[j];
			register double suma = 0.0;
			
      		for (k = 0; k < N; k++) {
				suma += *p1 * *p2;
				p1++;
				p2 += N;
      		}
			Asq[i * N + j] = suma;  
   		}
	}

	for (i = 0; i < N; i++) {
		double *pB1_orig = &B[i * N];
		double *pAsq_orig = &Asq[i * N];
   		for (j = 0; j < N; ++j) {
			register double suma = 0.0;	  

			double *pB1 = pB1_orig;
			double *pAsq = pAsq_orig;
			double *pAtr = &Atr[j];
			double *pB2 = &B[j];

			for (k = 0; k < N; k++){
         		suma += *pB1 * *pAtr + *pAsq * *pB2;

				pB1++;
				pAsq++;

				pAtr += N;
				pB2 += N;
      		}
			C[i * N + j] = suma;
   		}
	}

	free(Atr);
	free(Asq);
	
	return C;
}
