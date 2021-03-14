#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//Greedy approach is only valid for Indian currency

int CC(int money, vector<int> &coins, int dp[])		//O(N) time and space
{
	for(int i=1; i<=money; i++)
	{
		int mini=INT_MAX;

		for(auto x:coins)
		{
			if(x>i)
				break;

			mini=min(mini, dp[i-x]+1);
		}

		dp[i]=mini;
	}

	return dp[money];
}



int CoinChange(int n, vector<int> &coins)
{
	const int K=n+1;
	int dp[K]={0};
	sort(coins.begin(),coins.end());
	return CC(n,coins,dp);
}


int main()
{
	vector<int> coins{7, 10, 1};
	int n;
//	cin>>n;
	n=15;

	cout<<CoinChange(n,coins)<<endl;
	return 0;
}