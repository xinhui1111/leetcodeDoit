/**
* 
* 
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-insert-position
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
* 
* 例子：
	输入: nums = [1,3,5,6], target = 5
	输出: 2
*/

#include<stdio.h>


int searchInsert(int* nums, int numsSize, int target) {
	int right= numsSize - 1, left=0;
	int mid = (right + left) / 2;
	int ans = numsSize;//起始值的设置
	while (left<right)
	{
		if (target <= nums[mid]) {//当mid定位为1，right就会定位为0，0的位置是
			ans = mid;
			right = mid-1;
		}
		else if(target>nums[mid])
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
		mid = (right + left) / 2;
	}
	
	return ans;//返回对应的下标
}


int searchInsert2(int* nums, int numsSize, int target) {
	int left = 0, right = numsSize - 1, ans = numsSize;
	while (left <= right) {//这里注意是小于等于
		int mid = ((right - left) >> 1) + left;//加上起始点
		if (target <= nums[mid]) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ans;
}


int main_35(void) {
	printf("start \n");
	int nums[] = { 1,3,5,6 };
	int result=searchInsert(nums, 4, 4);
	printf("%d\n", result);

	
	return 0;
}