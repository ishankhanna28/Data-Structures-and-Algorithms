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


void Print(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" -> ";
		head=head->next;
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
		node* tail = new node(d);
		head=tail;
		return;
	}

	node* tail = head;
	while(tail->next != NULL)
		tail=tail->next;

	tail->next=new node(d);
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
	temp->next=n->next;
	n->next=temp;
}

// 7 -> 5 -> 1 -> 9 -> 2 -> 3 -> 


void DeleteHead(node* &head)
{
	if(head==NULL)
		return;

	node* temp = head;
	head=head->next;
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

	node* prev = head;
	node* tail = head->next;
	while(tail->next != NULL)
	{
		prev=prev->next;
		tail=tail->next;
	}

	prev->next=NULL;
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

	node* prev= head;
	node* temp= head->next;

	for(int i=1; i<pos; i++)
	{
		prev=prev->next;
		temp=temp->next;
	}

	prev->next=temp->next;
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


ostream& operator<<(ostream &os, node* head)
{
	Print(head);
	return os;
}



int main()
{
	/*
	node* head =NULL;
	InsertAtHead(head, 2);
	InsertAtHead(head, 5);
	InsertAtHead(head, 7);
	InsertAtTail(head, 3);
	InsertAtMid(head, 1, 2);
	InsertAtMid(head, 9, 3);
	
	DeleteHead(head);
	DeleteTail(head);
	DeleteAtMid(head, 2);
	InsertAtHead(head, 3);
	InsertAtHead(head, 6);
	InsertAtTail(head, 9);
	InsertAtMid(head, 7, 2);

	Print(head);
	cout<<Search(head, 5)<<endl;
	cout<<SearchRec(head, 1)<<endl;
	*/

	/*
	node* head = Input();
	Print(head);
	*/
	node* h1=NULL;
	node* h2=NULL;
	cin>>h1>>h2;
	cout<<h1<<h2;


	return 0;
}
