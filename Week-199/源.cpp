#include<stdio.h>
#include<vector>
#include<map>
#include<string>
#include<iostream>

using namespace std;


//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    map<int, int> m;
    vector<int> node;
    int res;
    int dis = 0;
    int countPairs(TreeNode* root, int distance) {
        dfs(root);
        for (int i = 0; i < node.size()-1; i++) {
            for (int j = i + 1; j < node.size(); j++) {
                if (abs(m[node[i]] - m[node[j]]) < distance)
                    res++;
            }
        }
        return res;
    }
    void dfs(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (!root->left && !root->right)
            node.push_back(root->val);

        dfs(root->left);
        m[root->val] = dis;
        cout << root->val<<" "<<dis << endl;
        dis++;
        dfs(root->right);

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
    se.countPairs(root,3);
	system("pause");
	return 0;
}
