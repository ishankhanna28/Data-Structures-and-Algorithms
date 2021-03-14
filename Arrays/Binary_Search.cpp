#include<iostream>
using namespace std;
int i;

int Binary_Search(int A[], int N, int num)
{int LB=0, UB=N-1, mid, f=0;

	while(LB<=UB && !f)
	{
		mid=(LB+UB)/2;
		if (A[mid]==num) f++;
		else if (A[mid]>num) UB=mid-1;
		else if (A[mid]<num) LB=mid+1;
	}

if(f) return mid;
else return -1;}


int Sort_Check(int a[], int size)
{int s=1;

	for (i=0; i<size-1; i++)
		if (a[i]>a[i+1]) {s--; break;}

return s;}


int main ()
{int n, NUM, r, S;

	cout<<"How many integers do you want to enter in your array ?"<<endl;
	cin>>n;

	int *ptr = new int[n];

	cout<<"Input "<<n<<" integers..."<<endl;
	for (i=0; i<n; i++)
		cin>>ptr[i];

	S=Sort_Check(ptr,n);
	if(!S) cout<<"Given Array is not sorted. Hence, Binary Search algorithm is not applicable"<<endl;

	else{
	cout<<"Which number do you want to search for ?"<<endl;
	cin>>NUM;

	r=Binary_Search(ptr, n, NUM);
		if(r==-1) cout<<"Element is not present in the array"<<endl;
		else cout<<"Element found at "<<r<<"th subscript value"<<endl;
	}

delete[] ptr;
return 0;}
