#include<iostream>
#include<vector>
using namespace std;


/*
��ù�Ʊ�����ʱ��
*/
int maxProfit(vector<int>& prices) {
	int size = prices.size();
	//��������Ĵ���
	if (size == 1 || size == 0)
		return 0;
	
	//��ʼ״̬
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
			//��¼�����׬�˶���Ǯ
			sum += prices[right - 1] - prices[left];
			//����left�Լ�right
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