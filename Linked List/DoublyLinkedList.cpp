#include <iostream>
using namespace std;


class node
{
public:

	int data;
	node* next;
	node* prev;

	node()
	{
		next=NULL;
		prev=NULL;
	}

	node(int d)
	{
		data=d;
		next=NULL;
		prev=NULL;
	}
};


void Print(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" -> ";
		head=head->next;
	}

	cout<<endl;
}


void PrintRev(node* head)
{
	node* tail=head;

	while(tail->next!=NULL)
		tail=tail->next;

	while(tail!=NULL)
	{
		cout<<tail->data<<" -> ";
		tail=tail->prev;
	}

	cout<<endl;
}


int Length(node* head)
{
	int cnt = 0;

	while(head!=NULL)
	{
		cnt++;
		head=head->next;
	}

	return cnt;
}


void InsertAtHead(node* &head, int d)
{
	if(head==NULL)
	{
		head = new node(d);
		return;
	}

	node* temp = new node(d);
	temp->next = head;
	head = temp;
}


void InsertAtTail(node* &head, int d)
{
	if(head==NULL)
	{
		head = new node(d);
		return;
	}

	node* tail = head;
	while(tail->next != NULL)
		tail=tail->next;

	node* temp=new node(d); 
	tail->next=temp;
	temp->prev=tail;
}


void InsertAtMid(node* &head, int d, int pos)
{
	if(!pos || head==NULL)
	{
		InsertAtHead(head, d);
		return;
	}

	if(pos==Length(head))
	{
		InsertAtTail(head, d);
		return;
	}

	node* n=head;

	while(--pos)
		n=n->next;

	node* temp = new node(d);
	temp->prev=n;
	temp->next=n->next;
	n->next->prev=temp;
	n->next=temp;
}

// 7 -> 5 -> 1 -> 9 -> 2 -> 3 -> 


void DeleteHead(node* &head)
{
	if(head==NULL)
		return;

	node* temp = head;
	head=head->next;
	head->prev=NULL;
//	temp->next=NULL;
	delete temp;
}


void DeleteTail(node* &head)
{
	if(head==NULL)
		return;

	if(head->next==NULL)
	{
		node* temp = head;
		head=NULL;
		delete temp;
	}

	node* pre = head;
	node* tail = head->next;
	while(tail->next != NULL)
	{
		pre=pre->next;
		tail=tail->next;
	}

	pre->next=NULL;
	delete tail;
}


void DeleteAtMid(node* &head, int pos)
{
	if(head==NULL || pos>=Length(head))
		return;

	if(!pos)
	{
		DeleteHead(head);
		return;
	}

	if(pos==Length(head)-1)
	{
		DeleteTail(head);
		return;
	}

	node* pre= head;
	node* temp= head->next;

	while(--pos)
	{
		pre=pre->next;
		temp=temp->next;
	}

	pre->next=temp->next;
	temp->next->prev=pre;
	delete temp;
}


int Search(node* head, int key)
{
	int pos=0;

	while(head!=NULL)
	{
		if(head->data==key)
			return pos;

		pos++;
		head=head->next;
	}

	return -1;
}


int SearchRec(node* head, int key, int pos=0)
{
	if(head==NULL)
		return -1;

	if(head->data==key)
		return pos;

	return SearchRec(head->next, key, pos+1);
}


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
			node* n = new node(d);
			temp->next = n;
			n->prev=temp;
			temp=n;
		}
	}

	return head;
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



int main()
{
	node* head = NULL;
	cin>>head;
//  5 1 4 8 7 6

	InsertAtHead(head, 2);
	InsertAtTail(head, 3);
	InsertAtMid(head, 1, 2);
	InsertAtMid(head, 9, 3);
	
	DeleteHead(head);
	DeleteTail(head);
	DeleteAtMid(head, 2);
	
	cout<<Search(head, 4)<<endl;
	cout<<SearchRec(head, 7)<<endl;

	cout<<head;
	PrintRev(head);
	return 0;
}

/*
INPUT:
5 4 8 7 6 

OUTPUT:
2
4
5 -> 1 -> 4 -> 8 -> 7 -> 6 -> 
6 -> 7 -> 8 -> 4 -> 1 -> 5 -> 
*/