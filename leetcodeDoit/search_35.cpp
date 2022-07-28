/**
* 
* 
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/search-insert-position
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
* 
* ���ӣ�
	����: nums = [1,3,5,6], target = 5
	���: 2
*/

#include<stdio.h>


int searchInsert(int* nums, int numsSize, int target) {
	int right= numsSize - 1, left=0;
	int mid = (right + left) / 2;
	int ans = numsSize;//��ʼֵ������
	while (left<right)
	{
		if (target <= nums[mid]) {//��mid��λΪ1��right�ͻᶨλΪ0��0��λ����
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
	
	return ans;//���ض�Ӧ���±�
}


int searchInsert2(int* nums, int numsSize, int target) {
	int left = 0, right = numsSize - 1, ans = numsSize;
	while (left <= right) {//����ע����С�ڵ���
		int mid = ((right - left) >> 1) + left;//������ʼ��
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