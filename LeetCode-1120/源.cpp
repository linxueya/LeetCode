#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
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
    double avg = 0;
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root); 
        return avg;
    }
    void dfs(TreeNode* root) {
        double res;
        int cnt = 0;
        if (!root)
            return;
        sumnode(root, res, cnt);
        avg = max(avg, res);
        cout<<res<<endl;
        dfs(root->left);
        dfs(root->right);
    }
    void sumnode(TreeNode* root, double& res, int& cnt) {
        if (!root)
            return;
        res += root->val;
        sumnode(root->left, res, cnt + 1);
        sumnode(root->right, res, cnt + 1);
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
    se.maximumAverageSubtree(root);
	system("pause");
	return 0;
}
