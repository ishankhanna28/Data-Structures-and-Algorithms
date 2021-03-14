#include <iostream>
#include <iostream>
#include <queue>
using namespace std;

//WAP 2 Replace each Node in a tree by the Sum of its descendants.

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


int SumReplace(node* root)
{
	if(root==NULL)
		return 0;

	if(root->left==NULL and root->right==NULL)
		return root->data;

	int temp=root->data;
	root->data= SumReplace(root->left) + SumReplace(root->right);
	return root->data + temp;
}


void BFS(node* root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);	//Level Marker

	while(1)
	{
		node* f=q.front();

		if(f==NULL)
		{
			cout<<endl;
			q.pop();

			if(q.empty())
				break;

			q.push(NULL);
			continue;
		}

		if(f->left!=NULL)
			q.push(f->left);

		if(f->right!=NULL)
			q.push(f->right);

		cout<<f->data<<" ";
		q.pop();
	}
}


int main()
{
	node* root=BuildTree();
	int SumOfAllNodes=SumReplace(root);
	BFS(root);
	return 0;
}