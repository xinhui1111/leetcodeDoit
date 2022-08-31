#include<iostream>
using namespace std;

#include<vector>
void plusOne(vector<int>& digits) {
	//核心部分算法
	int len = (int)digits.size();
	int loc = len - 1;
	while (loc >= 0) {
		if (digits[loc] == 9)
		{
			digits[loc] = 0;
			loc--;
			continue;
		}

		else {
			digits[loc] = digits[loc] + 1;
			return;
		}
	}
	if (loc == -1) {
		//都是9，那就需要进行扩展
		digits.push_back(0);
		digits[0] = 1;
		for (int i = 1; i < digits[i]; ++i) {
			digits[i] = 0;
		}
	}
	
}

vector<int> plusOne1(vector<int>& digits) {
	vector<int>result(digits.size(), 0);
	//核心部分算法
	int len = (int)digits.size();
	int loc = len - 1;
	while (loc >= 0) {
		if (digits[loc] == 9)
		{
			digits[loc] = 0;
			loc--;
			continue;
		}

		else {
			result[loc] = digits[loc] + 1;
			for (int i = 0; i < loc; ++i) {
				result[i] = digits[i];
			}
			return result;
		}
	}
	if (loc == -1) {
		result[0] = 1;
		result.push_back(0);
		return result;
	}

}
int main() {
	vector<int>digits = { 2,9,9,9 };
	vector<int>result=plusOne1(digits);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
	return 0;
}