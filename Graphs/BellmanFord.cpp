#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//SSSP algorithms
//BFS - unweighted only; O(V+E)
//Dijkstra - weighted ok, but no negative edge; O(ElogV)
//Bellman Ford - most powerful; O(E*V)


class Graph
{
	int v;
	vector< vector<int> > l;	//weight, edge list
	public:

	Graph(int v)
	{
		this->v=v;
		l.reserve(v);
	}

	void addEdge(int x, int y, int len)	//Directed Graph
	{
		l.push_back({len, x, y});
	}


	vector<int> BFord(int src)
	{
		vector<int> dist(v,INT_MAX);
		dist[src]=0;

		for(int i=1; i<v; i++)
		{
			for(auto edge:l)
			{
				int w = edge[0];
				int u = edge[1];
				int v = edge[2];

				if(dist[u]!=INT_MAX and dist[u]+w<dist[v])
					dist[v]=dist[u]+w;
			}
		}

		for(auto edge:l)						//Check for -ve cycle
		{
			int w = edge[0];
			int u = edge[1];
			int v = edge[2];

			if(dist[u]!=INT_MAX and dist[u]+w<dist[v])
				return vector<int>(v,INT_MIN);
		}

		return dist;
	}
};


void solve()
{
	int n, m, s;
	cin>>n>>m;
	Graph g(n);

	while(m--)
	{
		int x, y, r;
		cin>>x>>y>>r;
		g.addEdge(x,y,r);
	}

	cin>>s;
	vector<int> v = g.BFord(s);

	for(auto num:v)
	{
		if(num==INT_MIN)
		{
			cout<<"Negative Cycle Detected"<<endl;
			return;
		}

		if(num==INT_MAX)
		{
			cout<<"-1 ";
			continue;
		}

		if(num==0)
			continue;

		cout<<num<<" ";
	}

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