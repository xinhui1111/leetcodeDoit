/*
����lamda���ʽ
��������
	result��43
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
	//[]���в���lamda����֮���ֵ����ô��lamda���ʽ����Ҳ������
	//auto f3 = [j] () { return j; };		//�����˲��񣬺������ڿ���ʹ����
	//[fn = hash<int>{}](const array<int, 26>& arr)->size_t {fn(num)}
	auto f1=[i=2](int int_i, int int_j) {
		return int_i + int_j*2+34;
	};
	int result=f1(1, 4);
	cout << "result��" << result << endl;

	//����hash����
	//string hash_test = std::hash<int>{};
	return 0;
}