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


node* Build()
{
	node* root=NULL;
	int d=0;

	while(1)
	{
		cin>>d;

		if(d==-1)
			break;

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


//BST seach is more efficient than in BT. BT search is O(N), BST is O(D), where D=depth
//Best Case = O(logN) for a ballanced tree
//Worst Case = O(N) for skew tree

node* Search(node* root, int key)
{
	if(root==NULL or root->data==key)
		return root;

	if(key<root->data)
		return Search(root->left,key);

	return Search(root->right,key);
}


int main()
{
	node* root=NULL;
	cin>>root;
//	cout<<root<<endl;
	node* key=Search(root,7);

	if(key==NULL)
		cout<<"Element is not present"<<endl;

	else
		cout<<"Element containing "<<key->data<<" is present at "<<key<<endl;

	return 0;
}
