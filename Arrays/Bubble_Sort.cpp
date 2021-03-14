#include<iostream>
using namespace std;
int i, j;


void Bubble_Sort(int A[], int N)
{
	int t;

	for(i=0; i<N-1; i++)
		{
			for(j=0; j<N-1-i; j++)
			
			if(A[j]>A[j+1])
				{
					t=A[j];
					A[j]=A[j+1];
					A[j+1]=t;
				}
		}
		
	cout<<endl<<"Array has been sorted using Bubble Sort."<<endl;
}


int main ()
{int n;

	cout<<"How many integers do you want to enter in your array ?"<<endl;
	cin>>n;

	int *ptr = new int[n];

	cout<<"Input "<<n<<" integers..."<<endl;
	for (i=0; i<n; i++)
		cin>>ptr[i];

	Bubble_Sort(ptr,n);
	cout<<endl<<"Sorted Array..."<<endl;
	for (i=0; i<n; i++)
		cout<<ptr[i]<<" ";

delete[] ptr;
return 0;}
