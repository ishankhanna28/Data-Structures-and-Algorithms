//WAP to count no. of pairs in an array for which a[i]>a[j] and i<j
//DIVIDE AND CONQUER
#include <iostream>
#include <algorithm>
using namespace std;


int CrossInversions(int a[], int lb, int ub, int mid)
{
	int i=lb, j=mid+1, cnt=0;
	sort(a+lb, a+mid+1);
	sort(a+mid+1, a+ub+1);


	while(i<=mid && j<=ub)
	{
		if(a[i]>a[j])
		{
			j++;
			cnt+= (mid-i)+1;
		}

		else if(a[i]<a[j])
		{
			i++;
		}

		else
		{
			i++;
			j++;
		}
	}

	return cnt;
}


int InversionCount(int a[], int lb, int ub)
{
	if(lb>=ub)
		return 0;

	int mid = (ub+lb)/2;
	return InversionCount(a, lb, mid) + InversionCount(a, mid+1, ub) + CrossInversions(a, lb, ub, mid); 	
}



int main()
{
	int A[]={1, 5, 2, 6, 3, 0}, N=sizeof(A)/sizeof(int);
	cout<<InversionCount(A, 0, N-1)<<endl;
	return 0;
}