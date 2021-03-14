//WAP to find no. of primes in a given range using cumulative prefix sum array.

#include <iostream>
using namespace std;

void Prime_Sieve(int a[],int n)	//if (a[i]==1) ==> i is prime 
{								//excluding n (1 to n-1)
	int i, j;
	a[2]++;

	for(i=3; i<n; i+=2)
		a[i]++;


	for(i=3; i<n; i+=2)
	{
		if(a[i])
		{
			for(j=i*i; j<n; j+=i)
			{
				if(j%2 && a[j])
					a[j]--;
			}
		}
	}
}

void Prime_Prefix(int a[], int b[],int n)
{
	int i;
	b[2]++;

	for(i=3; i<n; i++)
	{
		b[i]=b[i-1];

		if(a[i])
			b[i]++;
	}
}


int Prime_Visits(int a, int b, int arr[])
{
	return arr[b] - arr[a-1];
}


int main()
{
	const int N=101;
	int i, A[N]={0}, B[N]={0};
	
	Prime_Sieve(A,N);

	for(i=0; i<N; i++)
		if(A[i])
		cout<<i<<" ";

	Prime_Prefix(A,B,N);
	cout<<endl;

	for(i=0; i<N; i++)
		cout<<B[i]<<" ";
	cout<<endl;

	cout<<Prime_Visits(11, 20, B);

	cout<<endl;
	return 0;
}