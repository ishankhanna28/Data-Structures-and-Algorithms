#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://www.spoj.com/problems/BUSYMAN/
//Busy Man or Activity Planner using Greedy

#define pii pair<int,int>
#define lb first
#define ub second

bool compare(pii a, pii b)
{
	return b.ub>a.ub;
}


int ActPlan(vector<pii> v)
{
	sort(v.begin(), v.end(), compare);
	int cnt=0, fin=-1;
	
	for(auto p:v)
	{
		if(cnt==0 or p.lb>=fin)
		{
			fin=p.ub;
			cnt++;
		}
	}

	return cnt;
}



void solve()
{
	int n, s, e;
	cin>>n;

	vector<pii> v;
	v.reserve(n);

	while(n--)
	{
		cin>>s>>e;
		v.push_back(make_pair(s,e));
	}

	cout<<ActPlan(v)<<endl;
	v.clear();
}

int main()
{
	int T=1;
	cin>>T;

	while(T--)
		solve();

	return 0;
}