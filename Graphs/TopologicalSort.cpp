#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include <map>
using namespace std;


template<typename T>
class Graph
{
	map<T, list<T> > m;
	public:

	void addEdge(T x, T y)
	{
		m[x].push_back(y);
//		m[y].push_back(x);
	} 


	void dfs(T src, map<T,bool> &visited, list<T> &order)
	{
		visited[src]=true;

		for(auto nbr:m[src])
			if(!visited[nbr])
				dfs(nbr,visited,order);

		order.push_front(src);
		return;
	}


	void TS()
	{
		map<T, bool> visited;
		list<T> order;

		for(auto p:m)
			visited[p.first]=false;

		for(auto p:visited)
			if(!visited[p.first])
				dfs(p.first, visited, order);

		for(auto x:order)
			cout<<x<<endl;
	}

};


int main()
{
	Graph<string> g;
	g.addEdge("Python", "Data Proc");
	g.addEdge("Python", "PyTorch");
	g.addEdge("Python", "ML");
	g.addEdge("Data Proc", "ML");
	g.addEdge("PyTorch", "DL");
	g.addEdge("ML", "DL");
	g.addEdge("DL", "Face Recogn");
	g.addEdge("Data Set", "Face Recogn");
	g.TS();
	return 0;
}