#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

/*
5
2 1 3
4*/


int Cell(int n, int x, int y, int z)		//O(n) time and space
{
	const int k=n+1;
	int dp[k];
//	memset(dp, INT_MAX, sizeof(dp));
	dp[1]=0;

	for(int i=2; i<=n; i++)
		if(i%2)
			dp[i]=min(dp[i-1]+y, dp[(i+1)/2]+x+z);
		else
			dp[i]=min(dp[i/2]+x, dp[i-1]+y);

	return dp[n];
}


int main()
{
	int n=5, x=2, y=1, z=3;
	cout<<Cell(n,x,y,z)<<endl;
	return 0; 
}