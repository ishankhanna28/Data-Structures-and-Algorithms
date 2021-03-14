//WAP to find first occurrence of an integer in an array using recursion.
#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;


int FirstOcc(int a[], int n, int num, int i=0)
{
	if(i==n)
		return -1;

	else if(a[i]==num)
		return i;

	else 
		return FirstOcc(a,n,num,i+1);
}


int FirstOcc2(int a[], int n, int num)
{
	if(!n) 
		return -1;

	else if(a[0]==num)
		return 0;

	int i=FirstOcc2(a+1, n-1, num);

	if(i<0)
		return -1;

	else 
		return i+1;
}


int LastOcc(int a[], int n, int num)
{
	if(!n)
		return -1;


	else if(a[n-1]==num)
		return n-1;

	else 
		return LastOcc(a, n-1, num);

}


int LastOcc2(int a[], int n, int num)
{
	if(!n)
		return -1;

	int i = LastOcc2(a+1, n-1, num);

	if(a[0]==num && i<0)
		return 0;

	else if(i>=0)
		return i+1;

	else 
		return -1;
}


int AllOcc(int a[], int b[], int n, int num, int i=0, int j=0)
{
	int k;
	if(i==n)
		return j;

	if(a[i]==num)
	{
		b[j]=i;
		k=AllOcc(a,b,n,num,i+1,j+1);
	}

	else 
	{
		k=AllOcc(a,b,n,num,i+1,j);
	}

	return k;
}



int main()
{
	int A[]= {1, 2, 3, 2, 7, 6, 4, 10, 7, 5};
	const int N = sizeof(A)/sizeof(int);
	int B[N];
	int Num = 7;

	int K=AllOcc(A,B,N,Num);

	for(int I=0; I<K; I++)
		cout<<B[I]<<" ";

	cout<<endl;
	return 0;
}

