#include <iostream>
#include <list>
#include <queue>
#include <unordered_set>
#include <cstring>
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
		l[y].push_back(x);
	}


	bool ContainCycle(int src=0)			//BFS
	{
		unordered_set<int> s;
		const int K=v;
		int parent[K];
		memset(parent, -1, sizeof(parent));

		queue<int> q;
		q.push(src);
		s.insert(src);

		while(!q.empty())
		{
			int tmp = q.front();

			for(auto nbr:l[tmp])
			{
				if(s.find(nbr)==s.end())
				{
					parent[nbr]=tmp;
					q.push(nbr);
					s.insert(nbr);
				}

				else if(parent[tmp]!=nbr)
					return true;
			}

			q.pop();
		}

		return false;
	}


	bool CC(int src=0, int parent=-1)				//DFS
	{
		static unordered_set<int> s;
		s.insert(src);

		for(auto nbr:l[src])
		{
			if(s.find(nbr)==s.end())
			{
				if(CC(nbr,src))
					return true;
			}

			else if(nbr!=parent)
				return true;
		}

		return false;
	}


	~Graph()
	{
		delete[] l;
	}
};


int main()
{
	Graph g(5);
	g.addEdge(1,2);
	g.addEdge(0,1);
	g.addEdge(2,3);
//	g.addEdge(3,0);
	g.addEdge(4,0);
	
	cout<<"BFS: ";
	if(g.ContainCycle())
		cout<<"Cyclic";
	else
		cout<<"Tree";

	cout<<endl<<"DFS: ";
	if(g.CC())
		cout<<"Cyclic";
	else
		cout<<"Tree";

	cout<<endl;
	return 0;
}