#include<iostream>
using namespace std;

#include<fstream>

int main_outstream() {
	const char* str1 = "I Love You";
	int n[5];
	ifstream in("xxx.xxx");
	ofstream out("yyy.yyy");
	out.write(str1, strlen(str1));//���ַ���str1ȫ��д��yyy.yyy�� 
	in.read((char*)n, sizeof(n));//��xxx.xxx�ж�ȡָ����������ע������ת�� 
	in.close(); out.close();
	return 0;
}
