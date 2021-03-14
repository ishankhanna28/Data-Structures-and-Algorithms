#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define val first
#define row second.first
#define col second.second 
typedef pair< int, pair<int,int> > node;

//O(NlogK)

vector<int> Merge(vector< vector<int> > v)
{
	int i, j; 
	int n=v[0].size(), k=v.size();
	vector<int> ans;
	ans.reserve(n*k);
	priority_queue< node, vector<node>, greater<node> > p;

	for(i=0; i<k; i++)
		p.push( make_pair( v[i][0], make_pair(i,0) ) );

	while(!p.empty())
	{
		node cur=p.top();
		p.pop();
		ans.push_back(cur.val);

		if(cur.col+1<n)
			p.push( make_pair( v[cur.row][cur.col+1], make_pair(cur.row,cur.col+1) ));
	}

	return ans;
}


int main()
{
	vector< vector<int> > v;
	int k, n, d;
	cin>>k>>n;
	v.reserve(k);

	for(int i=0; i<k; i++)
	{
		vector<int> Row;
		Row.reserve(n);

		for(int j=0; j<n; j++)
		{
			cin>>d;
			Row.push_back(d);
		}

		v.push_back(Row);
	}

	vector<int> V = Merge(v);
	for(auto x:V)
		cout<<x<<" ";

	cout<<endl;
	return 0;
}