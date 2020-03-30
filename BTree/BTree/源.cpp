#include <iostream>
#include<stdio.h>
#include<string>

using namespace std;

struct node
{
	node * lchild;
	node * rchild;
	string data;
	//初始化  
	node()
	{
		lchild = rchild = NULL;
	}
};
void CreateTree(node * & root)
{
	char data;
	cin >> data;
	if (data != '#')
	{
		root = new node;
		root->data = data;

		CreateTree(root->lchild);

		CreateTree(root->rchild);

	}
}
void CreateTree(node * & root)  
{  
     char data;  
     cin>>data;  
     if(data!='#')  
     {  
         root=new node;  
         root->data=data;  
           
         CreateTree(root->lchild);  
          
         CreateTree(root->rchild);  
          
     }  
}
void  PreOrder(node * root)//先序遍历  
{
	if (root != NULL)
	{
		cout << root->data;
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}
void main()
{
	node *tree1;
	CreateTree(tree1);
	PreOrder(tree1);

}