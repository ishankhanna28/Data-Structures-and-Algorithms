#include <iostream>
using namespace std;

//Bottom up approach is iterative in nature
//Can be further optimized using Matrix Exponentiation to get O(logN) time complexity

int fib(int n)		//O(n) time & O(1) space
{
	if(n==0 or n==1)
		return n;

	int a=0, b=1, c;

	for(int i=2; i<=n; i++)
	{
		c=a+b;
		a=b;
		b=c;
	}

	return c;
}


int main()
{
	int n;
//	cin>>n;
	n=12;

	cout<<fib(n)<<endl;
	return 0;
}