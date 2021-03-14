#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//All Pair Shortest Path Algorithm (APSP)
//O(N^3) time and O(N^2) space
//2D DP with Bottom Up build

void FloydWarshall(vector< vector<int> > dp)
{
	int n=dp.size();

	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(dp[i][k]!=INT_MAX and dp[k][j]!=INT_MAX)		//Avoid overflow
					dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);


	for(int i=0; i<n; i++)			//Print DP matrix
	{
		for(int j=0; j<n; j++)
			cout<<dp[i][j]<<" ";

		cout<<endl;
	}
}


class Graph
{
	vector< vector<int> > dp;	//Adjacency Matrix
	public:

	Graph(int n)
	{
		dp.reserve(n);

		for(int i=0; i<n; i++)
		{
			vector<int> v;
			v.reserve(n);

			for(int j=0; j<n; j++)
			{
				if(i==j)
					v.push_back(0);
				else
					v.push_back(INT_MAX);
			}

			dp.push_back(v);
		}
	}

	void addEdge(int u, int v, int w)
	{
		dp[u][v]=w;
	}

	void APSP()
	{
		FloydWarshall(dp);
	}
};


int main()
{
	Graph g(4);
	g.addEdge(1,0,4);
	g.addEdge(0,2,-2);
	g.addEdge(2,3,2);
	g.addEdge(3,1,-1);
	g.addEdge(1,2,3);
	g.APSP();
	return 0;
}