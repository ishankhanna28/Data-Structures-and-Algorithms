#include<iostream>
using namespace std;
int i, j;

bool COMPARE(int a, int b)
{return (b>a);}


void Bubble_Sort(int A[], int N, bool(&cmp)(int x, int y))
{int t;
	for(i=0; i<N-1; i++)
		{for(j=0; j<N-1-i; j++)
			if(cmp(A[j],A[j+1]))
				swap(A[j],A[j+1]);
		}
cout<<endl<<"Array has been sorted using Bubble Sort."<<endl;}


int main ()
{int n;

	cout<<"How many integers do you want to enter in your array ?"<<endl;
	cin>>n;

	int *ptr = new int[n];

	cout<<"Input "<<n<<" integers..."<<endl;
	for (i=0; i<n; i++)
		cin>>ptr[i];

	Bubble_Sort(ptr,n, COMPARE);
	cout<<endl<<"Sorted Array in descending order..."<<endl;
	for (i=0; i<n; i++)
		cout<<ptr[i]<<" ";

delete[] ptr;
return 0;}
