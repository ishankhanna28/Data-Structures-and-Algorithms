//Print all possible solutions.

#include <iostream>
#include <stdio.h>
using namespace std;
const int K=5;


bool ratINmaze(int a[][K], char s[][K], int m, int n, int r=0, int c=0)
{
	if(r==m-1 && c==n-1)
	{
        a[r][c]=1;

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

	bool right = ratINmaze(a, s, m, n, r, c+1); //moving right	
	bool down  = ratINmaze(a, s, m, n, r+1, c);  //moving down

	a[r][c]--; //BACKTRACKING

	if(right || down)
		return true;

	else 
		return false;
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
/*
Sample Input

4 4
O O O O
O O X O
O O O X
O X O O


OUTPUT

1 1 0 0 
0 1 0 0 
0 1 1 0 
0 0 1 1 

1 0 0 0 
1 1 0 0 
0 1 1 0 
0 0 1 1 

1 0 0 0 
1 0 0 0 
1 1 1 0 
0 0 1 1 

*/