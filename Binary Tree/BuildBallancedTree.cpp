#include <iostream>
#include <queue>
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


node* Build(int a[], int lb, int ub)	//Divide and Conquer - O(logN)
{
	if(lb>ub)
		return NULL;

	int mid = (lb+ub)/2;
	node* root=new node(a[mid], Build(a,lb,mid-1), Build(a,mid+1,ub));
	return root;
}


node* BuildBalancedTree(int a[], int n)
{
	return Build(a, 0, n-1);
}


int main()
{
	int n;
	cin>>n;
	const int k=n;
	int a[k];

	for(n=0; n<k; n++)
		cin>>a[n];

	BFS(BuildBalancedTree(a,k));
	return 0;
}