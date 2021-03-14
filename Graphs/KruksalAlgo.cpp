#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


class DSU
{
	int v, *parent, *rank;
	public:

	DSU(int v)
	{
		this->v=v;
		parent=new int[v];
		rank=new int[v];
		memset(parent, -1, sizeof(int)*v);

		for(int i=0; i<v; i++)
			rank[i]=1;
	}

	int Find(int i)
	{
		if(parent[i]==-1)
			return i;

		return parent[i]=Find(parent[i]);
	}


	bool Union(int u, int v)
	{
		int s1 = Find(u);
		int s2 = Find(v);

		if(s1==s2)
			return false;

		if(s2>s1)
		{
			parent[s1]=s2;
			rank[s2]+=rank[s1];
		}

		else
		{
			parent[s2]=s1;
			rank[s1]+=rank[s2];
		}

		return true;
	}

	~DSU()
	{
		delete[] parent;
		delete[] rank;
	}
};


class Graph
{
	int v, e;
	vector< vector<int> > l;
	public:

	Graph(int v=3, int e=3)
	{
		this->v=v;
		this->e=e;
		l.reserve(e);
	}

	void addEdge(int x, int y, int w)
	{
		if(x>y)
			swap(x,y);

		l.push_back({w,x,y});
	}


	int MST()							//O(E)
	{
		int sum=0;
		DSU s(v);
		sort(l.begin(),l.end());

		for(auto edge:l)
			if(s.Union(edge[1],edge[2]))
				sum+=edge[0];

		return sum;
	}
};


int main()
{
	int v, e;
	cin>>v>>e;
	Graph g(v,e);

	while(e--)
	{
		int x, y, z;
		cin>>x>>y>>z;
		g.addEdge(x,y,z);
	}

	cout<<g.MST()<<endl;
	return 0;
}