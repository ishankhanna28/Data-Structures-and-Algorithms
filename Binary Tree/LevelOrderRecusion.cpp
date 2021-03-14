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


void PrintKthLevel(node* root, int k)	//O(K)=O(N)
{
	if(root==NULL)
		return;

	if(k==1)
		cout<<root->data<<" ";

	PrintKthLevel(root->left, k-1);
	PrintKthLevel(root->right, k-1);
}


void LevelOrderPrint(node* root)	//O(N^2)
{
	int h=Height(root);

	for(int i=1; i<=h; i++)
	{
		PrintKthLevel(root, i);
		cout<<endl;
	}
}


int main()
{
	node* root=BuildTree();
	LevelOrderPrint(root);
	return 0;
}