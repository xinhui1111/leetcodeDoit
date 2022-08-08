#include<iostream>
#include<algorithm>
using namespace std;

#include<vector>

//������Ϊ0
//ʹ��˫ָ�뷨����Ҫ���ȶ������������
vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) return {};
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());
    // O(n^2)
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // �� i + 1 ... nums.length - 1 �в�����ӵ��� -nums[i] ��������
        int target = -nums[i];
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                res.push_back({ nums[i], nums[left], nums[right] });
                 // ȥ��
                while (left < right && nums[left] == nums[++left]);
                while (left < right && nums[right] == nums[--right]);
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    return res;
}

int main_15() {
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> res = threeSum(nums);
	for (auto i : res) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}