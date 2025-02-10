#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>
using namespace std;

// Create 2D Matrix Function
class Matrix2D {
	public:
		int x, y;
		vector<vector<double>> matrix;
		Matrix2D(int xi, int yi) {
			try {

				if (xi <= 0 || yi <= 0) {

					throw invalid_argument("Both dimensions must be greater than 0.");

				} else {
					x = xi;
					y = yi;

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

	int rows(){
		//returns the number of rows in the matrix
		int numRows = matrix.size();
		return numRows;
	}

	int columns(){
		//returns the number of columns in the matrix
		int numColumns = matrix[0].size();
		return numColumns;
	}

	void matrixTranspose(){

		//Generate a matrix with opposite dimensions of original matrix
		vector<vector<double>> matrixHolder = vector<vector<double>>(y, vector<double>(x, 0.0));

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
	int matrix1Rows = matrix1.rows();
	int matrix1Columns = matrix1.columns();

	int matrix2Rows = matrix2.rows();
	int matrix2Columns = matrix2.columns();

	int resultRows = matrix1.rows();
	int resultColumns = matrix2.columns();

	//Throw an error if matrix dimensions are not appropriate for multiplication
	//Inner dimensions must match!
	try {
		if (matrix1Columns != matrix2Rows) {
			throw invalid_argument("Matrix dimensions are incapatible with matrix multiplication!");
		}
	} catch (const invalid_argument& e) {
				cerr << e.what() << endl;
	}

	Matrix2D result(matrix1Rows, matrix2Columns);

	// Conduct the multiplication
	for (int i = 0; i < resultRows; i++){
		for (int j = 0; j < resultColumns; j++) {
			for (int k = 0; k < matrix1Columns; k++) {
				result.matrix[i][j] = matrix1.matrix[i][k] * matrix2.matrix[k][j];
			}
		}
	}

	return result;
}

Matrix2D scalarMultiplication(Matrix2D matrixInput, double scalarValue){
	// Multiplies a matrix by a scalar

	for (int i = 0; i< matrixInput.rows(); i++){
		for (int j = 0; j< matrixInput.columns(); j++) {
			matrixInput.matrix[i][j] *= scalarValue;
		}
	}

	return matrixInput;

}

//Addition
//Inverse
//Trace
//Gauss Elimination
//LU Decomposition
//Eigenvalue Problems

int main(){
	Matrix2D mat1(2,3);
	mat1.randomizeMatrixUniform(0, 1);
	Matrix2D mat2(3,2);
	mat2.randomizeMatrixUniform(0,1);
	Matrix2D matrixResult = matrixMultiplication(mat1, mat2);
	matrixResult.printMatrix();
	Matrix2D matrixScalar = scalarMultiplication(matrixResult, 5);
	matrixScalar.printMatrix();
	return 0;
}
