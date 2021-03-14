#include <iostream>
using namespace std;
const int Max = 5;


void Qinsert(int a[], int &f, int &r, int d)
{
	if( (r+1)%Max == f)
	{
		cout<<"Queue is Full"<<endl;
		return;
	}

	if(r==-1)
		f=0;

	r=(r+1)%Max;
	a[r]=d;
}


void Qdelete(int a[], int &f, int &r)
{
	if(f==-1)
	{
		cout<<"Queue is Empty"<<endl;
		return;
	}

	if(f==r)
	{
		f=-1;
		r=-1;
		return;
	}

	f=(f+1)%Max;
}


void Qdisplay(int a[], int f, int r)
{
	for(; f!=r; f=(f+1)%Max)
		cout<<a[f]<<" ";
	cout<<a[f]<<endl;
}


int main()
{
	int Q[Max], F=-1, R=-1, num, s;
	char ch;
	
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
			Qinsert(Q, F, R, num);
			break;

		case 2:
			Qdelete(Q, F, R);
			break;

		case 3:
			Qdisplay(Q, F, R);
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
