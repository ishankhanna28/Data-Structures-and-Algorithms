#include <iostream>
#include <vector>
using namespace std;


class STACK
{
	vector<int> v;
	public:

	bool isEmpty()
	{
		if(v.empty())
			return true;

		else
			return false;
	}


	void PUSH(int d)
	{
		v.push_back(d);
	}


	void POP()
	{
		v.pop_back();
	}


	void DISPLAY()
	{
		for(auto it=(v.end()-1); it!=(v.begin()-1); it--)
			cout<<*it<<" ";
		cout<<endl;
	}


	int Get_Top()
	{
		return v[v.size()-1];
	}

};



int main()
{
	int s, x, y;
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
			cin>>y;
			S.PUSH(y);
			break;

		case 3:
			cout<<S.Get_Top()<<" has been popped"<<endl;
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
