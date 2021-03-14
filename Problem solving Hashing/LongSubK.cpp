#include <iostream>
#include <unordered_map>
using namespace std;

//WAP to find the longest subarray having sum = k

int LongSub(int a[], int n, int k)
{
	unordered_map<int,int> m;
	int pre=0, len=0;

	for(int i=0; i<n; i++)
	{
		pre+=a[i];

		if(pre==k)
			len=max(len, i+1);

		else if(m.count(pre-k))
			len=max(len, i-m[pre-k]);

		else
			m[pre]=i;
	}

	return len;
}


int main()
{			 
	int a[]= {1, -1, 5, -2, 3};
	int n = sizeof(a)/sizeof(int);
	int k = 3;

	cout<<LongSub(a,n,k)<<endl;
	return 0;
}