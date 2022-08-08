#include<iostream>
#include<algorithm>
using namespace std;

#include<vector>

//几个和为0
//使用双指针法，需要首先对数组进行排序
vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) return {};
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());
    // O(n^2)
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // 在 i + 1 ... nums.length - 1 中查找相加等于 -nums[i] 的两个数
        int target = -nums[i];
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                res.push_back({ nums[i], nums[left], nums[right] });
                 // 去重
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