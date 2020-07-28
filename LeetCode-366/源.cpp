#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>

using namespace std;



// Definition for a binary tree node.
struct TreeNode {
		int val;
      	TreeNode *left;
      	TreeNode *right;
      	TreeNode() : val(0), left(nullptr), right(nullptr) {}
      	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution{
public:
	vector<vector<int>> res;
	vector<int> v;
	vector<vector<int>> findLeaves(TreeNode* root) {
		 if (!root)
			return res;
		while (root) {
			v  = {};
			dfs(root,root);
			res.push_back(v);
		}
		return res;
	}
	void dfs(TreeNode* root, TreeNode* pre) {
		if (!root)
			return;
		if (!root->left  && !root->right) {
			v.push_back(root->val);
			cout << root->val;
			if (pre->left  == root)
				pre->left  = NULL;
			else if(pre->right  == root)
				pre->right  = NULL;
			else
				root  = NULL;
			return;
		}
		dfs(root->left,root);
		dfs(root->right,root);
	}
};

int main()
{
	Solution se;

	system("pause");
	return 0;
}
