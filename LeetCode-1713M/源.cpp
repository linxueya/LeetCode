#include<stdio.h>
#include<vector>
#include<string>
#include<list>
#include<unordered_map>
#include<iostream>

using namespace std;

class Solution {
public:
    int respace(vector<string>& dict, string sen) {
        unordered_map<string, int> m;
        vector<string> str;
        int pre = 0;
        int res = 0;
        list<int> list;
        vector<int> v(list.begin(), list.end());
        for (auto n : dict)
            m[n] = 1;
        for (int i = 0; i < sen.size() - 1; i++) {
            for (int j = i + 1; j < sen.size(); j++) {
                string temp = sen.substr(i, j - i + 1);
                if (m.find(temp) != m.end()) {
                    str.push_back(temp);
                    res += temp.size();
                    i = j;
                    break;
                }
            }
        }
        return sen.size() - res;
    }
};

int main()
{
	Solution se;
    vector<string> v = { "vprkj","sqvuzjz","ptkrqrkussszzprkqrjrtzzvrkrrrskkrrursqdqpp","spqzqtrqs","rkktkruzsjkrzqq","rk","k","zkvdzqrzpkrukdqrqjzkrqrzzkkrr","pzpstvqzrzprqkkkd","jvutvjtktqvvdkzujkq","r","pspkr","tdkkktdsrkzpzpuzvszzzzdjj","zk","pqkjkzpvdpktzskdkvzjkkj","sr","zqjkzksvkvvrsjrjkkjkztrpuzrqrqvvpkutqkrrqpzu" };
    string str = "rkktkruzsjkrzqqzkvdzqrzpkrukdqrqjzkrqrzzkkrr";
    se.respace(v, str);
	system("pause");
	return 0;
}
