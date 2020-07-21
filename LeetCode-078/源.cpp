#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> v;
    vector<bool> visited;
    int size = 1;
    vector<vector<int>> subsets(vector<int>& nums) {
        visited = vector<bool>(nums.size(), 0);
        dfs(nums, 0);
        return res;
    }
    void dfs(vector<int>& nums, int idx) {
        if (v.size() == size) {
            res.push_back(v);
            v.clear();
            if (idx == nums.size()) {
                idx = 0;
                size++;
            }
        }
        if (idx == nums.size() && v.size() == nums.size()) {
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])continue;
            v.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, i + 1);
            visited[i] = false;

        }
        return;
    }
};

int main()
{
	Solution se;
    vector<int> v = { 1,2,3 };
    se.subsets(v);
	system("pause");
	return 0;
}
