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


istream& operator>>(istream &is, node* &head)	//Operator Overloading
{
	head=Input();
	return is;
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



int main()
{
	node* head= NULL;
	cin>>head;
	cout<<(MPT(head))->data<<endl;
	return 0;
}