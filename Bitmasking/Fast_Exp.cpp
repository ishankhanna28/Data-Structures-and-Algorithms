//WAP to calculate a to the power n in logn time using bitwise operators.

#include <iostream>
using namespace std;

int main()
{
	int a, n, p=1;
	a=3, n=5;
//	cin>>a>>n;

	while(n)
	{
		if(n&1)
			p*=a;

		n=n>>1;
		a*=a;
	}

	cout<<p<<endl;
	return 0;
}