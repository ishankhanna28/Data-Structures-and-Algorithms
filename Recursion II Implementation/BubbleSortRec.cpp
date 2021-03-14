#include <iostream>
using namespace std;


void BubbleSortRec(int a[], int n, int j=0)
{
	if(n==1)
		return;

	if(j==n-1)
		BubbleSortRec(a, n-1);

	else 
	{
		if(a[j]>a[j+1])
			swap(a[j],a[j+1]);

		BubbleSortRec(a, n, j+1);
	}
}


int main()
{
	int A[] = {25, 46, 32, 78, 14, 72};
	int N = sizeof(A)/sizeof(int), i;
	BubbleSortRec(A,N);

	for(i=0; i<N; i++)
		cout<<A[i]<<" ";

	cout<<endl;
	return 0;
}