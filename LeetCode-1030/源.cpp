#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;


class Solution {
public:
    int r0, c0;
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        this->r0 = r0;
        this->c0 = c0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                res.push_back({ i, j });
            }
        }
        sort(res.begin(), res.end(), [r0, c0](vector<int> a, vector<int> b) {
            return  (abs(a[0] - r0) + abs(a[1] - c0)) < (abs(b[0] - r0) + abs(b[1] - c0)); 
            });
        return res;
    }
};
class mycmp : public Solution
{
public:
    bool operator()(vector<int> a, vector<int> b) {
        return (abs(a[0] - r0) + abs(a[1] - c0)) < (abs(b[0] - r0) + abs(b[1] - c0));
    }
};

int main()
{
	Solution se;
    se.allCellsDistOrder(1, 2, 0, 0);
	system("pause");
	return 0;
}
