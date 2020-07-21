#include<stdio.h>
#include<vector>
#include<deque>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int res = 0;
    vector<string> str;
    vector<bool> visited;
    int numSub(string s) {
        int cnt = 0;
        for (auto n : s)
            if (n == '1')
                cnt++;
        if (cnt < 2)
            return cnt;

        while (cnt > 1) {
            visited = vector<bool>(s.size(), 0);
            dfs(s, 0, cnt);
            cnt--;
        }
        return res + cnt;
    }
    void dfs(string s, int idx, int cnt) {
        deque<string> win;
        if (idx == s.size()) {
            res += str.size();
            str = {};
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            //if (visited[i])break;
            if (s[i] == '1') {
                win.push_back("1");
                if (win.size() == cnt) {
                    str.push_back(to_string(cnt));
                    win.pop_front();
                } 
            }
            else {
                win.clear();
            }
            visited[i] = true;
            dfs(s, idx + 1, cnt);
            visited[i] = false;
        }
    }

};

int main()
{
	Solution se;
    string s = "0110111";
    se.numSub(s);
	system("pause");
	return 0;
}
