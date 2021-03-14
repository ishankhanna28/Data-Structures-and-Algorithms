#include <iostream>
#include <vector>
using namespace std;


class Graph
{
	int n;
	vector<int> *l;
	public:

	Graph(int n)
	{
		this->n=n;
		l=new vector<int>[n];
	}

	void addEdge(int u, int v, bool bidir=true)
	{
		l[u].push_back(v);

		if(bidir)
			l[v].push_back(u);
	}


	bool dfs(int colours[], int node=0, int color=1, int parent=-1)
	{
		colours[node]=color;

		for(auto nbr:l[node])
		{
			if(colours[nbr]==0 and !dfs(colours, nbr, 3-color, node))
				return false;

			if(nbr!=parent and colours[nbr]==color)
				return false;
		}

		return true;
	}


	bool isBipart()
	{
		const int K=n;
		int color[K]={0};
		return dfs(color);
	}


	~Graph()
	{
		delete[] l;
	}
};


int main()
{
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(3,2);
	g.addEdge(3,4);

	if(g.isBipart())
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}