/*
 * @lc app=leetcode.cn id=1219 lang=cpp
 *
 * [1219] 黄金矿工
 */

// @lc code=start
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid.size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else if(i == 0 && j != 0)
                    dp[j][j] = dp[i][j-1] + grid[i][j];
                else if(i != 0 && j == 0)
                    dp[j][j] = dp[i-1][j] + grid[i][j];
                else
                    dp[j][j] = max(dp[i][j-1] + grid[i][j],dp[i-1][j]+grid[i][j]);
                res = max(res,dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end

