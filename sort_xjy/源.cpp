#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
	void InsertSort(vector<int>& v) {
		int n = v.size();
		for (int i = 1; i < n; i++)
		{
			if (v[i] < v[i - 1])
			{
				int temp = v[i];
				int j = i - 1;
				while (j >= 0 && temp < v[j]) {
					v[j + 1] = v[j];
					j--;
				}
				v[j+1] = temp;
			}
		}
	}
	void quicksort(vector<int>& v,int left,int right) {

		if (left < right) {
			int point = Partition(v, left, right);
			quicksort(v,left, point - 1);
			quicksort(v, point + 1, right);
		}
	}
	int Partition(vector<int>& v, int left, int right) {
		int mid = left + (right - left) / 2;
		if (v[mid] > v[right])
			swap(v[mid], v[right]);
		if (v[left] > v[right])
			swap(v[left], v[right]);
		if (v[mid] > v[left])
			swap(v[mid], v[left]);
		int point = v[left];
		while (left < right) {
			while (left < right && v[right] >= point)
				right--;
			v[left] = v[right];
			while (left<right && v[left] <= point)
				left++;
			v[right] = v[left];

		}
		v[left] = point;
		return left;
	}
	void selectsort(vector<int>& v) {
		int n = v.size();
		for (int i = 0; i < n-1; i++)
		{
			int min = v[i];
			int idx = i;
			for (int j = i+1; j < n; j++)
			{
				if (v[j] < min)
				{
					min = v[j];
					idx = j;
				}
			}
			if (idx != i)
				swap(v[i], v[idx]);
		}

	}

	void bubblesort1(vector<int>&  v){
		int n = v.size();
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (v[j] <= v[i])
					swap(v[i], v[j]);
			}
		}
	}

	void bubblesort2(vector<int>& v) {
		int n = v.size();
		int flag = 1;
		for (int i = 0; i < n - 1 && flag; i++)
		{
			for (int j = n - 1; j > i; j--)
			{
				flag = 0;
				if (v[j] <= v[j-1]) {
					flag ++;
					swap(v[j-1], v[j]);
				}
					
			}
		}
	}

	vector<int> mergesort(vector<int>& v,int n) {
		if (v.size() == 1)
			return vector<int >(1, v[0]);
		if (v.size() == 0) {
			return vector<int >();
		}

		vector<int> left(v.begin(), v.begin() + n / 2),
			right(v.begin() + n / 2, v.end());
		left = mergesort(left, left.size());
		right = mergesort(right, right.size());
		return merge(left, right);

	}

	vector<int> merge(vector<int>& a, vector<int>& b) {

		int i = 0;
		int j = 0;
		vector<int> res;
		while(i < a.size() && j < b.size()) {
			if (a[i] < b[j])
				res.push_back(a[i++]);
			else if (a[i] >= b[j])
				res.push_back(b[j++]);
		}
		while(i < a.size())
			res.push_back(a[i++]);
		while (j < b.size())
			res.push_back(b[j++]);
		return res;
	}
};

int main()
{
	Solution se;
	vector<int> v = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	v = se.mergesort(v,10);
	printf("排序后的结果是：");
	for (auto n : v)
	{
		cout << n<<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}
