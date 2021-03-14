#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

//https://www.codechef.com/problems/TACHSTCK

int main()
{
	int n, d;
	cin>>n>>d;

	const int K=n;
	int L[K];

	for(int i=0; i<n; i++)
		cin>>L[i];

	sort(L,L+n);
	int i=0, cnt=0;
	while(i<=n-2)
	{
		if((L[i+1]-L[i])<=d)
		{
			cnt++;
			i+=2;
		}

		else
			i++;
	}

	cout<<cnt<<endl;
	return 0;
}