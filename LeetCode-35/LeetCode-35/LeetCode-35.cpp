#include <iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

//暴力法
//class Solution {
//public:
//	int searchInsert(vector<int>& nums, int target) {
//		int idx = 0;
//		for (int i = 0; i < nums.size();i++)
//		{
//			if (target < nums[0])
//				idx = 0;
//			else if (target == nums[i])
//				idx = i;
//			else if (target > nums[i])
//				idx = i + 1;
//		}
//		return idx;
//	}
//};

//二分查找
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right =nums.size()-1;
		int mid = 0;
		while (left <= right)
		{
			mid = (left + right) / 2;
			cout << mid;
			if (target < nums[mid])
				right = mid - 1;
			else if (target > nums[mid])
				left = mid + 1;
			else
				return mid;
		}
		return left;
	}
};

int main() {

	vector<int> s = { 1, 3, 6, 7, 9 };
	class Solution re;
	int num = 6;
	int n = 0;
	n = re.searchInsert(s, num);
	cout << n << endl;
	system("pause");
}