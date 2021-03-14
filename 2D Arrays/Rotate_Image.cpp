#include<iostream>
using namespace std;
int R, C;
//https://hack.codingblocks.com/app/practice/2/1012/problem

void Rotate_Image(int **A, int N)
{
	for(C=N-1; C>=0; C--)
	{
		cout<<endl;

		for(R=0; R<N; R++)
			cout<<A[R][C]<<" ";
	}
}


int main()
{
	int n;
	cin>>n;

	int **A = new int*[n];
	for(R=0; R<n; R++)
		A[R] = new int[n];

	for(R=0; R<n; R++)
	{
		for(C=0; C<n; C++)
			cin>>A[R][C];
	}

	Rotate_Image(A,n);

	for(R=0; R<n; R++)
		delete[] A[R];
	delete[] A;
	return 0;
}


/*
Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.



Input Format
First line contains a single integer N. Next N lines contain N space separated integers.

Constraints
N < 1000

Output Format
Print N lines with N space separated integers of the rotated array.

Sample Input
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Sample Output
4 8 12 16 
3 7 11 15 
2 6 10 14 
1 5 9 13 

Explanation
Rotate the array 90 degrees anticlockwise.
*/