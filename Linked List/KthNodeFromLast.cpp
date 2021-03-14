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
	cin>>d;

	while(d!=-1)
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

		cin>>d;
	}

	return head;
}


istream& operator>>(istream &is, node* &head)	//Operator Overloading
{
	head=Input();
	return is;
}


node* KfromLAST(node* head, int k)
{
	node* slow=head; 
	node* fast=head;

	while(--k)
		fast=fast->next;

	while(fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
	}

	return slow;
}



int main()
{
	int k;
	node* head= NULL;
	cin>>head;
	cin>>k;
	cout<<(KfromLAST(head, k))->data<<endl;
	return 0;
}