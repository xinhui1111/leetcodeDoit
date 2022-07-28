#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;


int main_test() {
	unordered_map<string, vector<string>> mp{ { "start", {"start", "signed", "in_number", "end"} } };
	for (auto temp : mp) {
		cout << temp.first;
	}
	return 0;
}