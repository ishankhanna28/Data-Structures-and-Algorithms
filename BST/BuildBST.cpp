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


node* Insert(node* root, int d)
{
	if(root==NULL)
		return new node(d);

	if(d<=root->data)
		root->left=Insert(root->left,d);

	else
		root->right=Insert(root->right,d);

	return root;
}


node* Build(int n)
{
	node* root=NULL;
	int d=0;

	while(n--)
	{
		cin>>d;

//		if(d==-1)
//			break;

		root=Insert(root,d);
	}

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


istream& operator>>(istream &is, node* &root)
{
	root=Build();
	return is;
}

ostream& operator<<(ostream &os, node* root)
{
	BFS(root);
	return os;
}


void solve()
{
	node* root=NULL;

	int n;
	cin>>n;
	root=Build(n);

	cout<<root<<endl;
}


int main()
{
	int t=1;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
