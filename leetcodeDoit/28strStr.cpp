#include<iostream>
using namespace std;

#include<string>

int strStr(string haystack, string needle) {
	if (haystack.size() < needle.size())
		return -1;
	
	//长度相同的话后面的循环会执行不了，长度差值为0
	if (haystack.size() == needle.size())
	{
		if (haystack == needle)
			return 0;
		else
			return -1;
	}
	int size = needle.size();
	for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
		string str1 = haystack.substr(i, size);
		if (str1 == needle)
			return i;
	}
	return -1;
	
}

#include<string.h>
int strStr2(string haystack, string needle) {
	if (haystack.size() < needle.size())
		return -1;

	//长度相同的话后面的循环会执行不了，长度差值为0
	if (haystack.size() == needle.size())
	{
		if (haystack == needle)
			return 0;
		else
			return -1;
	}
	int size = needle.size();

	//如果直接用c_str获取字符串，由于是取子串，获得的是临时值，取得的字符串就是空的了
	for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
		//string temp_str = haystack.substr(i, size);
		const char* str1 = (haystack.substr(i, size)).c_str();
		if (strcmp(str1,needle.c_str())==0)
			return i;
	}
	return -1;

}

/*
haystack = "hello", needle = "ll"
2

haystack = "aaaaa", needle = "bba"
-1
*/
int main_28() {
	string haystack = "hello";
	string needle = "ll";
	cout << strStr2(haystack, needle) << endl;
	return 0;
}