#include<iostream>
using namespace std;

#include<vector>
//利用双指针进行实现
//双指针在很多时候需要进行排序，那么这里不用，是因为是遍历穷举的时候不需要排序
int removeElement(vector<int>& nums, int val) {
    int left = 0, right = (int)nums.size();
    while (left < right) {
        if (nums[left] == val) {
            nums[left] = nums[right - 1];
            right--;
        }
        else {
            left++;
        }
    }
    return left;
}

int main_27() {
	vector<int>nums = { 3,2,2,3 };
    int result = removeElement(nums, 3);
	cout << removeElement(nums, 3)<<endl;
	for (int i = 0; i < result; ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}