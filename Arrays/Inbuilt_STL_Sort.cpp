#include<iostream>
#include<algorithm>
using namespace std;

bool COMPARE(int a, int b)
{return (a>b);}


int main ()
{int i, n;

	cout<<"How many integers do you want to enter in your array ?"<<endl;
	cin>>n;

	int *A = new int[n];

	cout<<"Input "<<n<<" integers..."<<endl;
	for (i=0; i<n; i++)
		cin>>A[i];

	sort(A, A+n, COMPARE);
	cout<<endl<<"Sorted Array in descending order..."<<endl;
	for (i=0; i<n; i++)
		cout<<A[i]<<" ";

	sort(A, A+n);
	cout<<endl<<endl<<"Sorted Array in asscending order..."<<endl;
	for (i=0; i<n; i++)
		cout<<A[i]<<" ";



delete[] A;
return 0;}