#include<iostream>
using namespace std;
int i;

int Linear_Search(int A[], int N, int num)
{int f=0;

	for (i=0; i<N; i++)
		if (A[i]==num) {f++; break;}

if(f) return i;
else return -1;}


int main ()
{int n, NUM, r;

	cout<<"How many integers do you want to enter in your array ?"<<endl;
	cin>>n;

	int *ptr = new int[n];

	cout<<"Input "<<n<<" integers..."<<endl;
	for (i=0; i<n; i++)
		cin>>ptr[i];

	cout<<"Which number do you want to search for ?"<<endl;
	cin>>NUM;

	r=Linear_Search(ptr, n, NUM);
		if(r==-1) cout<<"Element is not present in the array"<<endl;
		else cout<<"Element found at "<<r<<"th subscript value"<<endl;

delete[] ptr;
return 0;}