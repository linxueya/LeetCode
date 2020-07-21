#include<stdio.h>
#include<vector>
#include<set>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> s;
    string res;
    vector<bool> visited;
    vector<string> permutation(string S) {
        visited = vector<bool>(S.size(),0);
        dfs(S, 0);
        return s;
    }
    void dfs(string str, int idx) {
        
        if ( res.size() == str.size()) {
            s.push_back(res);
            cout << res << endl;
            return;
        }
        for (int i = 0; i < str.size(); i++) {
            if (visited[i])continue;
            if (i > 0 && str[i] == str[i - 1] && !visited[i-1])continue;
            res += str[i];
            visited[i] = true;
            dfs(str, i + 1);
            visited[i] = false;
            res.pop_back();
        }

    }
};

int main()
{
	Solution se;
    string str = "qqe";
    se.permutation(str);
	system("pause");
	return 0;
}
