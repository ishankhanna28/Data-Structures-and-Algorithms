#include<iostream>
using namespace std;
int i;

int Rain_Water(int A[], int N)
{
	int MAX=0, sum=0, *L=new int[N], *R=new int[N];

	for(i=N-1; i>=0; i--)
	{
		MAX=max(A[i],MAX);
		R[i]=MAX;
	}

	for(MAX=0,i++; i<N; i++)
	{
		MAX=max(A[i],MAX);
		L[i]=MAX;
		sum += min(L[i],R[i]) - A[i];
	}

	delete[] L;
	delete[] R;
	return sum;
}


int main()
{
	int n, *a;

//	cout<<"How many integers do you want to enter in your array ?"<<endl;
	cin>>n;
	a = new int[n];
	for (i=0; i<n; i++)
		cin>>a[i];

//	cout<<"No. of volume units of rainwater harvested = "<<
	cout<<Rain_Water(a,n);

	delete[] a;
	return 0;
}


/*
Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

Explanation for the Sample input Testcase:
Elevation Map

So the total units of water she can save is 5 units

Input Format
First line contains an integer n. Second line contains n space separated integers representing the elevation map.

Constraints
1 <= N <= 10^6

Output Format
Print a single integer containing the maximum unit of waters she can save.

Sample Input
10
0 2 1 3 0 1 2 1 2 1
Sample Output
5
Explanation
Refer to the image for explanation. Count the number of cells having water in them.
*/

