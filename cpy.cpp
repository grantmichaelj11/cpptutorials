#include <iostream>
#include <vector>
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
};

int main(){
	Matrix testMat(3,3,3);

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



