#include <iostream>
#include <queue>
using namespace std;

//Keeping Push as Expensive Operation

template <typename T>
class STACK
{
	queue<T> q1, q2;
	public:

	void Push(T data)	//O(N)
	{
		q2.push(data);

		while(!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}

		swap(q1,q2);
	}

	void Pop()	//O(1)
	{
		if(q1.empty())
			return;

		q1.pop();
	}


	T Top()		//O(1)
	{
		return q1.front();
	}

    bool Empty()	//O(1)
    {
        return  q1.size()+q2.size()==0;
    }
};


int main()
{
	STACK<int> s;

	for(int i=1; i<=10; i++)
		s.Push(i*5);

	while(!s.Empty())
	{
		cout<<s.Top()<<" ";
		s.Pop();
	}

	cout<<endl;
	return 0;
}