#include <iostream>
using namespace std;
int count;


class node
{
public:

	signed int data;
	node* next;

	node()
	{
		next=NULL;
	}

	node(int d)
	{
		data=d;
		next=NULL;
	}
};


node* Input()
{
	node* head = NULL;
	node* temp = NULL;
	int d, cnt=0;

	while(count!=0)
	{
		cin>>d;

		if(!cnt)
		{
			temp = new node(d);
			head=temp;
			cnt++;
		}

		else 
		{
			temp->next = new node(d);
			temp=temp->next;
		}

		count--;
	}

	return head;
}


void Print(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}

	cout<<endl;
}


istream& operator>>(istream &is, node* &head)	//Operator Overloading
{
	head=Input();
	return is;
}


ostream& operator<<(ostream &os, node* head)
{
	Print(head);
	return os;
}


node* MPT(node* head)	//Midpoint Runner Technique
{
	node* slow = head;
	node* fast = head->next;

	while(fast!=NULL and fast->next!=NULL)
	{
		slow= slow->next;
		fast= fast->next->next;
	}

	return slow;
}


node* MERGE(node* a, node* b)
{
	if(a==NULL)
		return b;

	if(b==NULL)
		return a;


	node* c=NULL;

	if(a->data < b->data)
	{
		c=a;
		c->next = MERGE(a->next, b);
	}

	else if(b->data < a->data)
	{
		c=b;
		c->next = MERGE(a, b->next);
	}

	else
	{
		c=a;
		c->next=b;
		c->next->next = MERGE(a->next, b->next);
	}

	return c;
}


node* MergeSort(node* head)
{
	if(head->next==NULL or head==NULL)
		return head;


	node* mid = MPT(head);
	node* temp= mid->next;
	mid->next=NULL;

	return MERGE( MergeSort(head), MergeSort(temp) );
}


void SORT(node* &head)
{
	head=MergeSort(head);
}


int main()
{
	node* head = NULL;
	cin>>count>>head;
	SORT(head);
	cout<<head<<endl;
	return 0;
}
