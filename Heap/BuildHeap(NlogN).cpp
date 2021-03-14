#include <iostream>
#include <vector>
using namespace std;

//Build a Heap from a Vector inplace(without external space) in O(NlogN)

bool compare(int a, int b, bool maxh)
{
	if(maxh)
		return a>b;

	return b>a;
}

void BuildHeap(vector<int> &v, bool maxH)
{
	int i, idx, parent;

	for(i=2; i<v.size(); i++)
	{
		idx=i;
		parent=idx/2;

		while(idx>1 and compare(v[idx], v[parent], maxH))
		{
			swap(v[idx],v[parent]);
			idx=parent;
			parent/=2;
		}
	}
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