//WAP to generate all divisors of a given integer.
//60 = 2^2 x 3^1 x 5^1
//1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vp vector<pair<int,int>>
#define ff first
#define ss second

//O(sqrt(n))

vp Fatcorize(int n)
{
	int i, cnt;
	vp v;

	for(i=2; i*i<=n; i++)
	{
		cnt=0;

		while(n%i==0)
		{
			cnt++;
			n/=i;
		}

		if(cnt)
			v.push_back(make_pair(i,cnt));
	}

	if(n!=1)
		v.push_back(make_pair(n,1));

	return v;
}


int main()
{
	int num=60, ans, t, i, j;
//	cin>>num;
	vp V=Fatcorize(num);
	vi div, divisors;
	div.reserve(V.size());

	for(auto x:V)
	{
		while(x.ss)
		{
			div.push_back(x.ff);
			x.ss--;
		}
	}

	for(i=0; i<(1<<div.size()); i++)
	{
		ans=1;
		t=i;
		j=0;

		while(t)
		{
			if(t&1)
				ans*=div[j];

			t=t>>1;
			j++;
		}

		divisors.push_back(ans);
	}

	sort(divisors.begin(),divisors.end());

	for(i=0; i<divisors.size(); i++)
		if(divisors[i]!=divisors[i-1])
			cout<<divisors[i]<<" ";

	cout<<endl;
	return 0;
}