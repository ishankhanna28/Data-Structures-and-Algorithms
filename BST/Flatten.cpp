#include <iostream>
#include <queue>
using namespace std;

//A BST may be flattened by converting it into a Sorted Linked List.
//Without creating any additional node
//5 3 7 1 6 8 -1

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


istream& operator>>(istream &is, node* &root)
{
	root=Build();
	return is;
}


#define list pair<node*,node*>
#define head first
#define tail second


list MakePair(node* h, node* t)
{
	list l;
	l.head=h;
	l.tail=t;
	return l;
}


list Flatten(node* root)
{
	if(root==NULL)
		return MakePair(NULL,NULL);

	if(root->left==NULL and root->right==NULL)
		return MakePair(root,root);


	if(root->right==NULL)
	{
		list l=Flatten(root->left);
		l.tail->right=root;
		return MakePair(l.head,root);
	}

	if(root->left==NULL)
	{
		list r=Flatten(root->right);
		root->right=r.head;
		return MakePair(root,r.tail);
	}


	list ll=Flatten(root->left);
	list rr=Flatten(root->right);

	ll.tail->right=root;
	root->right=rr.head;
	return MakePair(ll.head,rr.tail);
}


void PrintList(node* temp)
{
	while(temp!=NULL)
	{
		cout<<temp->data<<" -> ";
		temp=temp->right;
	}
}


ostream& operator<<(ostream &os, node* head)
{
	PrintList(head);
	return os;
}


int main()
{
	node* root=NULL;
	cin>>root;
	cout<<Flatten(root).head<<endl;
	return 0;
}


