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


int Count(node* root)		//Returns Number of Nodes in the Tree
{
	if(root==NULL)
		return 0;

	return Count(root->left) + Count(root->right) + 1;
}


int Sum(node* root)			//Returns Sum of data stored in all nodes of the Tree
{
	if(root==NULL)
		return 0;

	return Sum(root->left) + Sum(root->right) + root->data;
}


int main()
{
	node* root=BuildTree();
	cout<<"No. of Nodes = "<<Count(root)<<endl;
	cout<<"Sum of all Nodes = "<<Sum(root)<<endl;
	return 0;
}