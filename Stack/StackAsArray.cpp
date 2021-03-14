#include <iostream>
using namespace std;


class STACK
{
	int T, *A, max;
	public:

	STACK(int max)
	{
		this->max=max;
		T=-1;
		A = new int[max]; 
	}


	bool isEmpty()
	{
		if(T==-1)
			return true;

		else
			return false;
	}


	bool isFull()
	{
		if(T==max-1)
			return true;

		else
			return false;
	}


	void PUSH(int d)
	{
		if(!isFull())
			A[++T]=d;
	}


	void POP()
	{
		if(!isEmpty())
			T--;
	}


	void DISPLAY()
	{
		for(int i=T; i>=0; i--)
			cout<<A[i]<<" ";
		cout<<endl;
	}


	int Get_Top()
	{
		return A[T];
	}


	~STACK()
	{
		delete[] A;
	}

};



int main()
{
	int s, x, y;
	char ch;
	cout<<"Input Max..."<<endl;
	cin>>x;
	STACK S(x);
	
	do{
	
	for(x=1; x<=3; x++)
		cout<<endl;

	cout<<"\t\tSTACK"<<endl;
	cout<<"1) Check if Empty "<<endl;
	cout<<"2) Check if Full "<<endl;
	cout<<"3) Push"<<endl;
	cout<<"4) Pop"<<endl;
	cout<<"5) Display"<<endl;
	cout<<"6) Exit"<<endl;
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
			if(S.isFull())
				cout<<"Stack is FULL"<<endl;
			else
				cout<<"Stack is NOT FULL"<<endl;
			break;

		case 3:
			cout<<"Input Data..."<<endl;
			cin>>y;
			S.PUSH(y);
			break;

		case 4:
			cout<<S.Get_Top()<<" has been popped"<<endl;
			S.POP();
			break;

		case 5:
			S.DISPLAY();
			break;

		case 6:
			cout<<"Quitting..."<<endl;
			break;

		default:
			cout<<"Invalid Input."<<endl;
			break;
	}

	
	if(s==6)
	{
		cout<<"Are you sure you want to Quit(Y/N)..."<<endl;
		cin>>ch;

		if(ch=='N' || ch=='n')
			s++;
	}

	}while(s!=6);
	return 0;
}
