#include <iostream>
#include <vector>
using namespace std;


class Graph
{
	vector<int> *v;
	int n;
	public:

	Graph(int n)
	{
		this->n=n;
		v=new vector<int>[n];
	}

	void addEdge(int x, int y)
	{
		v[x].push_back(y);
		v[y].push_back(x);
	}

	void Print()
	{
		for(int i=0; i<n; i++)
		{
			cout<<i<<" -> ";

			for(auto x:v[i])
				cout<<x<<" ";

			cout<<endl;
		}
	}
};


int main()
{
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.Print();
	return 0;
}