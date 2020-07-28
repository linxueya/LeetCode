#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>

using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<vector<int>> res;
	vector<int> v;
	vector<vector<int>> findLeaves(TreeNode* root) {
		if (!root)
			return res;
		while (root->left || root->right) {
			v = {};
			dfs(root, root);
			res.push_back(v);
		}
		res.push_back({ root->val });
		return res;
	}
	void dfs(TreeNode* root, TreeNode* pre) {
		if (!root)
			return;
		if (!root->left && !root->right) {
			v.push_back(root->val);
			if (pre->left == root)
				pre->left = NULL;
			else
				pre->right = NULL;
			return;
		}
		dfs(root->left, root);
		dfs(root->right, root);
	}
};

void InsertIntoBitTree(TreeNode** root, int data)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->val = data;
	newNode->left = NULL;
	newNode->right = NULL;
	if (*root == NULL)//说明是空树
	{
		*root = newNode;//将新结点的指针newNode赋值给根结点的指针
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if ((*root)->left == NULL)
		(*root)->left = newNode;
	else if ((*root)->right == NULL)
		(*root)->right = newNode;
	else
		InsertIntoBitTree(&((*root)->left), data);
}
int main()
{
	Solution se;
	TreeNode* root = new TreeNode(1);
	InsertIntoBitTree(&root, 2);
	InsertIntoBitTree(&root, 3);
	InsertIntoBitTree(&root->left, 4);
	InsertIntoBitTree(&root->left, 5);
	InsertIntoBitTree(&root->right, 6);
	InsertIntoBitTree(&root->right, 7);
	se.findLeaves(root);
	system("pause");
	return 0;
}
