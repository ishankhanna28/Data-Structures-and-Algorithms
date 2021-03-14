#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long
#define station pair<int,int>
#define dist first
#define fuel second

//https://www.spoj.com/problems/EXPEDI/

void solve()
{
	int n, d, f, cnt=0;
	vector<station> v;
	priority_queue<int> p;

	cin>>n;
	v.reserve(n);

	for(int i=0; i<n; i++)
	{
		cin>>d>>f;
		v.push_back(make_pair(d,f));
	}

	cin>>d>>f;

	for(int i=0; i<n; i++)
		v[i].dist = d-v[i].dist;

	sort(v.begin(), v.end());
	int prev=0;

	for(auto x:v)
	{
		int temp = x.dist-prev;

		while(f-temp<0)
		{
			if(p.empty())
			{
				cnt=-1;
				break;
			}

			f+=p.top();
			p.pop();
			cnt++;
		}

		f-=temp;
		p.push(x.fuel);
		prev=x.dist;
	}


	while(f<d-prev)
	{
		if(p.empty())
		{
			cnt=-1;
			break;
		}

		f+=p.top();
		p.pop();
		cnt++;
	}

	cout<<cnt<<endl;
}


int32_t main()
{
	int T=1;
	cin>>T;

	while(T--)
		solve();

	return 0;
}