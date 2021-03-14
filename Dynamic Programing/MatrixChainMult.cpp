#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int MCM(vector<int> a)
{
	int n=a.size()-2;
	const int k=n+1;
	int dp[k][k]={0};

	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			dp[i][j]=0;


	for(int i=1; i<=n-1; i++)
	{
		for(int j=1; (i+j)<=n; j++)
		{
			int r=j, c=j+i;
			dp[r][c]=INT_MAX;

			for(int k=r; k<c; k++)
				dp[r][c]=min(dp[r][c], dp[r][k] + dp[k+1][c] + (a[r]*a[k+1]*a[c+1]) );
		}
	}
/*
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=n; j++)
			cout<<dp[i][j]<<" ";

		cout<<endl;
	}*/

	return dp[1][n];
}


int main()
{
	vector<int> v{-1, 1, 2, 3, 4, 3};
	cout<<MCM(v)<<endl;
	return 0;
}