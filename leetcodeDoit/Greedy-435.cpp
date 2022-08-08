//����һ������ļ��ϣ��ҵ���Ҫ�Ƴ��������С������ʹʣ�����以���ص���
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//�������С��������
bool cmp(vector<int>a,vector<int>b) {
	return a[1] > b[1];
}

//���Ͻⷨ
//1,2  2,3  5,6  1,5  4,7  1,5 
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	if (intervals.empty()) {
		return 0;
	}
	int n = intervals.size();
	sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
		return a[1] < b[1];
		});
	int total = 0, prev = intervals[0][1];
	for (int i = 1; i < n; ++i) {
		if (intervals[i][0] < prev) {
			++total;
		}
		else {
			prev = intervals[i][1];
		}
	}
	return total;
}

//�ٷ��ⷨ
int eraseOverlapIntervals2(vector<vector<int>>& intervals) {
	if (intervals.empty()) {
		return 0;
	}

	sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
		return u[1] < v[1];
		});



	int n = intervals.size();
	int right = intervals[0][1];
	int ans = 1;
	for (int i = 1; i < n; ++i) {
		if (intervals[i][0] >= right) {
			++ans;
			right = intervals[i][1];
		}
	}
	return n - ans;

}

//���Ĺ�ע�����:1,5����ǰ������С��5�Ķ�ȥ��,���������ܹ���С����һ�����������
int eraseOverlapIntervals_self0(vector<vector<int>>& intervals) {
	//ʱ�̹�ע�����������
	if (intervals.empty()) {
		return 0;
	}

	//��������
	sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
		return u[1] < v[1];
	});

	int n = intervals.size();
	int right = intervals[0][1];
	int ans = 1;
	for (int i = 1; i < n; ++i) {
		if (intervals[i][0] >= right) {
			++ans;
			right = intervals[i][1];
		}
	}
	//����ͳ���ų����ٸ�
	return n - ans;
}


//�Լ���������֮��,��Ϲٷ��Ľ��
int eraseOverlapIntervals_self3(vector<vector<int>>& intervals) {
	//ʱ�̹�ע�������
	if (intervals.empty()) {
		return 0;
	}

	//��������
	sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v){
		return u[1] < v[1];
		});

	int n = intervals.size();
	int right = intervals[0][1];
	int ans = 1;
	for (int i = 1; i < n; ++i) {
		//����ؼ���������:�Ƿ���Ҫ�޳�����Ҫ���(�������)  1,2 1,3 1,4 1,5 1,6 3,4==>1,2 3,4
		if (intervals[i][0] >= right) {
			++ans;
			right = intervals[i][1];
		}
	}
	return 0;
}

//�Լ���������֮��,��Ϲٷ��Ľ��
int eraseOverlapIntervals_self4(vector<vector<int>>& intervals) {
	//ʱ�̹�ע�������
	if (intervals.empty()) {
		return 0;
	}

	//��������
	sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
		return u[1] < v[1];
	});

	int n = intervals.size();
	int right = intervals[0][1];
	int ans = 1;
	for (int i = 1; i < intervals.size(); i++) {
		//����ؼ���������:�Ƿ���Ҫ�޳�����Ҫ���(�������)  1,2 1,3 1,4 1,5 1,6 3,4==>1,2 3,4
		//��ʵ�޳��ظ���ʱ�򲢲���Ҫ�׸���������,��Ҫ��ǰһ���ĺ����һ����ǰ���ص�
		if (intervals[i][0] >= right) {//��дһ��=
			ans++;
			right = intervals[i][1];
		}
	}
	return n - ans;
}


int main_435() {
	vector<vector<int>>intervals = { {1,2} ,{2,3},{3,4},{1,3} ,{3,5} ,{7,8} };
	cout << eraseOverlapIntervals2(intervals) << endl;
	cout<< eraseOverlapIntervals_self4(intervals)<<endl;

	cout << "-------------------------\n";
	for (auto temp : intervals) {
		for (auto child_temp : temp) {
			cout << child_temp << endl;
		}
	}


	system("pause");
	return 0;
}