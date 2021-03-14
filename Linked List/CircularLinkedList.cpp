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



void Convert2Circ(node* head)
{
	node* tail=head;

	while(tail->next!=NULL)
		tail=tail->next;

	tail->next=head;
}


void Print(node* head)
{
	node* temp = head;

	while(temp->next!=head)
	{
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}

	cout<<temp->data<<endl;
}


int Length(node* head)
{
	int cnt = 0;
	node* temp=head;

	while(temp->next!=head)
	{
		cnt++;
		temp=temp->next;
	}

	return cnt+1;
}


void INSERT(node* &head, int d)
{
	node* tail=head;

	while(tail->next!=head)
		tail=tail->next;

//	tail->next=NULL;
	tail->next=new node(d);
	tail->next->next=head;
	head=tail->next;
}


void InsertAtHead(node* &head, int d)
{
	INSERT(head, d);
}


void InsertAtTail(node* head, int d)
{
	INSERT(head, d);
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

	node* tail = head;

	while(tail->next!=head)
		tail=tail->next;

	tail->next=head->next;

	node* temp = head;
	head=head->next;
	delete temp;
}


void DeleteTail(node* head)
{
	node* tail=head;

	while(tail->next->next!=head)
		tail=tail->next;

	node* temp=tail->next;
	tail->next=head;
	delete temp;
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
	node* temp=head;

	while(temp->next!=head)
	{
		if(temp->data==key)
			return pos;

		pos++;
		temp=temp->next;
	}

	return -1;
}


int SearchRec(node* head, int key, int pos=0, node* temp=NULL)
{
	if(!pos)
		temp=head;

	if(temp==NULL)
		return -1;

	if(temp==head and pos>0)
		return -1;

	if(temp->data==key)
		return pos;

	return SearchRec(head, key, pos+1, temp->next);
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

	Convert2Circ(head);
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

	cout<<head<<endl;
	return 0;
}

/*
INPUT:
5 4 8 7 6 

OUTPUT:
2
4
5 -> 1 -> 4 -> 8 -> 7 -> 6
*/