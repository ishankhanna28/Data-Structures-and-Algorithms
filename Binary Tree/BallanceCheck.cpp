#include <iostream>
using namespace std;

//WAP 2 Check whether Tree is Ballanced or Not.
//Ballanced Tree: 1 2 3 -1 -1 4 -1 -1 5 -1 -1

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


int Ballance(node* root, bool &check)
{
	if(root==NULL || !check)
		return 0;

	int h1 = Ballance(root->left,check);
	int h2 = Ballance(root->right,check);

	if( (h1-h2)>1 || (h2-h1)>1 )
		check=false;

	return max(h1,h2) + 1;
}


bool isBallanced(node* root)
{
	bool Check=true;
	Ballance(root,Check);
	return Check;
}


int main()
{
	node* root=BuildTree();

	if(isBallanced(root))
		cout<<"Yes, Tree is Ballanced"<<endl;

	else
		cout<<"No, Tree is NOT Ballanced"<<endl;

	return 0;
}