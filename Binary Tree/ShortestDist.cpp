#include <iostream>
#include <queue>
using namespace std;

//WAP to find the shortest distance between 2 nodes.

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


int Search(node* root, int key, int level=0)
{
	if(root==NULL)
		return -1;

	if(root->data==key)
		return level;

	int left=Search(root->left, key, level+1);

	if(left!=-1)
		return left;

	return Search(root->right, key, level+1);;
}


int ShortDist(node* root, int a, int b)
{
	node* lca=LCA(root,a,b);
	return Search(lca,a) + Search(lca,b);
	
}


int main()
{
	node* root=NULL;
	cin>>root;
	cout<<ShortDist(root,7,9)<<endl;
	cout<<ShortDist(root,11,8)<<endl;
	return 0;
}