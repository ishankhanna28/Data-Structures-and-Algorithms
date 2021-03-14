#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


class Graph
{
	int v;
	vector< pair<int,int> > l;
	public:

	Graph(int v)
	{
		this->v=v;
		l.reserve(v);
	}


	void addEdge(int u, int v)
	{
		if(u>v)
			swap(u,v);

		l.push_back(make_pair(u,v));
	}


	int Find(int i, int parent[])						//O(V)
	{
		if(parent[i]==-1)
			return i;

		return parent[i]=Find(parent[i], parent);		// Path Compression Optimization (PCO)
	}


	void Union(int u, int v, int parent[], vector<int> &rank)	//O(V) because of find function calls
	{
		int s1 = Find(u, parent);
		int s2 = Find(v, parent);

		if(s1==s2)
			return;

		//Union Rank Optimization (URO)
		if(rank[s1]>rank[s2])
		{
			parent[s2]=s1;
			rank[s1]+=rank[s2];
		}
		else
		{
			parent[s1]=s2;
			rank[s2]+=rank[s1];
		}

		return;
	}


	int CountPairs()
	{
		const int k=v;
		int parent[k], sum=0;
		memset(parent, -1, sizeof(parent));
		vector<int> rank(v,1);
		
		for(auto edge:l)
			Union(edge.first, edge.second, parent, rank);

		for(int i=0; i<v; i++)
			sum+= v-rank[Find(i, parent)];

		return sum/2;
	}

};


int main()
{
	int n, m;
	cin>>n>>m;
	Graph g(n);

	while(m--)
	{
		int x, y;
		cin>>x>>y;
		g.addEdge(x,y);
	}

	cout<<g.CountPairs()<<endl;
	return 0;
}