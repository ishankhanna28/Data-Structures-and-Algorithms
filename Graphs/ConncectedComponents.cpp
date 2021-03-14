#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <map>
using namespace std;


template<typename T>
class Graph
{
	unordered_map<T, list<T> > m;
	public:

	void addEdge(T x, T y)
	{
		m[x].push_back(y);
		m[y].push_back(x);
	} 


	void dfs(T src, map<T,bool> &visited)
	{
		cout<<src<<" ";
		visited[src]=true;

		for(auto nbr:m[src])
			if(!visited[nbr])
				dfs(nbr,visited);
	}


	void DFS()
	{
		map<T, bool> visited;

		for(auto p:m)
			visited[p.first]=false;

		for(auto p:visited)
		{
			if(!visited[p.first])
			{
				dfs(p.first, visited);
				cout<<endl;
			}
		}
	}



};


int main()
{
	Graph<int> g;
	g.addEdge(8,8);

	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(0,3);
	g.addEdge(0,4);

	g.addEdge(5,6);
	g.addEdge(6,7);

	g.DFS();
	return 0;
}