#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//Check Cycle in undirected Graph
//Complexities mentioned are without PCO & URO
//Only PCO -> O(logN) average
//PCO + URO-> O(1)

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


	bool Union(int u, int v, int parent[], vector<int> &rank)	//O(V) because of find function calls
	{
		int s1 = Find(u, parent);
		int s2 = Find(v, parent);

		if(s1==s2)
			return false;

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

		return true;
	}


	bool ContainsCycle()								//O(E*V)
	{
		const int K=v;
		int parent[K];
		memset(parent, -1, sizeof(parent));
		vector<int> rank(v, 1);

		for(auto edge:l)
			if(!Union(edge.first, edge.second, parent, rank))
				return true;

		return false;
	}

};


int main()
{
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);

	if(g.ContainsCycle())
		cout<<"Cyclic"<<endl;
	else
		cout<<"Tree"<<endl;

	return 0;
}