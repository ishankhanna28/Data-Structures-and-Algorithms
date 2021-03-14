#include <iostream>
using namespace std;


int fib(int n)		// O(2^n) time and O(n) space
{
	if(n==0 or n==1)
		return n;

	return fib(n-1) + fib(n-2);
}

int main()
{
	int n;
//	cin>>n;
	n=6;

	cout<<fib(n)<<endl;
	return 0;
}