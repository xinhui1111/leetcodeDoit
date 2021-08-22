
#include<vector>
#include <iostream>
#include<algorithm>
using namespace std;

/*
*输入: g = [1,2,3], s = [1,1]
*输出: 1
* 题目:对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；
*并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，
*这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
*/
int findContentChildren(vector<int>& g, vector<int>& s) {
	//1.进行排序
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());

	//2.将g中的饥饿度(胃口值)依次从小到大解决掉
	int count = 0;
	for (auto temp_g = g.begin(); temp_g < g.end(); temp_g++)
		for (auto temp_s = s.begin(); temp_s < s.end(); temp_s++) {
			if (*temp_g <= *temp_s)
			{
				++count;
				s.erase(temp_s);
				break;
			}
			else
			{
				if (temp_s != s.end() - 1)
					continue;
				else
					return count;
			}

		}
	return count;
}

int findContentChildren1(vector<int>& g, vector<int>& s) {
	//1.进行排序
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());

	//2.将g中的饥饿度(胃口值)依次从小到大解决掉
	int count = 0;
	int flag = 0;
	for (int temp_g = 0; temp_g < g.size(); temp_g++)
	{

		for (int temp_s = flag; temp_s < s.size(); temp_s++) {
			if (g[temp_g] <= s[temp_s])
			{
				++count;
				if (temp_s >= s.size() - 1)
				{
					return count;
				}
				else {
					flag = temp_s+1;//这里需要进行加1
					break;
				}
				
			}
			else
			{
				if (temp_s != s.size() - 1)
					continue;
				else
					return count;
			}

		}
	}
	return count;
}

int main_455()
{
	/*vector<int>g = { 10,9,8,7 };
	vector<int>s = { 5,6,7,8};*/
	/*vector<int>g = { 1,2,3 };
	vector<int>s = { 3 };*/
	vector<int>g = { 10, 9, 8, 7, 10, 9, 8, 7 };
	vector<int>s = { 10, 9, 8, 7 };
	cout << findContentChildren1(g, s) << endl;


	system("pause");
	return 0;
}
