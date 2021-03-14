#include <iostream>
#include <unordered_map>
using namespace std;

//WAP to find the longest subarray having zero sum

int LongSub(int a[], int n)
{
	unordered_map<int,int> m;
	int pre=0, len=0;

	for(int i=0; i<n; i++)
	{
		pre+=a[i];

		if(pre==0)
			len=max(len, i+1);

		else if(m.count(pre))
			len=max(len, i-m[pre]);

		else
			m[pre]=i;
	}

	return len;
}


int main()
{			 
	int a[]= {1, 0, -1, -1, 2, 4, 3};
	int n = sizeof(a)/sizeof(int);

	cout<<LongSub(a,n)<<endl;
	return 0;
}