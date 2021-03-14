//WAP to sort an array such that the graph of the array is a collection of peaks and valleys.
//O(N/2)

#include <iostream>
using namespace std;


void WaveSort_Cos(int a[], int n)	//First element is peak
{
	int i=0;

	for(; i<n; i+=2)
	{
		if(i!=0 && a[i] < a[i-1])
			swap(a[i], a[i-1]);

		if(i!=n-1 && a[i] < a[i+1])
			swap(a[i], a[i+1]);
	}

	i-=2;

	if(i==n-1 && a[n-1]<a[0])
		swap(a[n-1], a[0]);

	if(i==n-2 && a[n-1]>a[0])
		swap(a[n-1], a[0]);
}


void WaveSort_Sin(int a[], int n)	//First element is valley
{
	int i=0;

	for(; i<n; i+=2)
	{
		if(i!=0 && a[i] > a[i-1])
			swap(a[i], a[i-1]);

		if(i!=n-1 && a[i] > a[i+1])
			swap(a[i], a[i+1]);
	}

	i-=2;

	if(i==n-1 && a[n-1]>a[0])
		swap(a[n-1], a[0]);

	if(i==n-2 && a[n-1]<a[0])
		swap(a[n-1], a[0]);
}





int main()
{
	int A[]={1, 3, 4, 2, 7, 8};
	int N = sizeof(A)/sizeof(int);

	WaveSort_Sin(A, N);	

	for(int i=0; i<N; i++)
		cout<<A[i]<<" ";

	cout<<endl;
	return 0;
}