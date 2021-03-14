#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Top Down DP
//O(n^2) space

int LCS(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
	if(s1[i]=='\0' or s2[j]=='\0')
		return 0;

	if(dp[i][j]>=0)
		return dp[i][j];

	if(s1[i]==s2[j])
		return dp[i][j] = 1 + LCS(s1,s2,i+1,j+1,dp);

	return dp[i][j]=max(LCS(s1,s2,i+1,j,dp), LCS(s1,s2,i,j+1,dp));
}


int lcsTD(string s1, string s2)
{
	int n1 = s1.length();
	int n2 = s2.length();
	vector<vector<int>> dp(n1, vector<int>(n2,-1));	//Initialises a (n1 x n2) vector of -1
	return LCS(s1,s2,0,0,dp);
}


int main()
{
	string s1 = "ABCD";
	string s2 = "ABEDG";
	cout<<lcsTD(s1,s2)<<endl;
	return 0;
}