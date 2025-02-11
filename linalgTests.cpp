#include "linalg.h"
using namespace std;

//Test "matrixTransport() in Matrix2D class"
void testMatrixTranspose(){
	/*
	Input:

		1 2 3
		5 6 7

	Expected Output:

		1 5
		2 6
		3 7

	*/

	//Generates a matrix of zeros
	Matrix2D inputMat(2,3);
	//Assigns input elements
	inputMat.matrix[0][0] = 1;
	inputMat.matrix[0][1] = 2;
	inputMat.matrix[0][2] = 3;
	inputMat.matrix[1][0] = 5;
	inputMat.matrix[1][1] = 6;
	inputMat.matrix[1][2] = 7;

	//Generate Output Matrix
	Matrix2D outputMat(3,2);

	outputMat.matrix[0][0] = 1;
	outputMat.matrix[0][1] = 5;
	outputMat.matrix[1][0] = 2;
	outputMat.matrix[1][1] = 6;
	outputMat.matrix[2][0] = 3;
	outputMat.matrix[2][1] = 7;

	inputMat.matrixTranspose();

	//Test if matricies are equal
	if (inputMat.matrix != outputMat.matrix){
		cout << "matrixTranspose() TEST FAILED" << endl;
	} else {
		cout << "SUCCESS" << endl;
	}

}

void testMatrixMultiplication(){
	/*

		3 1	5 9	22 29
		8 6	7 2	82 84
		0 4		28 8

	*/

	Matrix2D matrix1(3,2);

	matrix1.matrix[0][0] = 3;
	matrix1.matrix[0][1] = 1;
	matrix1.matrix[1][0] = 8;
	matrix1.matrix[1][1] = 6;
	matrix1.matrix[2][0] = 0;
	matrix1.matrix[2][1] = 4;

	Matrix2D matrix2(2,2);

	matrix2.matrix[0][0] = 5;
	matrix2.matrix[0][1] = 9;
	matrix2.matrix[1][0] = 7;
	matrix2.matrix[1][1] = 2;

	Matrix2D matrixAnswer(3,2);

	matrixAnswer.matrix[0][0] = 22;
	matrixAnswer.matrix[0][1] = 29;
	matrixAnswer.matrix[1][0] = 82;
	matrixAnswer.matrix[1][1] = 84;
	matrixAnswer.matrix[2][0] = 28;
	matrixAnswer.matrix[2][1] = 8;

	Matrix2D matrixTest = matrixMultiplication(matrix1, matrix2);

	//Test
	if (matrixAnswer.matrix != matrixTest.matrix){
		cout << "matrixMultiplication() TEST FAILED" << endl;
	} else {
		cout << "SUCCESS" << endl;
	}
}

void testScalarMultiplication(){
	/*

		5	5 9	25 45
			7 2	35 10

	*/

	double scalarValue = 5.0;
	Matrix2D matrixInput(2,2);

	matrixInput.matrix[0][0] = 5;
	matrixInput.matrix[0][1] = 9;
	matrixInput.matrix[1][0] = 7;
	matrixInput.matrix[1][1] = 2;

	Matrix2D matrixAnswer(2,2);

	matrixAnswer.matrix[0][0] = 25;
	matrixAnswer.matrix[0][1] = 45;
	matrixAnswer.matrix[1][0] = 35;
	matrixAnswer.matrix[1][1] = 10;

	Matrix2D matrixTest = scalarMultiplication(matrixInput, scalarValue);

	//Test
	if (matrixAnswer.matrix != matrixTest.matrix){
		cout << "scalarMultiplication() TEST FAILED" << endl;
	} else{
		cout << "SUCCESS" << endl;
	}
}


int main() {
	testMatrixTranspose();
	testMatrixMultiplication();
	testScalarMultiplication();
}
