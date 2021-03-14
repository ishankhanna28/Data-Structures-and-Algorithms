#include <iostream>
using namespace std;

class node
{
	public:
	int data;
	node* next;

	node(int data=0, node* next=NULL)
	{
		this->data=data;
		this->next=next;
	}
};


class QUEUE
{
	node* front;
	node*rear;
	public:

	QUEUE()
	{
		front=NULL;
		rear=NULL;
	}


	void Qinsert(int d)
	{
		if(rear==NULL)
		{
			rear=new node(d);
			front=rear;
			return;
		}

		rear->next=new node(d);
		rear=rear->next;
	}


	void Qdelete()
	{
		if(front==NULL)
		{
			cout<<"Queue is Empty."<<endl;
			return;
		}

		node* temp=front;
		front=front->next;
		delete temp;

		if(front==NULL)
			rear=NULL;
	}


	void Qdisplay()
	{
		node* temp = front;

		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}

		cout<<endl;
	}


	~QUEUE()
	{
		while(front!=NULL)
		{
			node* temp = front;
			front=front->next;
			delete temp;
		}
	}
};


int main()
{
	int num, s;
	char ch;
	QUEUE Q;
	
	do{
	cout<<endl<<endl<<endl;
	cout<<"\t\tSTATIC QUEUE"<<endl;
	cout<<"1) Insert"<<endl;
	cout<<"2) Delete"<<endl;
	cout<<"3) Display"<<endl;
	cout<<"4) Exit"<<endl;
	cout<<"\t Make you choice(1/2/3/4)..."<<endl;
	
	cin>>s;
	switch(s)
	{
		case 1:
			cout<<"Input an integer..."<<endl;
			cin>>num;
			Q.Qinsert(num);
			break;

		case 2:
			Q.Qdelete();
			break;

		case 3:
			Q.Qdisplay();
			break;

		case 4:
			cout<<"Quitting..."<<endl;
			break;

		default:
			cout<<"Invalid Input."<<endl;
			break;
	}

	
	if(s==4)
	{
		cout<<"Are you sure you want to Quit(Y/N)..."<<endl;
		cin>>ch;

		if(ch=='N' || ch=='n')
			s++;
	}

	}while(s!=4);
	return 0;
}
