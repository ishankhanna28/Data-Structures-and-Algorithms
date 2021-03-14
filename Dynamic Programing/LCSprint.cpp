#include <iostream>
#include <vector> 
#include <string>
using namespace std;


void PrintLCS(string s1, string s2)	//Bottom up in O(n^2) time & space
{
	int n1 = s1.length();
	int n2 = s2.length();
	const int K1=n1+1;
	const int K2=n2+1;
	int dp[K1][K2]={0};

	for(int i=0; i<=n1; i++)
		for(int j=0; j<=n2; j++)
			dp[i][j]=0;

	for(int i=1; i<=n1; i++)
	{
		for(int j=1; j<=n2; j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;

			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}

	
	//Print in O(n)
	vector<char> v;
	int cnt=0, i=n1, j=n2;

	while(i and j)
	{
		if(dp[i][j]==dp[i-1][j])
			i--;

		else if(dp[i][j]==dp[i][j-1])
			j--;

		else
		{
			v.push_back(s1[i-1]);
			i--;
			j--;
		}
	}

	for(int i=v.size()-1; i>=0; i--)
		cout<<v[i];
}


int main()
{
	string s1, s2;
	cin>>s1>>s2;
	PrintLCS(s1,s2);
	cout<<endl;
	return 0;
}