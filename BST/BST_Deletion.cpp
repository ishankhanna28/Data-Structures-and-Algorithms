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


node* Delete(node* root, int key)
{
	if(root==NULL)
	{
		return NULL;
	}

	if(root->data==key)
	{

		node* ls=root->left;
		node* rs=root->right;

		if(ls==NULL and rs==NULL)
		{
			delete root;
			return NULL;
		}


		if(ls!=NULL and rs!=NULL)
		{
			while(rs->left!=NULL)
				rs=rs->left;

			root->data=rs->data;
			root->right=Delete(root->right,root->data);
			return root;
		}

		delete root;

		if(ls!=NULL)
			return ls;

		return rs;
	}


	if(key<root->data)
		root->left=Delete(root->left,key);

	else
		root->right=Delete(root->right,key);

	return root;
}


int main()
{
	node* root=NULL;
	cin>>root;
	Delete(root,7);
	cout<<root<<endl;
	return 0;
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
