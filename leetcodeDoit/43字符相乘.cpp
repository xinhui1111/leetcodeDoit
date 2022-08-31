#include<iostream>
using namespace std;



#include<string>

/*
实现一个字符与字符串相乘的函数
*/
string one_multiply(string num1, string num2) {
	for (int i = 0; i < num1.length(); ++i) {
		int int_num1 = num1[i] - '0';
		string temp = "";
		int int_front = 0;
		for(int j = 0; j < num2.length(); ++j) {
			//先转化为数字计算
			int int_num2 = num2[j] - '0';
			int num1_multi_2 = int_num1 * int_num2;
			int go_to = num1_multi_2 / 10;//计算要进多少
			//再将数字转换为字符串，如果超过9前面就要进数字，这个数字需要保存用到下一步
			
		}
	}
}

/*
输入: num1 = "123", num2 = "456"
输出: "56088"
需要考虑可能会是大整数
*/
string multiply(string num1, string num2) {
	//分别将每一个字符与字符串的结果计算出来，并且对应前面补0，然后进行相加

}

//对两个字符串相加
string addStrings(string& num1, string& num2) {
    int i = num1.size() - 1, j = num2.size() - 1, add = 0;
    string ans;
    while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0 ? num1.at(i) - '0' : 0;
        int y = j >= 0 ? num2.at(j) - '0' : 0;
        int result = x + y + add;
        ans.push_back(result % 10);
        add = result / 10;
        i--;
        j--;
    }
    reverse(ans.begin(), ans.end());
    for (auto& c : ans) {
        c += '0';
    }
    return ans;
}

string multipy2(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    string ans = "0";
    int m = num1.size(), n = num2.size();
    for (int i = n - 1; i >= 0; i--) {
        string curr;
        int add = 0;
        for (int j = n - 1; j > i; j--) {
            curr.push_back(0);
        }
        int y = num2.at(i) - '0';
        for (int j = m - 1; j >= 0; j--) {
            int x = num1.at(j) - '0';
            int product = x * y + add;
            curr.push_back(product % 10);
            add = product / 10;
        }
        while (add != 0) {
            curr.push_back(add % 10);
            add /= 10;
        }
        reverse(curr.begin(), curr.end());
        for (auto& c : curr) {
            c += '0';
        }
        ans = addStrings(ans, curr);
    }
    return ans;
}



int main() {
	return 0;
}