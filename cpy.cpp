#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>
using namespace std;


class Tensor3D{
	public:
		// Gives the size of the matrix in each direction
		int x,y,z;
		vector<vector<vector<double>>> matrix;
		// Constructor for class
		Tensor3D(int xi, int yi, int zi) {
			try {

				if (xi <= 0 || yi <= 0 || zi <= 0) {

					throw invalid_argument("All three dimensions must be greater than 0.");

				} else {
					x = xi;
					y = yi;
					z = zi;

					//Generate the 3D matrix if all three dimensions exist
					matrix = vector<vector<vector<double>>>(xi, vector<vector<double>>(yi, vector<double>(zi, 0.0)));
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
				for (int k = 0; k < matrix[i][j].size(); k++){
					matrix[i][j][k] = dist(mt);
				}
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
				for (int k = 0; k < matrix[i][j].size(); k++){
					matrix[i][j][k] = dist(mt);
				}
			}
		}
	}

	//Print Matrix Function?

};

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



int main(){
	Matrix2D testMat(2,3);
	testMat.printMatrix();
	testMat.randomizeMatrixUniform(0.0, 1.0);
	testMat.printMatrix();
	testMat.matrixTranspose();
	testMat.printMatrix();
	return 0;
}



