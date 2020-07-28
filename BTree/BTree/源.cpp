#include<stdio.h>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<iostream>

using namespace std;

//结构体定义
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//二叉树插入，从终端输入
	void BiTrinsert(TreeNode** pRoot) {
		char c = ' ';
		scanf_s("%c", &c);
		if (' ' == c)
		{
			*pRoot = NULL;
		}
		else
		{
			TreeNode* newNode = new TreeNode(atoi(&c));
			(*pRoot) = newNode;
			BiTrinsert(&(*pRoot)->left);
			BiTrinsert(&(*pRoot)->right);
		}
	}
	//二叉树插入，从data赋值
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
	//求二叉树的最大深度
	int maxDepth(TreeNode* root) {
		if (root == NULL)  return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return max(left, right) + 1;
	}

	//求二叉树的最小深度
	int minDepth(TreeNode* root) {

		int lh = 1, rh = 1;
		if (root == NULL)
			return 0;
		lh += minDepth(root->left);
		rh += minDepth(root->right);
		if (lh == 1)
			return rh;
		else if (rh == 1)
			return lh;
		return lh <= rh ? lh : rh;
	}

	//二叉树的前序遍历
	void preView(TreeNode* root) {
		if (root != NULL) {
			cout << root->val << " ";
			preView(root->left);
			preView(root->right);
		}
	}

	//二叉树的中序遍历
	void midView(TreeNode* root) {
		if (root != NULL) {
			midView(root->left);
			cout << root->val << " ";
			midView(root->right);
		}
	}

	//二叉树的后序遍历
	void postView(TreeNode* root) {
		if (root != NULL) {
			postView(root->left);
			postView(root->right);
			cout << root->val << " ";
		}
	}

	//二叉树的层序遍历
	void levelView(TreeNode* root) {
		vector<int> s;
		queue<TreeNode*> p, q;
		p.push(root);    q = p;
		while (!p.empty()) {
			p = queue<TreeNode*>();
			s.clear();
			while (!q.empty()) {
				TreeNode* tmp = q.front();
				q.pop();
				s.push_back(tmp->val);
				if (tmp->left != NULL)  p.push(tmp->left);
				if (tmp->right != NULL)  p.push(tmp->right);
			}
			for (auto i : s)  cout << i << " ";
			cout << endl;
			q = p;
		}
	}
	//求二叉树的节点个数
	int nodeNumbers(TreeNode* root) {
		if (root == NULL)  return 0;
		int left = nodeNumbers(root->left);
		int right = nodeNumbers(root->right);
		return left + right + 1;
	}

	//求二叉树的叶节点个数
	int leafNodeNumbers(TreeNode* root) {
		if (root == NULL)  return 0;
		if (root->left == NULL && root->right == NULL)  return 1;
		return leafNodeNumbers(root->left) + leafNodeNumbers(root->right);
	}

	//判断二叉树是否为平衡二叉树
	int countFloor(TreeNode* root) {//计算层数
		if (!root)  return 0;
		return 1 + max(countFloor(root->left), countFloor(root->right));
	}
	bool isBalanced(TreeNode* root) {
		if (!root)  return true;
		if (abs(countFloor(root->left) - countFloor(root->right)) > 1)  return false;
		else  return isBalanced(root->left) && isBalanced(root->right);
	}

	//判断二叉树是否为满二叉树
	bool isFullTree(TreeNode* root) {
		if (root == NULL)  return true;
		int n = nodeNumbers(root) + 1;//满二叉树节点数为2^n-1，利用算法7求节点数
		while (n > 1) {
			if (n % 2 == 1)  return false;
			n /= 2;
		}
		return true;
	}
	//判断两个树是否完全相同
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		if (q != NULL && p != NULL) {
			if (q->val != p->val) return false;
			else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		else
			return false;
	}

	//判断二叉树是否为二叉搜索树
	bool isValidBST(TreeNode* root) {
		vector<int> s;
		midView(root, s);
		if (s.size() < 2)  return true;
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] >= s[i + 1])  return false;
		}
		return true;
	}
	
	//将有序数组转换为二叉搜索树
	TreeNode* buildTree(vector<int>& num, int left, int right) {
		if (left > right) return NULL;
		int mid = (left + right) / 2;
		TreeNode* cur = new TreeNode(num[mid]);
		cur->left = buildTree(num, left, mid - 1);
		cur->right = buildTree(num, mid + 1, right);
		return cur;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return buildTree(nums, 0, nums.size() - 1);
	}
	//镜像翻转二叉树
	TreeNode* invertTree(TreeNode* root) {
		if (root != NULL) {
			TreeNode* tmp = root->left;
			root->left = root->right;
			root->right = tmp;
			invertTree(root->left);
			invertTree(root->right);
		}
		return root;
	}
	//二叉树之字形遍历(第一层从左往右遍历，第二层从右往左遍历，第三次从左往右…)
	vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
		vector<vector<int> > s;
		bool change = false;
		if (root == NULL)  return s;
		queue<TreeNode*> p;
		p.push(root);
		vector<int> t;
		queue<TreeNode*> q = p;
		t.push_back(root->val);
		while (!q.empty()) {
			q = queue<TreeNode*>();
			t.clear();
			while (!p.empty()) {
				TreeNode* tmp = p.front();
				t.push_back(tmp->val);
				p.pop();
				if (tmp->left != NULL)  q.push(tmp->left);
				if (tmp->right != NULL)  q.push(tmp->right);
			}
			p = q;
			if (change) {
				change = false;
				reverse(t.begin(), t.end());
			}
			else  change = true;
			s.push_back(t);
		}
		return s;
	}
	//判断两个二叉树是否互为镜像
	bool isMirror(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)  return true;
		if (p == NULL || q == NULL)  return false;
		if (p->val != q->val)  return false;
		return isMirror(p->left, q->right) && isMirror(p->right, q->left);
	}
	//判断二叉树本身是否为镜像二叉树
	bool isMirrorTree(TreeNode* root) {
		return isMirror(root, root);//利用算法16，如果一个树是镜像的，那么它和自己本身互为镜像
	}

	//求二叉树中两个节点的最近公共祖先
	void help(TreeNode* p, map<TreeNode*, TreeNode*>& q) {
		if (p) {
			if (p->left)  q[p->left] = p;
			if (p->right)  q[p->right] = p;
			help(p->left, q);
			help(p->right, q);
		}
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		map<TreeNode*, TreeNode*> m;
		TreeNode* head = root;
		help(root, m);
		if (m[p] == q)  return q;
		if (m[q] == p)  return p;
		while (p != head) {
			TreeNode* tmp = q;
			while (tmp != head) {
				if (p == tmp || m[tmp] == p)  return p;
				if (m[p] == tmp)  return tmp;
				tmp = m[tmp];
			}
			p = m[p];
		}
		return head;
	}
	//判断二叉树中两个节点是否为堂兄弟(深度相同但父节点不同)
	void help(TreeNode* root, map<int, int>& p) {
		if (root != NULL) {
			if (root->left != NULL)  p[root->left->val] = root->val;
			if (root->right != NULL)  p[root->right->val] = root->val;
			help(root->left, p);
			help(root->right, p);
		}
	}
	map<int, int> p;
	bool isCousins(TreeNode* root, int x, int y) {
		help(root, p);
		if (p[x] == 0 || p[y] == 0)  return false;
		if (p[x] == p[y])  return false;
		int xi = 0, yi = 0;
		while (p[x] != p[y]) {
			if (p[p[x]] != 0) {
				x = p[x];
				xi++;
			}
			if (p[p[y]] != 0) {
				y = p[y];
				yi++;
			}
		}
		return xi == yi;
	}
};

int main()
{
	Solution se;

	system("pause");
	return 0;
}
