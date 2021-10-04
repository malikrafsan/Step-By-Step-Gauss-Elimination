#include<bits/stdc++.h>
#include "func.hpp"
using namespace std;

void leadOner(double mat[N][N+1],int row) {
	printf("Make %d row to have lead one\n",row+1);
	double divider = mat[row][row];
	
	for (int i=row;i<N+1;i++) {
		mat[row][i] /= divider;
	}
}

void printMat(double mat[N][N+1]) {
  cout << "======================================" << endl;
  for (int i=0;i<N;i++) {
    for (int j=0;j<N+1;j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  cout << "======================================" << endl;
}

void gaussianElimination(double mat[N][N+1]) {
	int singular_flag = forwardElim(mat);

	if (singular_flag != -1) {
		printf("Singular Matrix.\n");
		if (mat[singular_flag][N])
			printf("Inconsistent System.");
		else
			printf("May have infinitely many "
				"solutions.");

		return;
	}
	backSub(mat);
}

void swap_row(double mat[N][N+1], int i, int j) {
	for (int k=0; k<=N; k++) {
		double temp = mat[i][k];
		mat[i][k] = mat[j][k];
		mat[j][k] = temp;
	}
	printf("Swap %d row with %d row\n", i+1, j+1);
	printMat(mat);
}

void print(double mat[N][N+1])
{
	for (int i=0; i<N; i++, printf("\n"))
		for (int j=0; j<=N; j++)
			printf("%lf ", mat[i][j]);

	printf("\n");
}


int forwardElim(double mat[N][N+1]) {
	for (int k=0; k<N; k++) {
		int i_max = k;
		int v_max = mat[i_max][k];

		for (int i = k+1; i < N; i++)
			if (abs(mat[i][k]) > v_max)
				v_max = mat[i][k], i_max = i;

		if (!mat[k][i_max])
			return k;

		if (i_max != k)
			swap_row(mat, k, i_max);

		leadOner(mat,k);
		printMat(mat);
		printf("Make %d column be 0 under lead one\n",k+1);
		for (int i=k+1; i<N; i++) {
			double f = mat[i][k]/mat[k][k];

			for (int j=k+1; j<=N; j++)
				mat[i][j] -= mat[k][j]*f;

			mat[i][k] = 0;
      printMat(mat);
		}

	}
	printMat(mat);
	return -1;
}

void backSub(double mat[N][N+1])
{
	double x[N];

	for (int i = N-1; i >= 0; i--) {
		x[i] = mat[i][N];

		for (int j=i+1; j<N; j++) {
			x[i] -= mat[i][j]*x[j];
		}

		x[i] = x[i]/mat[i][i];
	}

	printf("\nSolution for the system:\n");
	for (int i=0; i<N; i++)
		printf("%lf\n", x[i]);
}