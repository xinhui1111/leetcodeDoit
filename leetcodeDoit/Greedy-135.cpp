#include<iostream>
#include<vector>
using namespace std;

/*
*@input��[1,0,2]
*output��5
*@���ͣ�����Էֱ�����������ӷַ� 2��1��2 ���ǹ���
*/
int candy(vector<int>& ratings) {
	if (ratings.size() == 1)
		return 1;
	if (ratings.size() == 0)
		return 0;
	//����һ������ȥ�洢�����ǹ���,��ʼֵ����Ϊ1
	int* candy = (int*)malloc(sizeof(int) * ratings.size());
	for (int i = 0; i < ratings.size(); ++i)
		candy[i] = 1;
	//�ҵ���Сֵ
	int min = ratings[0];
	int min_position = 0;
	for (int i = 1; i < ratings.size(); ++i) {
		if (min > ratings[i])
		{
			min = ratings[i];
			min_position = i;
		}
	}
	//�Կ�����ֵ���м�1,����һ�����ھ��ǲ��Ǵ�,��Ļ�,����Ļ��Ͳ���i��j
	int i = min_position-1;
	int j = min_position + 1;
	int left_position = min_position;
	int right_position = min_position;

	if (ratings[0] > ratings[1])
		candy[0] = 2;
	//2.1 �ж���ߵ�
	//��������
	for (int left_i = i; left_i > 0; left_i--)
	{
		if (ratings[left_i] > ratings[left_i - 1]) {
			candy[left_i] = candy[left_i - 1]+1;
			if (ratings[left_i] > ratings[left_position]) {
				candy[left_i]= candy[left_i - 1] > candy[left_position] ? candy[left_i - 1] + 1: candy[left_position] + 1;
			}
		}
		else {
			if (ratings[left_i] > ratings[left_position]) {
				candy[left_i] = candy[left_position]+1;
			}
		}
		left_position--;
	}

	//��������
	if (ratings[0] > ratings[1])
		candy[0] = candy[1] + 1;
	left_position = 1;
	for (int left_i = 1; left_i <= i; left_i++) {
		if (ratings[left_i] > ratings[left_i-1]) {
			candy[left_i] = candy[left_i -1] + 1;
			if (ratings[left_i] > ratings[left_position]) {
				candy[left_i] = candy[left_i-1 ] > candy[left_position] ? candy[left_i-1 ] + 1 : candy[left_position] + 1;
			}
		}
		else {
			if (ratings[left_i] > ratings[left_position]) {
				candy[left_i] = candy[left_position] + 1;
			}
		}
		left_position++;
	}

	//2.2 �ж��ұߵ�
	for (int right_i = j; right_i < ratings.size()-1; right_i++)
	{
		if (ratings[right_i] > ratings[right_i + 1]) {
			candy[right_i] = candy[right_i + 1]+1;
			if (ratings[right_i] > ratings[right_position])
			{
				candy[right_i]=candy[right_i+1] + 1 > candy[right_position] + 1 ? candy[right_i+1] + 1: candy[right_position] + 1;
			}
				
		}
		else {
			if (ratings[right_i] > ratings[right_position])
				candy[right_i]= candy[right_position]+1;
		}
		right_position++;
	}

	if (ratings[ratings.size() - 2] < ratings[ratings.size() - 1])
		candy[ratings.size() - 1] = candy[ratings.size() - 2]+1;

	//����������
	right_position = ratings.size() - 2;
	for (int right_i = ratings.size() - 1; right_i >min_position; right_i--) {
		if (right_i + 1<ratings.size() && ratings[right_i] > ratings[right_i + 1]) {
			candy[right_i] = candy[right_i + 1] + 1;
			if (ratings[right_i] > ratings[right_position])
			{
				candy[right_i] = candy[right_i+1] + 1 > candy[right_position] + 1 ? candy[right_i+1] + 1 : candy[right_position] + 1;
			}

		}
		else {
			if (right_i + 1 < ratings.size() && ratings[right_i] > ratings[right_position])
				candy[right_i] = candy[right_position] + 1;
		}
		right_position--;
	}

	int Summary = 0;
	for (int Summary_i = 0; Summary_i < ratings.size(); Summary_i++) {
		Summary += candy[Summary_i];
	}
	return Summary;
}

//TODO:��д����3��,����ע��i > 0 &&��i < n - 1 &&
//�ٷ����: �ȼ�������������,Ȼ������ҹ����ʱ��ֻ��Ҫ�õ���������¼��ǰλ�õ��ҹ���ͬʱ����𰸼���
int candy_official(vector<int>& ratings) {
	int n = ratings.size();
	vector<int> left(n);
	for (int i = 0; i < n; i++) {
		if (i > 0 && ratings[i] > ratings[i - 1]) {
			left[i] = left[i - 1] + 1;
		}
		else {
			left[i] = 1;
		}
	}
	int right = 0, ret = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (i < n - 1 && ratings[i] > ratings[i + 1]) {
			right++;
		}
		else {
			right = 1;
		}
		ret += max(left[i], right);
		cout << "-----------------\n" << max(left[i], right) << endl;
	}
	return ret;
}

int main_135() {
	vector<int>rating = { 1,0,2 };
	vector<int>rating2 = { 1,2,2 };
	vector<int>rating_error = { 1,3,2,2,1 };
	vector<int>rating_error1 = { 1,3,2,2,1 };
	vector<int>rating_error2 = { 29,51,87,87,72,12 };
	vector<int>rating_error3 = { 1,3,2,2,1};
	vector<int>rating_error4 = { 1,2,3 };
	vector<int>rating_error5 = { 3,2,1,1,4,3,3};
	vector<int>rating_error6 = {0};
	cout << candy(rating_error6) << endl;
	cout << candy_official(rating_error5) << endl;

	system("pause");
	return 0;
}


//�����Լ���˼·�Ǽ����һ����Сֵ,���𲽼����ʱ������������ͬʱ����,����û�п��ǵ�����ֵ��ȵ�ʱ��
//�Լ��������ұ��Ƶ�ʱ����һ��ֵ�ǲ�ȷ����,��ô֮��Ҫ����һ�²��ܻ����ȷֵ,ͬ���������Ҳ��һ���Ľ��
//