#include <iostream>
#include <climits>
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


istream& operator>>(istream &is, node* &root)
{
	root=BuildTree();
	return is;
}


bool isBST(node* root, int minV=INT_MIN, int maxV=INT_MAX)
{
	if(root==NULL)
		return true;

	if(root->data>=minV and root->data<=maxV and isBST(root->left,minV,root->data) and
	 isBST(root->right,root->data,maxV))
		return true;

	return false;
}


int main()
{
	node* root=NULL;
	cin>>root;

	if(isBST(root))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	return 0;
}