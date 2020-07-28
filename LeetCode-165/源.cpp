#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int compareVersion(string v1, string v2) {
        int left1 = 0, left2 = 0;
        int right1 = 0, right2 = 0;

        while (right1 < v1.size() || right2 < v2.size()) {

            string s1, s2;
            while ( right1 < v1.size() && v1[right1] != '.')
                right1++;
            while ( right2 < v2.size() && v2[right2] != '.' )
                right2++;

            if (left1 >= v1.size())
                s1 = "0";
            else
                s1 = v1.substr(left1, right1 - left1);

            if (left2 >= v2.size())
                s2 = "0";
            else
                s2 = v2.substr(left2, right2 - left2);

            cout << s1 << " " << s2 <<" "<< right1 << " " << right2 <<endl;
            //cout<<left1 <<" "<<right1<<endl;
            if (stoi(s1) < stoi(s2))
                return -1;
            else if (stoi(s1) > stoi(s2))
                return 1;

            right1++;
            right2++;
            left1 = right1;
            left2 = right2;
        }
        return 0;
    }
};

int main()
{
	Solution se;
    string s1 = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
    string s2 = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
    cout<<stoi("00000000000") << endl;
    se.compareVersion(s1, s2);
    system("pause");
	return 0;
}
