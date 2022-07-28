/*
测试lamda表达式
输出结果：
	result：43
*/

#include<iostream>
using namespace std;


#include<string>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>
int main_lamda() {
	int i = 10;
	//[]进行捕获lamda函数之外的值，那么在lamda表达式里面也可以用
	//auto f3 = [j] () { return j; };		//进行了捕获，函数体内可以使用了
	//[fn = hash<int>{}](const array<int, 26>& arr)->size_t {fn(num)}
	auto f1=[i=2](int int_i, int int_j) {
		return int_i + int_j*2+34;
	};
	int result=f1(1, 4);
	cout << "result：" << result << endl;

	//测试hash函数
	//string hash_test = std::hash<int>{};
	return 0;
}