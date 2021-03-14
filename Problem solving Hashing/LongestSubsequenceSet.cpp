#include <iostream>
#include <unordered_set>
using namespace std;


int LCS(int a[], int n)
{
	unordered_set<int> s;
	int max_len=0;

	for(int i=0; i<n; i++)
		s.insert(a[i]);

	for(int i=0; i<n; i++)
	{
		int n = a[i];

		if(s.find(n-1)==s.end())
		{
			int len=1;

			while(s.find(n+1)!=s.end())
			{
				len++;
				n++;
			}

			max_len=max(max_len,len);
		}
	}

	return max_len;
}


int main()
{			 
	int a[]= {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17, 10};
	int n = sizeof(a)/sizeof(int);

	cout<<LCS(a,n)<<endl;
	return 0;
}
