#include<bits/stdc++.h>
#include "func.hpp"
using namespace std;

// Driver program
int main() {
	double mat[N][N+1] = 
  {{2.0, -1.0,3.0, 4.0,9.0},
  {1.0, 0.0, -2.0, 7.0,11.0},
  {3.0, -3.0, 1.0, 5.0,8.0},
  {2.0,1.0,4.0,4.0,10.0}};

	printf("ORIGINAL MATRIX: \n");
  printMat(mat);

	gaussianElimination(mat);

	return 0;
}
