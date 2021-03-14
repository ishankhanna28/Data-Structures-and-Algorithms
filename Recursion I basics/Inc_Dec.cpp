#include <iostream>
using namespace std;

//WAP to print all natural nos from 1 to N in ascending and descending order.

void DESC(int n)
{
	if(!n)
		return;

	else
	{
		cout<<n<<" ";	//Function call is after the cout statement
		DESC(n-1);		//Bottom to Top approach
	}
}

void ASC(int n)
{
	if(!n)
		return;

	else
	{
		ASC(n-1);		//Function call is before the cout statement
		cout<<n<<" ";	//Top to Bottom approach
	}
}



int main()
{
	int N = 5;
	DESC(N);
	cout<<endl;

	ASC(N);
	cout<<endl;
	return 0;
}