#include <iostream>
#include <vector>
#include <random>
using namespace std;


class Matrix{
	public:
		// Gives the size of the matrix in each direction
		int x,y,z;
		vector<vector<vector<double>>> matrix;
		// Constructor for class
		Matrix(int xi, int yi, int zi) {
			x = xi;
			y = yi;
			z = zi;
			matrix = vector<vector<vector<double>>>(xi, vector<vector<double>>(yi, vector<double>(zi, 0.0)));
		}

	void randomizeMatrixUniform(float low, float high){
		// Takes random numbers between low and high

		// seeds random number generator
		random_device rd;
		//define our random number generator
		mt19937 mt(rd());
		//Generate the random number on some range
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
};

int main(){
	Matrix testMat(3,3,3);
	testMat.randomizeMatrixUniform(-0.5, 0.5);
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



