#include<iostream>
using namespace std;
int i, j;

void Selection_Sort(int A[], int N)
{int min, t;

	for(i=0; i<N-1; i++)
	{	min=i;
		 for(j=i+1; j<N; j++)
			if(A[j]<A[min]) min=j;

		if(min!=i)
		{
			t=A[i];
			A[i]=A[min];
			A[min]=t;
		}
	}
cout<<endl<<"Array has been sorted using Selection Sort."<<endl;
}


int main ()
{int n;

	cout<<"How many integers do you want to enter in your array ?"<<endl;
	cin>>n;

	int *ptr = new int[n];

	cout<<"Input "<<n<<" integers..."<<endl;
	for (i=0; i<n; i++)
		cin>>ptr[i];

	Selection_Sort(ptr,n);
	cout<<endl<<"Sorted Array..."<<endl;
	for (i=0; i<n; i++)
		cout<<ptr[i]<<" ";

delete[] ptr;
return 0;}

