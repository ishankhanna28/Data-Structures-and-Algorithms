#include <iostream>
using namespace std;

int bin2dec(int n)
{
	int sum=0, t=1;

	while(n)
	{
		sum+= (n%10)*t;
		n/=10;
		t*=2;
	}

	return sum;
}

int dec2bin(int n)
{
	int sum=0, t=1;

	while(n)
	{
		sum+= (n&1)*t;
		n = n>>1;
		t*=10;
	}

	return sum;
}

int main()
{
	cout<<bin2dec(1011)<<endl;
	cout<<dec2bin(15)<<endl;
	return 0;
}