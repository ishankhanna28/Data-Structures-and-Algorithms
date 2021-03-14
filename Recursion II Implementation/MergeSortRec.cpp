#include <iostream>
using namespace std;


void MERGE_SORT_REC(int a[], int n, int lb=0, int ub=-1)
{
	if(ub==-1)
		ub=n-1;

	if(lb>=ub)
		return;

	//1) Divide into 2 parts
	int mid=(ub+lb)/2;

	//2) Recursively sort both arrays
	MERGE_SORT_REC(a, n, lb, mid);
	MERGE_SORT_REC(a, n, mid+1, ub);

	//3) Merge
	int i=lb, j=mid+1, k=lb, M=mid-lb+1, N=ub-mid;
	int C[ub-lb+1];

	while(i<=mid && j<=ub)
	{
		if(a[i]<a[j]) 
			C[k++]=a[i++];

		else if(a[j]<a[i]) 
			C[k++]=a[j++];
	
		else
		{
			C[k++]=a[i++];
			C[k++]=a[j++];
		}
	}

	while(i<=mid) 
		C[k++]=a[i++];

	while(j<=ub) 
		C[k++]=a[j++];

	for(int t=lb; t<=ub; t++)
		a[i]=C[i];
}


int main()
{
	int i, N;
	cin>>N;
	const int K=N;
	int A[K];

	for(i=0; i<N; i++)
		cin>>A[i];

	MERGE_SORT_REC(A, N);

	for(i=0; i<N; i++)
		cout<<A[i]<<" ";

	cout<<endl;
	return 0;
}