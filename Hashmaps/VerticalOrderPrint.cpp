#include <iostream>
#include <map>
#include <vector>
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


node* Build()
{
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);
	root->left->right->right=new node(8);
	root->right->right->right=new node(9);
	return root;
}


void VOP(map< int, vector<int> > &m, node* root, int d=0)
{
	if(root==NULL)
		return;

	m[d].push_back(root->data);
	VOP(m, root->left, d-1);
	VOP(m, root->right, d+1);
}


int main()
{
	map< int, vector<int> > m;
	node* root=Build();
	VOP(m, root);

	for(auto p:m)
	{
		for(auto x:p.second)
			cout<<x<<" ";

		cout<<endl;
	}

	return 0;
}