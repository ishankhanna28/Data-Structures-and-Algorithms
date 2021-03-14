#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;


template<typename t>
class Graph
{
	unordered_map<t,list<t>> m;
	public:

	void addEdge(t x, t y)
	{
		m[x].push_back(y);
		m[y].push_back(x);
	}


	void SSSP(t src)
	{
		queue<t> q;
		map<t, int> dist;

		for(auto p:m)
			dist[p.first]=-1;
		
		q.push(src);
		dist[src]=0;

		while(!q.empty())
		{
			t tmp = q.front();

			for(auto nbr:m[tmp])
			{
				if(dist[nbr]==-1)
				{
					q.push(nbr);
					dist[nbr] = dist[tmp] + 1;
				}
			}

			q.pop();
		}

		for(auto p:dist)
		{
			if(p.first==src)
				continue;

			if(p.second!=-1)
				p.second*=6;

			cout<<p.second<<" ";
		}
	}
};


void solve()
{
	int n, m, s;
	Graph<int> g;
	cin>>n>>m;

	const int k=n+1;
	int a[k]={0};

	while(m--)
	{
		int u, v;
		cin>>u>>v;
		g.addEdge(u,v);
		a[u]++;
		a[v]++;
	}


	for(int i=1; i<=n; i++)
		if(a[i]==0)
			g.addEdge(i,i);

	cin>>s;
	g.SSSP(s);
	cout<<endl;
}


int main()
{
	int q;
	cin>>q;

	while(q--)
		solve();

	return 0;
}