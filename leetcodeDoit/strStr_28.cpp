#include<iostream>
#include<string>
using namespace std;


/*
输入：haystack = "hello", needle = "ll"
输出：2
*/
int strStr(string haystack, string needle) {
	int n = haystack.size(), m = needle.size();
	for (int i = 0; i + m <= n; i++) {
		bool flag = true;
		for (int j = 0; j < m; j++) {
			if (haystack[i + j] != needle[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return i;
		}
	}
	return -1;
}


#include<vector>
int strStr3(string haystack, string needle) {
	int haystack_len = haystack.length();
	int needle_len = needle.length();

	vector<int>vector_int = { 1,2,3,4,5 };
	for (auto var : vector_int) {
		cout << "var: " << var << endl;
	}
	return 1;
}
//int strStr3(string haystack, string needle) {
//    int haystack_len = haystack.length(), needle_len = needle.length();
//    vector<int>vector_string = { 1,2,3,4 };
//    for(auto var:vector_string)
//    {
//          
//    }
//
//}




/*
输入：haystack = "hello", needle = "ll"
输出：2
*/
void main_str() {
    string str1 = "hello";
    string needle = "ll";
    cout<<strStr(str1, needle)<<endl;
}