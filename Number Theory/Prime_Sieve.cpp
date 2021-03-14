//WAP to print all prime nos from 1-100 (one to n)

#include <iostream>
using namespace std;

int main()
{
	const int n=101;
	int a[n]={0}, i, j;
	cout<<"2 ";

	for(i=3; i<n; i+=2)	//if a[i]=0 ==> i is a prime no.
	{
		if(!a[i])
		{
			cout<<i<<" ";

			for(j=i*i; j<n; j+=i)
				a[j]++;
		}

	}

	cout<<endl;
	return 0;
}

/*
Time complexity:
=N/2 + N/3 + N/5 + N/7 ..........
= N(1/2 + 1/3 + 1/7 +.........)
= N*log(log(N))
if N= 10^18
tc= 7N
==> aproximately linear
*/