//#include<iostream>
//#include<vector>
//using namespace std;
//
//int search(vector<int>& nums, int target) {
//
//}
//
//
///*
//ÊäÈë£ºnums = [4,5,6,7,0,1,2], target = 0
//Êä³ö£º4
//*/
//int main() {
//
//	return 0;
//}

#include <algorithm>    // std::transform
#include <iostream>
#include<vector>

std::vector<int>& modifyVector(std::vector<int>& data, int upperBound)
{
	auto modifyFunc = [upperBound](int item) ->int { return (item >= upperBound) ? 0 : item; };
	std::transform(data.begin(), data.end(), data.begin(), modifyFunc);
	return data;
}

void printVector(const std::vector<int>& data)
{
	for (auto item = data.cbegin(); item != data.cend(); item++)
	{
		std::cout << *item << " ";
	}
	std::cout << std::endl;
}


/*
original data: 6 4 3 4 5 7 8 7 6 6 5
modified data: 6 4 3 4 5 0 0 0 6 6 5
*/
int main_search_rotation()
{
	std::vector<int> data{ 6,4,3,4,5,7,8,7,6,6,5 };
	std::cout << "original data: ";
	printVector(data);

	modifyVector(data, 7);
	std::cout << "modified data: ";
	printVector(data);
	return 0;
}