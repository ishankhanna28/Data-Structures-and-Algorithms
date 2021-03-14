#include <iostream>
#include <vector>
using namespace std;

//O(NlogN)

bool compare(int a, int b, bool maxh)
{
	if(maxh)
		return a>b;

	return b>a;
}


void heapify(int idx, vector<int> &v, bool maxh, int N)
{
	int left=2*idx;
	int right=left+1;
	int min_idx=idx, last=N-1;

	if(left<=last and compare(v[left],v[min_idx],maxh))
		min_idx=left;

	if(right<=last and compare(v[right],v[min_idx],maxh))
		min_idx=right;

	if(min_idx!=idx)
	{
		swap(v[idx],v[min_idx]);
		heapify(min_idx,v,maxh,N);
	}
}


void BuildHeap(vector<int> &v, bool maxH, int n)
{
	for(int i=(v.size()-1)/2; i>0; i--)
		heapify(i,v,maxH,n);
}


void HeapSort(vector<int> &v)
{
	int n = v.size();
	BuildHeap(v,1,n);

	while(n>=3)
	{
		swap(v[1],v[n-1]);
		n--;
		heapify(1,v,1,n);
	}
}


int main()
{
	vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
	HeapSort(v);

	for(int x:v)
		cout<<x<<" ";

	cout<<endl;
	return 0;
}