#include <iostream>
#include <queue>
using namespace std;

#define pii pair<int,int>
#define branch_len first
#define path_len second

//10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1
//Answer is 42

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


pii MaxSumPath(node* root)
{
	if(root==NULL)
		return make_pair(0,0);

	pii left = MaxSumPath(root->left);
	pii right= MaxSumPath(root->right);

	int op1=root->data;
	int op2= left.branch_len + root->data;
	int op3= right.branch_len + root->data;
	int x = max(op1, max(op2,op3));

	int op4=root->data + left.branch_len + right.branch_len;
	int op5=left.path_len;
	int op6=right.path_len;
	int y = max(max(op4,x),max(op5,op6));

	return make_pair(x,y);
}


int FindMaxSumPath(node* root)
{
	return MaxSumPath(root).path_len;
}


int main()
{
	node* root=NULL;
	cin>>root;
	cout<<FindMaxSumPath(root)<<endl;
	return 0;
}