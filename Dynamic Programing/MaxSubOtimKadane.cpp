#include <iostream>
using namespace std;


int MaxSub(int a[], int n)		//Bottom Down O(N) time and space
{
	int maxsum=0, sum=0;

	for(int i=0; i<n; i++)
	{
		sum=max(sum+a[i],0);
		maxsum=max(maxsum,sum);
	}

	if(maxsum==0 and a[0]!=0)
	{
		maxsum=a[0];

		for(int i=1; i<n; i++)
			maxsum=max(maxsum,a[i]);
	}

	return maxsum;
}


int main()
{
//	int a[]={-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
	int a[]={-78, -11, -2, -4, -7};
	int n = sizeof(a)/sizeof(int);
	cout<<MaxSub(a,n)<<endl;
	return 0;
}