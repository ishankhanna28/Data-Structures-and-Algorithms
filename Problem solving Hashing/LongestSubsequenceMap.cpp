#include <iostream>
#include <unordered_map>
using namespace std;


int LCS(int a[], int n)
{
	unordered_map<int,int> m;

	for(int i=0; i<n; i++)
	{
		int n = a[i];

		if(m.count(n))
			continue;

		else if(!m.count(n-1) and !m.count(n+1))
		{
			m[n]=1;
		}

		else if(m.count(n-1) and !m.count(n+1))
		{
			int len = m[n-1];
			m[n] = len + 1;
			m[n-len]++;
		}

		else if(!m.count(n-1) and m.count(n+1))
		{
			int len = m[n+1];
			m[n]=len+1;
			m[n+len]++;
		}

		else
		{
			int left = m[n-1];
			int right = m[n+1];
			int len = left + right + 1;

			m[n-left]=len;
			m[n+right]=len;
		}
	}

	int max_len=0;
	for(auto p:m)
		max_len=max(max_len,p.second);
	return max_len;
}


int main()
{			 
	int a[]= {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17, 10};
	int n = sizeof(a)/sizeof(int);

	cout<<LCS(a,n)<<endl;
	return 0;
}