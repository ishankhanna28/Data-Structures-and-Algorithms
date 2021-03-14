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

	node(int d, node* n=NULL)
	{
		data=d;
		next=n;
	}
};


class STACK
{
	node* top;	//top behaves as head
	public:

	STACK()
	{
		top=NULL;
	}


	bool isEmpty()
	{
		if(top==NULL)
			return true;

		else
			return false;
	}


	void PUSH(int d)	//Insertion will be at head
	{
		node* temp = new node(d, top);
		top=temp;
	}


	void POP()
	{
		if(isEmpty())
			return;

		node* temp=top;
		top=top->next;
		delete temp;
	}


	void DISPLAY()
	{
		node* temp=top;

		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}

		cout<<endl;
	}


	node* Get_Top()
	{
		return top;
	}


	~STACK()
	{
		node* temp;

		while(top!=NULL)
		{
			temp=top;
			top=top->next;
			delete temp;
		}
	}

};



int main()
{
	int s, x;
	char ch;
	STACK S;
	
	do{
	
	for(x=1; x<=3; x++)
		cout<<endl;

	cout<<"\t\tSTACK"<<endl;
	cout<<"1) Check if Empty "<<endl;
	cout<<"2) Push"<<endl;
	cout<<"3) Pop"<<endl;
	cout<<"4) Display"<<endl;
	cout<<"5) Exit"<<endl;
	cout<<"\t Make you choice(1/2/3/4/5/6/7)..."<<endl;
	
	cin>>s;
	switch(s)
	{
		case 1:
			if(S.isEmpty())
				cout<<"Stack is EMPTY"<<endl;
			else
				cout<<"Stack is NOT EMPTY"<<endl;
			break;

		case 2:
			cout<<"Input Data..."<<endl;
			cin>>x;
			S.PUSH(x);
			break;

		case 3:
			cout<<S.Get_Top()->data<<" has been popped"<<endl;
			S.POP();
			break;

		case 4:
			S.DISPLAY();
			break;

		case 5:
			cout<<"Quitting..."<<endl;
			break;

		default:
			cout<<"Invalid Input."<<endl;
			break;
	}

	
	if(s==5)
	{
		cout<<"Are you sure you want to Quit(Y/N)..."<<endl;
		cin>>ch;

		if(ch=='N' || ch=='n')
			s++;
	}

	}while(s!=5);
	return 0;
}
