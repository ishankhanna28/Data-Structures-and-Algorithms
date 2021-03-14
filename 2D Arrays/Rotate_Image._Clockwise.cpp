#include<iostream>
#include <algorithm>
using namespace std;
int R, C, i;
//WAP to Rotate image clockwise by 90 degrees.
/*
  For Rotate 90 deg anticlock first reverse row then take transpose.
  For Rotate 90 deg clock first take Transpose then reverse row.
*/

void Transpose_Arr(int **A, int N)
{
	for(R=0; R<N; R++)
		for(C=0; C<R; C++)
			swap(A[R][C],A[C][R]);
}

/*
void Rev_Row(int **A, int N)
{
	for(R=0; R<N; R++)
		for(C=0, i=N-1; C<N/2; C++, i--)
			swap(A[R][C],A[R][i]);
}
*/

void Rot_CW_90(int **A, int N)
{
	Transpose_Arr(A,N);
//	Rev_Row(A,N);

	for(R=0; R<N; R++)
		reverse(A[R], A[R]+N);
}


int main()
{
	int n;
	cin>>n;

	int **A = new int*[n];
	for(R=0; R<n; R++)
		A[R] = new int[n];

	for(R=0; R<n; R++)
		for(C=0; C<n; C++)
			cin>>A[R][C];

	Rot_CW_90(A,n);

	for(R=0; R<n; R++)
	{cout<<endl;
		for(C=0; C<n; C++)
			cout<<A[R][C]<<" ";
	}

	for(R=0; R<n; R++)
		delete[] A[R];
	delete[] A;
	return 0;
}


/*
Given a 2D array of size N x N. Rotate the array 90 degrees clockwise.



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
13 9 5 1
14 10 6 2
15 11 7 3
16 12 8 4


Explanation
Rotate the array 90 degrees clockwise.
*/