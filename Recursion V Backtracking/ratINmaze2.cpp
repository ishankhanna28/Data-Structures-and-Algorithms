//Print rightmost solution.

#include <iostream>
#include <stdio.h>
using namespace std;
const int K=1000;


bool ratINmaze(int a[][K], char s[][K], int m, int n, int r=0, int c=0)
{
	if(r==m-1 && c==n-1)
	{
        a[r][c]++;

		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
				cout<<a[i][j]<<" ";

			cout<<endl;
		}

		cout<<endl;
		return true;
	}

	else if(r>=m || c>=n || s[r][c]=='X')
		return false;

	//Otherwise assume route is possible through current element
	a[r][c]++;

	if( ratINmaze(a, s, m, n, r, c+1) )	     //moving right
	{	
		a[r][c]--;
		return true;
	}

	else if( ratINmaze(a, s, m, n, r+1, c) ) //moving down
	{
		a[r][c]--;
		return true;
	}

	else
	{	
		a[r][c]--;
		return false;
	}
}


int main()
{
	int M, N;
	cin>>M>>N;

	int A[M+1][K]={0};
	char str[M+1][K];

	for(int i=0; i<M; i++)
	{
        for(int j=0; j<N; j++)
            cin>>str[i][j];
	}

	if(!ratINmaze(A, str, M, N))
		cout<<"-1"<<endl;

	return 0;
}