#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//Greedy approach is only valid for Indian currency

int CC(int money, vector<int> &coins, int dp[])		//O(N) time and space
{
	if(money==0)
		return 0;

	if(dp[money]>0)
		return dp[money];

	int mini=INT_MAX;

	for(auto x:coins)
	{
		if(x>money)
			break;

		mini=min(mini, CC(money-x,coins,dp)+1);
	}

	return dp[money]=mini;
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