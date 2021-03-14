#include <iostream>
#include <list>
#include <queue>
using namespace std;


class Graph
{
	list<int> *l;
	int v;
	public:

	Graph(int v)
	{
		this->v=v;
		l=new list<int>[v];
	}

	void addEdge(int x, int y)
	{
		l[x].push_back(y);
	}


	void TS()
	{
		const int k=v;
		int indeg[k]={0};

		for(int i=0; i<v; i++)
			for(auto nbr:l[i])
				indeg[nbr]++;

		queue<int> q;

		for(int i=0; i<v; i++)
			if(indeg[i]==0)
				q.push(i);

		while(!q.empty())
		{
			int tmp=q.front();

			for(auto nbr:l[tmp])
			{
				indeg[nbr]--;

				if(indeg[nbr]==0)
					q.push(nbr);
			}

			cout<<tmp<<" ";
			q.pop();
		}

		cout<<endl;
	}


	~Graph()
	{
		delete[] l;
	}
};


int main()
{
	Graph g(6);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(2,5);
	g.addEdge(3,5);
	g.addEdge(4,5);

	g.TS();
	return 0;
}