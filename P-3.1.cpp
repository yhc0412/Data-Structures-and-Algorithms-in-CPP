// Write a C++ function that takes two three-dimensional integer arrays and adds them componentwise

#include <iostream> // cout
#include <cstdlib> // rand

#define dimOne 5
#define dimTwo 5
#define dimThree 5

void add( int***, int***, int*** );

int main()
{
	int*** A = new int** [dimOne];
	for( int i = 0; i < dimOne; i++ )
	{
		A[i] = new int* [dimTwo];
		for( int j = 0; j < dimTwo; j++ )
		{
			A[i][j] = new int [dimThree];
			for( int k = 0; k < dimThree; k++ )
				A[i][j][k] = std::rand();
		}
	}
	
	int*** B = new int** [dimOne];
	for( int i = 0; i < dimOne; i++ )
	{
		B[i] = new int* [dimTwo];
		for( int j = 0; j < dimTwo; j++ )
		{
			B[i][j] = new int [dimThree];
			for( int k = 0; k < dimThree; k++ )
				B[i][j][k] = std::rand();
		}
	}
	
	int*** C = new int** [dimOne];
	add( A, B, C );
	for( int i = 0; i < dimOne; i++ )
		for( int j = 0; j < dimTwo; j++ )
			for( int k = 0; k < dimThree; k++ )
			{
				std::cout << "C[" << i << "][" << j << "][" << k << "] = ";
				std::cout << "A[" << i << "][" << j << "][" << k << "] + B[" << i << "][" << j << "][" << k << "] = ";
				std::cout << A[i][j][k] << " + " << B[i][j][k] << " = " << C[i][j][k] << std::endl;
			}
	
	return 0;
}

void add( int*** A, int*** B, int*** C )
{
	// dynamic allocation for the output matrix C
	for( int i = 0; i < dimOne; i++ )
	{
		C[i] = new int* [dimTwo];
		for( int j = 0; j < dimTwo; j++ )
			C[i][j] = new int [dimThree];
	}
	
	// matrix addition
	for( int i = 0; i < dimOne; i++ )
		for( int j = 0; j < dimTwo; j++ )
			for( int k = 0; k < dimThree; k++ )
				C[i][j][k] = A[i][j][k] + B[i][j][k];
}
