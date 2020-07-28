#include<stdio.h>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<iostream>

using namespace std;

//�ṹ�嶨��
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//���������룬���ն�����
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
	//���������룬��data��ֵ
	void InsertIntoBitTree(TreeNode** root, int data)
	{
		TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
		newNode->val = data;
		newNode->left = NULL;
		newNode->right = NULL;
		if (*root == NULL)//˵���ǿ���
		{
			*root = newNode;//���½���ָ��newNode��ֵ��������ָ��
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
	//���������������
	int maxDepth(TreeNode* root) {
		if (root == NULL)  return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return max(left, right) + 1;
	}

	//�����������С���
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

	//��������ǰ�����
	void preView(TreeNode* root) {
		if (root != NULL) {
			cout << root->val << " ";
			preView(root->left);
			preView(root->right);
		}
	}

	//���������������
	void midView(TreeNode* root) {
		if (root != NULL) {
			midView(root->left);
			cout << root->val << " ";
			midView(root->right);
		}
	}

	//�������ĺ������
	void postView(TreeNode* root) {
		if (root != NULL) {
			postView(root->left);
			postView(root->right);
			cout << root->val << " ";
		}
	}

	//�������Ĳ������
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
	//��������Ľڵ����
	int nodeNumbers(TreeNode* root) {
		if (root == NULL)  return 0;
		int left = nodeNumbers(root->left);
		int right = nodeNumbers(root->right);
		return left + right + 1;
	}

	//���������Ҷ�ڵ����
	int leafNodeNumbers(TreeNode* root) {
		if (root == NULL)  return 0;
		if (root->left == NULL && root->right == NULL)  return 1;
		return leafNodeNumbers(root->left) + leafNodeNumbers(root->right);
	}

	//�ж϶������Ƿ�Ϊƽ�������
	int countFloor(TreeNode* root) {//�������
		if (!root)  return 0;
		return 1 + max(countFloor(root->left), countFloor(root->right));
	}
	bool isBalanced(TreeNode* root) {
		if (!root)  return true;
		if (abs(countFloor(root->left) - countFloor(root->right)) > 1)  return false;
		else  return isBalanced(root->left) && isBalanced(root->right);
	}

	//�ж϶������Ƿ�Ϊ��������
	bool isFullTree(TreeNode* root) {
		if (root == NULL)  return true;
		int n = nodeNumbers(root) + 1;//���������ڵ���Ϊ2^n-1�������㷨7��ڵ���
		while (n > 1) {
			if (n % 2 == 1)  return false;
			n /= 2;
		}
		return true;
	}
	//�ж��������Ƿ���ȫ��ͬ
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		if (q != NULL && p != NULL) {
			if (q->val != p->val) return false;
			else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		else
			return false;
	}

	//�ж϶������Ƿ�Ϊ����������
	bool isValidBST(TreeNode* root) {
		vector<int> s;
		midView(root, s);
		if (s.size() < 2)  return true;
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] >= s[i + 1])  return false;
		}
		return true;
	}
	
	//����������ת��Ϊ����������
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
	//����ת������
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
	//������֮���α���(��һ��������ұ������ڶ��������������������δ������ҡ�)
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
	//�ж������������Ƿ�Ϊ����
	bool isMirror(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)  return true;
		if (p == NULL || q == NULL)  return false;
		if (p->val != q->val)  return false;
		return isMirror(p->left, q->right) && isMirror(p->right, q->left);
	}
	//�ж϶����������Ƿ�Ϊ���������
	bool isMirrorTree(TreeNode* root) {
		return isMirror(root, root);//�����㷨16�����һ�����Ǿ���ģ���ô�����Լ�����Ϊ����
	}

	//��������������ڵ�������������
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
	//�ж϶������������ڵ��Ƿ�Ϊ���ֵ�(�����ͬ�����ڵ㲻ͬ)
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
