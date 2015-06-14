// Write a C++ program for a matrix class that can add and multiply arbitrary two-dimensional arrays of integers.
// Do this by overloading the addition + and multiplication * operators.

#include <iostream>
#include <cstdlib>
using namespace std;

class Matrix {
		friend ostream &operator<<( ostream &, Matrix & );
	public:
		Matrix();
		Matrix( int a, int b );
		const Matrix &operator=( const Matrix & );
		Matrix operator+( const Matrix & );
		Matrix operator*( const Matrix & );
	private:
		int** entries;
		int dimOne, dimTwo;
};

Matrix::Matrix() {
	dimOne = dimTwo = 1;
	entries = new int*;
	entries[0] = new int;
	entries[0][0] = rand();
}

Matrix::Matrix( int a, int b ) : dimOne(a), dimTwo(b) {
	entries = new int* [dimOne];
	for( int i = 0; i < dimOne; i++ ) {
		entries[i] = new int [dimTwo];
		for( int j = 0; j < dimTwo; j++ )
			entries[i][j] = rand()%100;
	}
}

const Matrix &Matrix::operator=( const Matrix &m ) {
	if( dimOne != m.dimOne || dimTwo != m.dimTwo ) {
		for( int i = 0; i < dimOne; i++ )
			delete [] entries[i];
		delete [] entries;
		
		dimOne = m.dimOne;
		dimTwo = m.dimTwo;
		Matrix* mm = new Matrix( dimOne, dimTwo );
		entries = mm->entries;
	}
	
	for( int i = 0; i < dimOne; i++ ) {
		for( int j = 0; j < dimTwo; j++ )
			entries[i][j] = m.entries[i][j];
	}
}

ostream &operator<<( ostream &out, Matrix &m ) {
	out << "---------------\n";
	for( int i = 0; i < m.dimOne; i++ ) {
		for( int j = 0; j < m.dimTwo; j++ )
			out << m.entries[i][j] << ' ';
		out << endl;
	}
	return out;
}

Matrix Matrix::operator+( const Matrix &m ) {
	if( dimOne != m.dimOne || dimTwo != m.dimTwo )
		return *this;
	else {
		Matrix* mm = new Matrix( dimOne, dimTwo );
		for( int i = 0; i < dimOne; i++ ) {
			for( int j = 0; j < dimTwo; j++ )
				mm->entries[i][j] = entries[i][j] + m.entries[i][j];
		}
		return *mm;
	}
}

Matrix Matrix::operator*( const Matrix &m ) {
	if( dimTwo != m.dimOne )
		return *this;
	else {
		Matrix* mm = new Matrix( dimOne, m.dimTwo );
		for( int i = 0; i < dimOne; i++ ) {
			for( int j = 0; j < m.dimTwo; j++ ) {
				mm->entries[i][j] = 0;
				for( int k = 0; k < dimTwo; k++ )
					mm->entries[i][j] += entries[i][k] * m.entries[k][j];
			}
		}
		return *mm;
	}
}
