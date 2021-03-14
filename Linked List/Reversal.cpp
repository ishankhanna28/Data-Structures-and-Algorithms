#include <iostream>
using namespace std;


class node
{
public:

	int data;
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

	while(cin>>d)
	{
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
	}

	return head;
}

void Print(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" -> ";
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


void RevList(node* &head)	//3 pointer method
{
	node *prev= NULL;
	node *cur = head;
	node *nxt = head->next;

	while(cur!=NULL)
	{
		cur->next=prev;

		prev=cur;
		cur=nxt;

		if(nxt!=NULL)
			nxt=nxt->next;
	}

	head=prev;
}


node* REC_reverse(node* head)	//Using Recursion
{
	if(head->next==NULL or head==NULL)
		return head;

	node* h = REC_reverse(head->next);
	
	head->next->next=head;
	head->next=NULL;

	return h;
}


void RECreverse(node* &head)	//Helper Function
{
	head = REC_reverse(head);
}


int main()
{
	node* head= NULL;
	cin>>head;
	RECreverse(head);
	cout<<head<<endl;
	return 0;
}