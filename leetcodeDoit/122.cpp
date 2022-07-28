#include<iostream>
#include<vector>
using namespace std;


/*
获得股票的最佳时刻
*/
int maxProfit(vector<int>& prices) {
	int size = prices.size();
	//特殊情况的处理
	if (size == 1 || size == 0)
		return 0;
	
	//初始状态
	int left = 0, right = 1;
	int sum = 0;
	while (right<size && left<size)
	{
		if (prices[right] > prices[right-1])
		{
			if (right == size - 1)
				sum += prices[right] - prices[left];
			right++;
		}
		else
		{
			//记录下这个赚了多少钱
			sum += prices[right - 1] - prices[left];
			//重置left以及right
			left = right;
			right++;
		}

	}
	return sum;
}

int main_122() {
	vector<int>data = { 1,2,3,4,5 };
	cout<<maxProfit(data);
	return 0;
}