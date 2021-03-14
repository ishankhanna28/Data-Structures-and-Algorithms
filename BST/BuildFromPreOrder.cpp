#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//WAP 2 Find BST using inorder Traversal

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


node* Build(int ino[], int pre[], int lb, int ub)
{
	static int i=0;
	if(lb>ub)
		return NULL;

	int mid=lb;
	for(; mid<=ub; mid++)
		if(ino[mid]==pre[i])
			break;

	node* root=new node(pre[i++], Build(ino,pre,lb,mid-1), Build(ino,pre,mid+1,ub));
	return root;
}


node* BuildBST(int pre[], int n)
{	
	const int k=n;
	int ino[k];

	for(int i=0; i<n; i++)
		ino[i]=pre[i];

	sort(ino, ino+n);
	return Build(ino, pre, 0, n-1);
}


int main()
{
	int a[]={5,3,1,7,6,8};
	int n=sizeof(a)/sizeof(int);
	BFS(BuildBST(a,n));
	return 0;
}