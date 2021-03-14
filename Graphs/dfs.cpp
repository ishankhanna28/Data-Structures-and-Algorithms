#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
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


	void dfs(T src)
	{
		static unordered_set<T> s;
		cout<<src<<" ";
		s.insert(src);

		for(auto nbr:m[src])
			if(s.find(nbr)==s.end())
				dfs(nbr);
	}
};


int main()
{
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(3,0);

	g.dfs(0);
	cout<<endl;
	return 0;
}