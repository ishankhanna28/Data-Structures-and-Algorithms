#include <iostream>
#include <queue>
using namespace std;

//WAP 2 Print all Nodes at K distance from a given Target node.
//1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1

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


void PrintKthLevel(node* root, int k)
{
	if(root==NULL)
		return;

	if(k==0)	//Root is at 0th Level
		cout<<root->data<<" ";

	PrintKthLevel(root->left, k-1);
	PrintKthLevel(root->right, k-1);
}


int PrintKdist(node* root, node* target, int k)
{
	if(root==NULL)
		return -1;

	if(root==target)
	{
		PrintKthLevel(root,k);
		return 0;
	}


	int dl = PrintKdist(root->left,target,k);
	if(dl!=-1)
	{
		if(dl+1==k)
			cout<<root->data<<" ";

		else
			PrintKthLevel(root->right, k-2-dl);

		return dl + 1;
	}


	int dr=PrintKdist(root->right,target,k);
	if(dr!=-1)
	{
		if(dr+1==k)
			cout<<root->data<<" ";

		else
			PrintKthLevel(root->left, k-2-dr);

		return dr + 1;
	}

	return -1;
}


int main()
{
	node* root=NULL;
	cin>>root;

	int k=3;
	node* target=root->left->left;
	
	if(PrintKdist(root, target, k)==-1)
		cout<<"Target is not present in given tree.";

	cout<<endl;
	return 0;
}