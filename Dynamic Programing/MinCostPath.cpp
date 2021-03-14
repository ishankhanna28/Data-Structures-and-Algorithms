#include <iostream>
using namespace std;
const int n=3;


int MinCost(int cost[][n])							//Bottom up in O(N^2) time & space
{
	int dp[n][n];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==0 and j==0)
				dp[i][j] = cost[i][j];

			else if(i==0)
				dp[i][j] = dp[i][j-1] + cost[i][j];

			else if(j==0)
				dp[i][j] = dp[i-1][j] + cost[i][j];

			else
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cost[i][j];
		}
	}

	return dp[n-1][n-1];
}


int main()
{
	int cost[][n]={{1, 5, 2}, {7, 1, 1}, {8, 1, 3}};
	cout<<MinCost(cost)<<endl;
	return 0;
}	