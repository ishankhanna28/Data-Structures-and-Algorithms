#include <iostream>
#include <vector>
using namespace std;

//Build a Heap from a Vector inplace(without external space) in O(N)

bool compare(int a, int b, bool maxh)
{
	if(maxh)
		return a>b;

	return b>a;
}


void heapify(int idx, vector<int> &v, bool maxh)
{
	int left=2*idx;
	int right=left+1;
	int min_idx=idx, last=v.size()-1;

	if(left<=last and compare(v[left],v[min_idx],maxh))
		min_idx=left;

	if(right<=last and compare(v[right],v[min_idx],maxh))
		min_idx=right;

	if(min_idx!=idx)
	{
		swap(v[idx],v[min_idx]);
		heapify(min_idx,v,maxh);
	}
}

void BuildHeap(vector<int> &v, bool maxH)
{
	for(int i=(v.size()-1)/2; i>0; i--)
		heapify(i,v,maxH);
}


int main()
{
	vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
	BuildHeap(v,1);

	for(int x:v)
		cout<<x<<" ";

	cout<<endl;
	return 0;
}