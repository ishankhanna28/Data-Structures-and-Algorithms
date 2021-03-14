#include <iostream>
#include <vector>
using namespace std;
#define int long long

//https://www.spoj.com/problems/HOLI/
//DFS solution in O(N) time and space

class Graph
{
	int n;
	vector< pair<int,int> > *l;
	public:

	Graph(int n)
	{
		this->n=n;
		l=new vector< pair<int,int> >[n+1];
	}

	void addEdge(int u, int v, int w)
	{
		l[u].push_back(make_pair(v,w));
		l[v].push_back(make_pair(u,w));
	}


	int dfs(int cnt[], int node=1)
	{
		static int ans;

		if(node==1)
			ans=0;

		cnt[node]++;

		for(auto nbr:l[node])
			if(cnt[nbr.first]==0)
			{
				int temp = dfs(cnt, nbr.first);
				cnt[node]+= cnt[nbr.first];
				ans+= min(cnt[nbr.first], n-cnt[nbr.first])*2*nbr.second;
			}

		return ans;
	}


	int Holi()
	{
		const int K=n+1;
		int cnt[K]={0};
		return dfs(cnt);
	}


	~Graph()
	{
		delete[] l;
	}
};


void solve()
{
	int n;
	cin>>n;
	Graph g(n);
	n--;

	while(n--)
	{
		int x, y, z;
		cin>>x>>y>>z;
		g.addEdge(x,y,z);
	}

	cout<<g.Holi()<<endl;
}


int32_t main()
{
	int t;
	cin>>t;

	for(int i=1; i<=t; i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}

	return 0;
}