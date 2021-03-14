#include <iostream>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;

	node(int data=0, node* left=NULL, node* right=NULL)
	{
		this->data=data;
		this->left=left;
		this->right=right;
	}
};


node* BuildTree()
{
	int d;
	cin>>d;

	if(d==-1)
		return NULL;

	node* root=new node(d, BuildTree(), BuildTree());
	return root;
}


void PrintPreOrder(node* root)
{
	if(root==NULL)
		return;

	cout<<root->data<<" ";
	PrintPreOrder(root->left);
	PrintPreOrder(root->right);
}


void PrintInOrder(node* root)
{
	if(root==NULL)
		return;

	PrintInOrder(root->left);
	cout<<root->data<<" ";
	PrintInOrder(root->right);
}


void PrintPostOrder(node* root)
{
	if(root==NULL)
		return;

	PrintPostOrder(root->left);
	PrintPostOrder(root->right);
	cout<<root->data<<" ";
}



int main()
{
	node* root=BuildTree();
	PrintPreOrder(root);
	cout<<endl;
	PrintInOrder(root);
	cout<<endl;
	PrintPostOrder(root);
	cout<<endl;
	return 0;
}


/*
INPUT (Pre-Order)
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

OUTPUT:
PRE-ORDER (TOP DOWN) Root/Left/Right
8 10 1 6 9 7 3 14 13

IN-ORDER Left/Root/Right
1 10 9 6 7 8 3 13 14

POST-ORDER (BOTTOM UP) Left/Right/Root
1 9 7 6 10 13 14 3 8
*/