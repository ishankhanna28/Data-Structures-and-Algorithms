#include <iostream>
#include <vector>
using namespace std;


int Elephant(int r, int c)							//Bottom up in O(N^3) time & O(N^2) space
{
	const int k1=r, k2=c;
	vector<vector<int>> dp(r, vector<int> (c,0));
	dp[0][0]++;

	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			for(int k=0; k<j; k++)
				dp[i][j]+=dp[i][k];

			for(int k=0; k<i; k++)
				dp[i][j]+=dp[k][j];
		}
	}

	return dp[r-1][c-1];
}


int Rat(int r, int c)							//Bottom up in O(N^2) time & space
{
	const int k1=r, k2=c;
	int dp[k1][k2];

	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			if(i==0 and j==0)
				dp[i][j] = 1;

			else if(i==0)
				dp[i][j] = 1;

			else if(j==0)
				dp[i][j] = 1;

			else
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}

	return dp[r-1][c-1];
}


int main()
{
	cout<<Rat(4,4)<<endl;
	cout<<Elephant(5,2)<<endl;
	return 0;
}	