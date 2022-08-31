#include<iostream>
using namespace std;

#include<vector>
//����˫ָ�����ʵ��
//˫ָ���ںܶ�ʱ����Ҫ����������ô���ﲻ�ã�����Ϊ�Ǳ�����ٵ�ʱ����Ҫ����
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