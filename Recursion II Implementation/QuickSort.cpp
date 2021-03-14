#include <iostream>
using namespace std;


int PARTITION(int a[], int lb, int ub)
{
	int i=lb-1, j;

	for(j=lb; j<ub; j++)
		if(a[j] < a[ub])
			swap(a[++i], a[j]);

	swap(a[++i], a[ub]);
	return i;
}


void QuickSort(int a[], int lb, int ub)	//O(NlogN) complexity
{										//O(N^2) in worst case, so it should be randomized
	if(lb>=ub)
		return;

	int p = PARTITION(a, lb, ub);

	QuickSort(a, lb, p-1);
	QuickSort(a, p+1, ub);
}


int main()
{
	int i, N;
	cin>>N;
	const int K1 = N;
	int A[K1];

	for(i=0; i<N; i++)
		cin>>A[i];

	QuickSort(A, 0, N-1);

	for(i=0; i<N; i++)
		cout<<A[i]<<" ";

	cout<<endl;
	return 0;
}