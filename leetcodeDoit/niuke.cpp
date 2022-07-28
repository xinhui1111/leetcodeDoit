#include<stdio.h>
void add(int* p) {
	(*p)++;
	printf("%d", *p);
	if (*p > 5) {
		return;
	}
	add(p);
}


#include<string>
#include <iostream>
using namespace std;
int main_niuke() {
	std::string str = "string";
	str +="hello";
	std::cout << "str" << str << endl;
	cout << "=========" << endl;
	int i = 0;
	add(&i);

	return 0;
}


