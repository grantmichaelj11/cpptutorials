#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>
using namespace std;

// Create 2D Matrix Function
class Matrix2D {
	public:
		int rows,columns;
		vector<vector<double>> matrix;
		Matrix2D(int xi, int yi) {
			try {

				if (xi <= 0 || yi <= 0) {

					throw invalid_argument("Both dimensions must be greater than 0.");

				} else {
					rows = xi;
					columns = yi;

					//Generate the 2D matrix if all three dimensions exist
					matrix = vector<vector<double>>(xi, vector<double>(yi, 0.0));
				}
			} catch (const invalid_argument& e) {
				cerr << e.what() << endl;
			}
		}
	void randomizeMatrixUniform(float low, float high){
		// Takes random numbers between low and high

		// seeds random number generator
		random_device rd;
		mt19937 mt(rd());
		//define our random number generator
		uniform_real_distribution<double> dist(low, high);

		//Iterate through matrix and randomly assign values to each element
		for (int i = 0; i < matrix.size(); i++){
			for (int j = 0; j < matrix[i].size(); j++){
				matrix[i][j] = dist(mt);
			}
		}
	}

	void randomizeMatrixGaussian(float mean, float std){
		//Randomly initalizes matrix according to a Gaussian Distribution
		random_device rd;
		mt19937 mt(rd());
		normal_distribution<> dist(mean, std);
		for (int i = 0; i < matrix.size(); i++){
			for (int j = 0; j < matrix[i].size(); j++){
				matrix[i][j] = dist(mt);
			}
		}
	}

	void matrixTranspose(){

		//Generate a matrix with opposite dimensions of original matrix
		vector<vector<double>> matrixHolder = vector<vector<double>>(columns, vector<double>(rows, 0.0));

		//Rows become Columns and Columns become rows
		for (int i = 0; i < matrix.size(); i++){
			for (int j = 0; j < matrix[i].size(); j++){
				matrixHolder[j][i] = matrix[i][j];
			}
		}
		matrix = matrixHolder;
	}

	void printMatrix(){
		for (int i = 0; i < matrix.size(); i++){
			for (int j = 0; j < matrix[i].size(); j++){
				cout << matrix[i][j] << " ";
			} cout << endl;
		}
	}
};



Matrix2D matrixMultiplication(Matrix2D matrix1, Matrix2D matrix2){
	//Check if dimensions are suitable for multiplication
	// Assumes that the operation is [matrix1] x [matrix2]

	//Throw an error if matrix dimensions are not appropriate for multiplication
	//Inner dimensions must match!
	try {
		if (matrix1.columns != matrix2.rows) {
			throw invalid_argument("Matrix dimensions are incapatible with matrix multiplication!");
		}
	} catch (const invalid_argument& e) {
				cerr << e.what() << endl;
	}

	Matrix2D result(matrix1.rows, matrix2.columns);

	// Conduct the multiplication
	for (int i = 0; i < matrix1.rows; i++){
		for (int j = 0; j < matrix2.columns; j++) {
			for (int k = 0; k < matrix1.columns; k++) {
				result.matrix[i][j] += matrix1.matrix[i][k] * matrix2.matrix[k][j];

			}
		}
	}

	return result;
}

Matrix2D scalarMultiplication(Matrix2D matrixInput, double scalarValue){
	// Multiplies a matrix by a scalar

	for (int i = 0; i< matrixInput.rows; i++){
		for (int j = 0; j< matrixInput.columns; j++) {
			matrixInput.matrix[i][j] *= scalarValue;
		}
	}

	return matrixInput;

}

//Dot Product
//Cross Product
//Addition
//Inverse
//Trace
//Gauss Elimination
//LU Decomposition
//Eigenvalue Problems

