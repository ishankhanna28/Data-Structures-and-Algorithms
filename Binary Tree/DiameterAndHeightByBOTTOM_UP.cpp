#include <iostream>
using namespace std;

#define pii pair<int,int>
#define height first
#define diameter second


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


pii HeightDiameter(node* root)
{
	pii p;

	if(root==NULL)
	{
		p.height=0;
		p.diameter=0;
		return p;
	}

	pii left = HeightDiameter(root->left);
	pii right = HeightDiameter(root->right);

	p.height = max(left.height, right.height) + 1;
	p.diameter = max( left.height+right.height, max(left.diameter,right.diameter) );
	return p;
}


int main()
{
	node* root=BuildTree();
	pii p = HeightDiameter(root);
	cout<<"Height = "<<p.height<<endl;
	cout<<"Diameter = "<<p.diameter<<endl;

}