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


int Height(node* root)	//O(N)
{
	if(root==NULL)
		return 0;

	return max(Height(root->left), Height(root->right)) + 1;
}


int Diameter(node* root)		//O(N^2)
{
	if(root==NULL)
		return 0;

	return max( Height(root->left)+Height(root->right), max(Diameter(root->left), Diameter(root->right)) );
}


int main()
{
	node* root=BuildTree();
	cout<<Diameter(root)<<endl;
	return 0;
}
