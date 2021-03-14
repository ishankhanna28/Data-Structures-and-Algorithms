#include <iostream>
#include <algorithm>
using namespace std;


int Connect(int a[], int b[], int n)
{
	sort(a,a+n);
	sort(b,b+n);
	int sum = 0;

	while(n--)
	{
		if(a[n]>b[n])
			sum+= a[n]-b[n];

		else
			sum+= b[n]-a[n];
	}

	return sum;
}


int main()
{
	int a[] = {3, 4, 1};
	int b[] = {2, 5, 6};
	int n 	= sizeof(a)/sizeof(int);

	cout<<Connect(a,b,n)<<endl;
	return 0;
}