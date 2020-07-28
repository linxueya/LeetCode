#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> v(nums1.begin(), nums1.end());
        v.insert(v.end(), nums2.begin(), nums2.end());
        int n = v.size();
        quicksort(v, 0, n - 1);

        if (n % 2 != 0)
            return (double)v[n / 2];
        else
            return ((double)(v[n / 2] + v[n / 2 - 1])) / 2;

    }
    void quicksort(vector<int>& v, int left, int right) {
        while (left < right) {
            int point = partition(v, left, right);
            quicksort(v, left, point - 1);
            quicksort(v, point + 1, right);
            cout << "_____" << endl;
        }
    }
    int partition(vector<int>& v, int left, int right) {
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
            while (left < right && v[left] <= point)
                left++;
            v[right] = v[left];
        }
        v[left] = point;
        return left;
    }
};
int main()
{
	Solution se;
    vector<int> a = { 1,2,3 };
    vector<int> b = { 3,4,5 };
    se.findMedianSortedArrays(a, b);
	system("pause");
	return 0;
}
