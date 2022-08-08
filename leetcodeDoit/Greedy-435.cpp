//给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//对区间大小进行排序
bool cmp(vector<int>a,vector<int>b) {
	return a[1] > b[1];
}

//书上解法
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

//官方解法
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

//核心关注点就是:1,5放在前面会后面小于5的都去除,而放在则能够把小区段一个个组合起来
int eraseOverlapIntervals_self0(vector<vector<int>>& intervals) {
	//时刻关注这种特殊情况
	if (intervals.empty()) {
		return 0;
	}

	//进行排序
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
	//进行统计排除多少个
	return n - ans;
}


//自己经过整理之后,结合官方的解答
int eraseOverlapIntervals_self3(vector<vector<int>>& intervals) {
	//时刻关注特殊情况
	if (intervals.empty()) {
		return 0;
	}

	//进行排序
	sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v){
		return u[1] < v[1];
		});

	int n = intervals.size();
	int right = intervals[0][1];
	int ans = 1;
	for (int i = 1; i < n; ++i) {
		//这里关键的问题是:是否需要剔除满足要求的(对于起点)  1,2 1,3 1,4 1,5 1,6 3,4==>1,2 3,4
		if (intervals[i][0] >= right) {
			++ans;
			right = intervals[i][1];
		}
	}
	return 0;
}

//自己经过整理之后,结合官方的解答
int eraseOverlapIntervals_self4(vector<vector<int>>& intervals) {
	//时刻关注特殊情况
	if (intervals.empty()) {
		return 0;
	}

	//进行排序
	sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
		return u[1] < v[1];
	});

	int n = intervals.size();
	int right = intervals[0][1];
	int ans = 1;
	for (int i = 1; i < intervals.size(); i++) {
		//这里关键的问题是:是否需要剔除满足要求的(对于起点)  1,2 1,3 1,4 1,5 1,6 3,4==>1,2 3,4
		//其实剔除重复的时候并不需要首个进行排序,主要是前一个的后与后一个的前不重叠
		if (intervals[i][0] >= right) {//少写一个=
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