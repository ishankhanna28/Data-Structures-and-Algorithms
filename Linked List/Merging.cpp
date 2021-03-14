#include <iostream>
using namespace std;
#define int long long
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


void solve()
{
	int A, B;
	node* a = NULL;
	node* b = NULL;
	cin>>count>>a>>count>>b;
	node* c = MERGE(a, b);
	cout<<c<<endl;
}


int32_t main()
{
	int t=1;
	cin>>t;
	while(t--)
		solve();
	return 0;
}

