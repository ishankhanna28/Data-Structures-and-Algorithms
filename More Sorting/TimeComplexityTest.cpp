#include <iostream>
#include <ctime>
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


void Bubble_Sort(int A[], int N)
{
	int i, j, t;

	for(i=0; i<N-1; i++)
		{
			for(j=0; j<N-1-i; j++)
			
			if(A[j]>A[j+1])
				{
					t=A[j];
					A[j]=A[j+1];
					A[j+1]=t;
				}
		}
}


int main()
{
	int N=5;
//	cin>>N;
	const int K1=N;
	int A[K1];

	for(int i=0, j=N/3; i<N; i++, j--)
	{
		if(i%2)
			A[i] = (N-i);

		else
			A[i] = (N-i) + j;
	}

	time_t bStart = clock();	//Returns current time on computer clock.
	Bubble_Sort(A, N);
	time_t bEnd = clock();
	cout<<"Bubble Sort: "<< (bEnd - bStart) <<" milliseconds."<<endl;

	time_t qStart = clock();
	QuickSort(A, 0, N-1);
	time_t qEnd = clock();
	cout<<"Bubble Sort: "<< (bEnd - bStart) <<" milliseconds."<<endl;

	return 0;
}