#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


class Graph
{
	int n;
	vector<int> *l;
	vector<int> *rev;
	public:

	Graph(int n)
	{
		this->n=n;
		l=new vector<int>[n];
		rev=new vector<int>[n];
	}

	void addEdge(int u, int v)
	{
		l[u].push_back(v);
		rev[v].push_back(u);
	}


	void dfs1(int node, bool visited[], vector<int> &stack)
	{
		visited[node]=true;

		for(auto nbr:l[node])
			if(!visited[nbr])
				dfs1(nbr, visited, stack);

		stack.push_back(node);
	}


	void dfs2(int node, bool visited[])
	{
		visited[node]=true;
		cout<<node<<" ";

		for(auto nbr:rev[node])
			if(!visited[nbr])
				dfs2(nbr, visited);
	}


	void SCC()									//O(N^2) time and O(N) space
	{
		const int K=n;
		bool visited[K]={0};
		vector<int> stack;
		stack.reserve(n);

		for(int i=0; i<n; i++)
			if(!visited[i])
				dfs1(i, visited, stack);

		memset(visited, 0, n);
		char ch = 'A';

		for(int i=stack.size()-1; i>=0; i--)
			if(!visited[stack[i]])
			{
				cout<<"Component "<<ch++<<" -> ";
				dfs2(stack[i], visited);
				cout<<endl;
			}
	}


	~Graph()
	{
		delete[] l;
		delete[] rev;
	}

};


int main()
{
	Graph g(7);
	g.addEdge(2,1);
	g.addEdge(1,0);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(6,3);
	g.addEdge(3,4);
	g.SCC();
	return 0;
}