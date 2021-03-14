#include <iostream>
#include <unordered_map>
#include <set>
#include <list>
#include <climits>
#include <string>
#include <map>
using namespace std;


template<typename T>
class Graph
{
	unordered_map<T, list< pair<int,T> > > m;
	public:

	void addEdge(T x, T y, int len=1, bool bidir=true)
	{
		m[x].push_back(make_pair(len,y));

		if(bidir)
			m[y].push_back(make_pair(len,x));
	}

	void Print()
	{
		for(auto node:m)
		{
			cout<<node.first<<" -> ";

			for(auto nbr:node.second)
				cout<<"("<<nbr.second<<","<<nbr.first<<") ";

			cout<<endl;
		}
	}


	void Dijkstra(T src)				//O(ElogV)
	{
		map<T,int> dist;
		set< pair<int,T> > s;

		for(auto node:m)
			dist[node.first]=INT_MAX;

		dist[src]=0;
		s.insert(make_pair(0,src));


		while(!s.empty())				//first->dist and second->node
		{
			auto itr = s.begin();
			auto node=*itr;
			s.erase(itr);

			for(auto nbr:m[node.second])
			{
				if(nbr.first + node.first < dist[nbr.second])
				{
					auto it = s.find(make_pair(dist[nbr.second],nbr.second));
					if(it!=s.end())
						s.erase(it);

					dist[nbr.second]=nbr.first + node.first;
					s.insert(make_pair(dist[nbr.second],nbr.second));
				}
			}
		}

		for(auto p:dist)
		{
			if(p.second==0)
				continue;

			if(p.second==INT_MAX)
				cout<<"-1 ";
			else
				cout<<p.second<<" ";
		}
	}
};


void solve()
{
	Graph<int> g;
	int n, m, x, y, r, s;
	cin>>n>>m;

	while(m--)
	{
		cin>>x>>y>>r;
		g.addEdge(x,y,r);
	}

	cin>>s;
	g.Dijkstra(s);
	cout<<endl;
}


int main()
{
	int t;
	cin>>t;

	while(t--)
		solve();

	return 0;
}

/*
int main()
{
	Graph<string> india;
	india.addEdge("Amritsar", "Delhi", 1);
	india.addEdge("Amritsar", "Jaipur", 4);
	india.addEdge("Jaipur", "Delhi", 2);
	india.addEdge("Jaipur", "Mumbai", 8);
	india.addEdge("Bhopal", "Agra", 2);
	india.addEdge("Mumbai", "Bhopal", 3);
	india.addEdge("Agra", "Delhi", 1);
	india.Dijkstra("Amritsar");
	return 0;
}
*/

