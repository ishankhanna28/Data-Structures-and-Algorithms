#include<iostream>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second
int i;

pii Binary_Search(int A[], int N, int num)
{
	int LB=0, UB=N-1, mid, f=0;
	pii p=make_pair(-1,N);

	while(LB<=UB && !f)
	{
		mid=(LB+UB)/2;
		if (A[mid]==num) f++;
		else if (A[mid]>num) UB=mid-1;
		else if (A[mid]<num) LB=mid+1;
	}

	//Find first and last occurrence 
	
	if(f)
	{
		for(LB=mid; A[LB]==num && LB>=0; LB--);
		LB++;
	
		for(UB=mid; A[UB]==num && UB<N; UB++);
		UB--;
	
		p.ff=LB;
		p.ss=UB;
	}

	return p;
}

int Sort_Check(int a[], int size)
{
	int s=1;

	for (i=0; i<size-1; i++)
		if (a[i]>a[i+1]) {s--; break;}

	return s;
}


int main ()
{
	int n, NUM, r, S;
	pii P;

	cout<<"How many integers do you want to enter in your array ?"<<endl;
	cin>>n;

	int *ptr = new int[n];

	cout<<"Input "<<n<<" integers..."<<endl;
	for (i=0; i<n; i++)
		cin>>ptr[i];

	S=Sort_Check(ptr,n);
	if(!S) 
		cout<<"Given Array is not sorted. Hence, Binary Search algorithm is not applicable"<<endl;

	else
	{
		cout<<"Which number do you want to search for ?"<<endl;
		cin>>NUM;

		P=Binary_Search(ptr, n, NUM);

		if(P.ff<0) 
			cout<<"Element is not present in the array"<<endl;
		else 
		{
			cout<<endl<<"Element found in given array"<<endl;
			cout<<"No. of occurrences of given element = "<<(P.ss - P.ff + 1)<<endl;
			cout<<"First occurrence at "<<P.ff<<"th subscript index"<<endl;
			cout<<"Last occurrence at "<<P.ss<<"th subscript index"<<endl;
		}
	}

	delete[] ptr;
	return 0;
}
