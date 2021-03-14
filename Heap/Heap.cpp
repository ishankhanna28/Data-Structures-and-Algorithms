#include <iostream>
#include <vector>
using namespace std;


class Heap
{
	vector<int> v;
	bool minheap;

	bool compare(int a, int b)
	{
		if(minheap)
			return b>a;

		return a>b;
	}

	public:

	Heap(bool type=true, int default_size=10)
	{
		minheap=type;
		v.reserve(default_size);
		v.push_back(-1);
	}

	void Push(int d)	//O(logN)
	{
		v.push_back(d);
		int idx=v.size()-1;
		int parent=idx/2;

		while(idx>1 and compare(v[idx],v[parent]))
		{
			swap(v[idx],v[parent]);
			idx=parent;
			parent=idx/2;
		}
	}


	void heapify(int idx)
	{
		int left=2*idx;
		int right=left+1;
		int min_idx=idx, last=v.size()-1;

		if(left<=last and compare(v[left],v[min_idx]))
			min_idx=left;

		if(right<=last and compare(v[right],v[min_idx]))
			min_idx=right;

		if(min_idx!=idx)
		{
			swap(v[idx],v[min_idx]);
			heapify(min_idx);
		}
	}


	void Pop()	//O(logN)
	{
		int last=v.size()-1;
		swap(v[1], v[last]);
		v.pop_back();
		heapify(1);
	}

	bool Empty()
	{
		return v.size()==1;
	}

	int Top()
	{
		return v[1];
	}
};


int main()
{
	Heap h(0);
	int a[]={22, 11, 55, 66, 44, 33};
	int n = sizeof(a)/sizeof(int);

	for(int i=0; i<n; i++)
		h.Push(a[i]);

	while(!h.Empty())
	{
		cout<<h.Top()<<" ";
		h.Pop();
	}

	cout<<endl;
	return 0;
}