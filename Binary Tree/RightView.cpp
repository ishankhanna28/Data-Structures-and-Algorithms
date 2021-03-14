#include <iostream>
#include <queue>
using namespace std;

//DFS

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


istream& operator>>(istream &is, node* &root)
{
	root=BuildTree();
	return is;
}


void RightView(node* root, int level=0)
{
	static int max_level=-1;

	if(root==NULL)
		return;

	if(level>max_level)
	{
		cout<<root->data<<" ";
		max_level=level;
	}

	RightView(root->right, level+1);
	RightView(root->left, level+1);
}


int main()
{
	node* root=NULL;
	cin>>root;
	RightView(root);
	cout<<endl;
	return 0;
}