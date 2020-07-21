#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, 0));
        if ((s1.size() + s2.size()) != s3.size())
            return false;
        for (int i = 0; i <= s1.size(); i++) {
            for (int j = 0; j <= s2.size(); j++) {

                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0 && s2[j - 1] == s3[j - 1])
                    dp[i][j] = true;
                else if (j == 0 && s1[i - 1] == s3[i - 1])
                    dp[i][j] = true;
                else if (i != 0 && j != 0) {
                    if (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                        dp[i][j] = true;
                    if (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                        dp[i][j] = true;
                }
            }
        }
        return dp.back().back();
    }
};
int main()
{
	Solution se;
    string s1 = "db";
    string s2 = "b";
    string s3 = "cbb";
    se.isInterleave(s1, s2, s3);
	system("pause");
	return 0;
}
