#include <iostream>
#include <queue>
using namespace std;

//BFS = Breadth First Search
//Allows us to implement Level Order Traversal in O(N) complexity.

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
	BFS(root);
	return 0;
}