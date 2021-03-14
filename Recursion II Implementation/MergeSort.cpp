#include <iostream>
#define int long long
using namespace std;


void M_ERGE(int a[], int lb, int ub, int mid)
{
	int i=lb, j=mid+1, k=lb;
	const int K2=ub+1;
	int B[K2];

	while(i<=mid && j<=ub)
	{
		if(a[i]<a[j])
			B[k++]=a[i++];

		else if(a[j]<a[i])
			B[k++]=a[j++];

		else
		{
			B[k++]=a[i++];
			B[k++]=a[j++];
		}
	} 

	while(i<=mid)
		B[k++]=a[i++];

	while(j<=ub)
		B[k++]=a[j++];

	for(int t=lb; t<=ub; t++)
		a[t]=B[t];
}


void M_S(int a[], int lb, int ub)
{
	if(lb>=ub)
		return;

	int mid=(ub+lb)/2;

	M_S(a, 0, mid);
	M_S(a, mid+1, ub);

	M_ERGE(a,lb,ub,mid);
}


void M_ergeSort(int A[],int N)
{
	M_S(A,0,N-1);
}


int32_t main()
{
	int N, i;
	cin>>N;
	const int K1=N;
	int A[K1];

	for(i=0; i<N; i++)
		cin>>A[i];

	M_ergeSort(A,N);

	for(i=0; i<N; i++)
		cout<<A[i]<<" ";

	cout<<endl; 
	return 0;
}