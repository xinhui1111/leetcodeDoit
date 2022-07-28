/*
实现旋转图像的功能
*/
#include<iostream>
#include<vector>
using namespace std;

#include<array>
void rotate(vector<vector<int>>& matrix) {
	int len = matrix.size();
	vector<vector<int>>temp(len, vector<int>(len, 0));
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[i].size(); ++j) {
			temp[i][len-1-j] = matrix[j][i];
		}
	}
	matrix = temp;
}

int main_rotate_image() {
	vector<vector<int>>matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	rotate(matrix);
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix.size(); ++j) {
			cout << matrix[i][j];
		}
		cout << endl;
	}

	return 0;
}