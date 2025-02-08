#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>
using namespace std;


class Matrix3D{
	public:
		// Gives the size of the matrix in each direction
		int x,y,z;
		vector<vector<vector<double>>> matrix;
		// Constructor for class
		Matrix3D(int xi, int yi, int zi) {
			try {

				if (xi == 0 || yi == 0 || zi == 0) {

					throw invalid_argument("All three dimensions must be non-zero");

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
};

// Create 2D Matrix Function

// Do we need to create a Vector Function?

//Matrix Operations functions?

int main(){
	Matrix3D testMat(3,3,3);
	testMat.randomizeMatrixGaussian(0.0, 1.0);
	for (int i = 0; i < testMat.matrix.size(); ++i){
		for (int j = 0; j < testMat.matrix[i].size(); ++j){
			for (int k = 0; k < testMat.matrix[i][j].size(); ++k){
				cout << testMat.matrix[i][j][k] << " ";
			}
		cout << endl;
		}
	cout << endl;
	}
	return 0;
}



