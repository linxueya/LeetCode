#include <iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int idx = s.length();
		for (int i = 0; i < s.length()-1;i++)
		{
			if (s[i] == ' ' && s[i+1] != ' ')
				idx = s.length() - i-1;
		}
		return idx;
	}
};


int main() {

	string s = " H ";
	class Solution re;
	int n = 0;
	n = re.lengthOfLastWord(s);
	cout << n << endl;
	system("pause");
}