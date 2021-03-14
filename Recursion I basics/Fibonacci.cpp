#include <iostream>
using namespace std;

int FIB(int n)	//returns nth term of the fibonacci series
{
	if(n==1)
		return 0;

	else if(n==2)
		return 1;

	else
		return FIB(n-1) + FIB(n-2);
}

int main()
{
	int N = 13;	
	cout<<FIB(N)<<endl;
	return 0;
}