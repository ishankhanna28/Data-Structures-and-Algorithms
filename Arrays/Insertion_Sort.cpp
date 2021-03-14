#include<iostream>
using namespace std;
int i, j;

void Insertion_Sort(int A[], int N)
{int t;
	for(i=1; i<N; i++)
	{
	t=A[i];
		for(j=i-1; j>=0 && t<A[j]; j--)
			A[j+1]=A[j];
	A[j+1]=t;
	}
cout<<endl<<"Array has been sorted using Insertion Sort."<<endl;}


int main ()
{int n;

	cout<<"How many integers do you want to enter in your array ?"<<endl;
	cin>>n;

	int *ptr = new int[n];

	cout<<"Input "<<n<<" integers..."<<endl;
	for (i=0; i<n; i++)
		cin>>ptr[i];

	Insertion_Sort(ptr,n);
	cout<<endl<<"Sorted Array..."<<endl;
	for (i=0; i<n; i++)
		cout<<ptr[i]<<" ";

delete[] ptr;
return 0;}
