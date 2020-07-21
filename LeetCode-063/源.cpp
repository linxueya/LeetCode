#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (v[i - 1][j - 1] == 1)continue;
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
        return dp[m][n];
    }
};

int main()
{
	Solution se;
    vector<vector<int>> v = { { 0,0,0,0},{0,1,0,0 }, { 0,0,0,0 } };
    se.uniquePathsWithObstacles(v);
	system("pause");
	return 0;
}
