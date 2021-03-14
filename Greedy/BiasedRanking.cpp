#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define int long long

//https://www.spoj.com/problems/BAISED/
//Use Counting Sort


int MinBadness(int freq[], int n)
{
	int rank=1, sum=0;

	for(int i=1; rank<=n; i++)
	{
		while(freq[i])
		{
			sum+= abs(i-rank);
			rank++;
			freq[i]--;
		}
	}

	return sum;
}


void solve()
{
	int n, num, freq[1000000]={0};
	string str;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>str>>num;
		freq[num]++;
	}

	cout<<MinBadness(freq, n)<<endl;
} 


int32_t main()
{
	int T=1;
	cin>>T;

	while(T--)
		solve();

	return 0;
}