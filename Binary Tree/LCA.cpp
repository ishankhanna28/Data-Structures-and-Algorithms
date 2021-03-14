#include <iostream>
#include <queue>
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


//LCA function returns pointer to Lowest Common Ancestor of a & b
//Assuming all keys are unique and that a & b are present in the Tree


node* LCA(node* root, int a, int b)
{
	if(root==NULL or root->data==a or root->data==b)
		return root;


	node* left=LCA(root->left,a,b);
	node* right=LCA(root->right,a,b);

	if(left!=NULL and right!=NULL)
		return root;

	if(left!=NULL)
		return left;

	return right;
}


int main()
{
	node* root=NULL;
	cin>>root;
	cout<<LCA(root,4,7)->data<<endl;
	cout<<LCA(root,6,9)->data<<endl;
	return 0;
}
