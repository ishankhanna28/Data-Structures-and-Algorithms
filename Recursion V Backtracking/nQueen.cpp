#include <iostream>
using namespace std;


bool isSafe(int a[][11], int n, int i, int j)
{
	int r=i, c=j;

	while(r>=0)	
		if(a[r--][c])
			return false;

	r=i, c=j;

	while(r>=0 && c>=0)
		if(a[r--][c--])
			return false;

	r=i, c=j;

	while(r>=0 && c<n)
		if(a[r--][c++])
			return false;

	return true;
}


void nQueen(int a[][11], int n, int i=0)
{
	static int cnt=0;

	if(i==n)
	{
		cnt++;
		return;
	}


	for(int j=0; j<n; j++)
	{
		if (isSafe(a, n, i, j))
		{
			a[i][j]++;
			nQueen(a, n, i+1);
			a[i][j]--;
		}
	}

	if(!i)
		cout<<cnt<<endl;
}


int main()
{
	int N;
	cin>>N;

	int A[11][11]={0};
	nQueen(A, N);
	return 0;
}