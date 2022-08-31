#include<iostream>
using namespace std;

#include<fstream>

int main_outstream() {
	const char* str1 = "I Love You";
	int n[5];
	ifstream in("xxx.xxx");
	ofstream out("yyy.yyy");
	out.write(str1, strlen(str1));//把字符串str1全部写到yyy.yyy中 
	in.read((char*)n, sizeof(n));//从xxx.xxx中读取指定个整数，注意类型转换 
	in.close(); out.close();
	return 0;
}
