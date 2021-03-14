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
	}


	bool ContainsCycle(int src=0)				//DFS to find back edge
	{
		static unordered_set<int> visited, stack;
		visited.insert(src);
		stack.insert(src);

		for(auto nbr:l[src])
		{
			if(visited.find(nbr)==visited.end())
			{
				if(ContainsCycle(nbr))
					return true;
			}

			else if(stack.find(nbr)!=stack.end())
				return true;
		}

		stack.erase(stack.find(src));
		return false;
	}


	~Graph()
	{
		delete[] l;
	}
};


int main()
{
	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(1,5);
	g.addEdge(5,6);
//	g.addEdge(4,2);
	
	if(g.ContainsCycle())
		cout<<"Cyclic";
	else
		cout<<"Tree";

	cout<<endl;
	return 0;
}