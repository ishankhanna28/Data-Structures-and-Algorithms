#include <iostream>
#include <list>
using namespace std;

class Queue
{
	int cs;	//Current Size
	list<int> l;
	public:

	Queue()
	{
		cs=0;
	}

	int Qsize()
	{
		return cs;
	}

	void Push(int d)
	{
		l.push_back(d);
		cs++;
	}

	void Pop()
	{
		l.pop_front();
		cs--;
	}

	int Get_Front()
	{
		return l.front();
	}

};


int main()
{
	Queue Q;

	for(int i=1; i<=10; i++)
		Q.Push(i*2);

	while(Q.Qsize()!=0)
	{
		cout<<Q.Get_Front()<<" ";
		Q.Pop();
	}

	cout<<endl;
	return 0;
}