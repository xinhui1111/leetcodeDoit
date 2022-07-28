#include<iostream>
#include<vector>
using namespace std;

//动态规划实现
/*
	1 0 223
	2 0 323
	3 2 1203
*/
int dynamic_prom(int n,vector<int>pyramid_data) {
	vector<int>temp = pyramid_data;
	int sum = temp[n-1];
	for (int i=n-1; i >0; i--) {
		temp[i - 1] = temp[i - 1] + (sum / 100) * 15;//
		sum += temp[i - 1];
	}
	cout << "sum is" << sum << endl;
	int result = temp[0];
	return result;
}

int main_wei() {
	vector<int>data = { 223,323,1203 };
	cout << dynamic_prom(3, data) << endl;
	return 0;
}