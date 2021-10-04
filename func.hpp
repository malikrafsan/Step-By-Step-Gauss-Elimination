#pragma once

#define N 4	 // Number of unknowns

// procedure to make the row have lead one
void leadOner(double mat[N][N+1],int row);

// procedure to print the matrix to the screen
void printMat(double mat[N][N+1]);

// function to reduce matrix to r.e.f. Returns a value to
// indicate whether matrix is singular or not
int forwardElim(double mat[N][N+1]);

// function to calculate the values of the unknowns
void backSub(double mat[N][N+1]);

// function to get matrix content
void gaussianElimination(double mat[N][N+1]);

// function for elementary operation of swapping two rows
void swap_row(double mat[N][N+1], int i, int j);

// function to print matrix content at any stage
void print(double mat[N][N+1]);


