#include <iostream>
#include <stack>
using namespace std;


template <typename T>
class QUEUE
{
	stack<T> s1, s2;
	public:

	void Push(T data)	//O(1)
	{
		s1.push(data);
	}


	void Pop()		//O(N)
	{
		if(s1.empty())
			return;

		while(s1.size()>1)
		{
			s2.push(s1.top());
			s1.pop();
		}

		s1.pop();

		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}


	T Front()		//O(N)
	{
		while(s1.size()>1)
		{
			s2.push(s1.top());
			s1.pop();
		}

		T t=s1.top();

		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}

		return t;
	}


	bool Empty()	//O(1)
	{
		return s1.empty();
	}
};


int main()
{
	QUEUE<int> q;

	for(int i=1; i<=10; i++)
		q.Push(i*5);

	while(!q.Empty())
	{
		cout<<q.Front()<<" ";
		q.Pop();
	}

	cout<<endl;
	return 0;
}