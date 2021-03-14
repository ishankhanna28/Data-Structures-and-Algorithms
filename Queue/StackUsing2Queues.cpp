#include <iostream>
#include <queue>
using namespace std;

//Keeping Pop as Expensive Operation

template <typename T>
class STACK
{
	queue<T> q1, q2;
	public:

	void Push(T data)	//O(1)
	{
		q1.push(data);
	}

	void Pop()	//O(N)
	{
		if(q1.empty())
			return;

		while(q1.size()>1)
		{
			q2.push(q1.front());
			q1.pop();
		}

		q1.pop();
		swap(q1,q2);
	}


	T Top()		//O(1)
	{
		return q1.back();
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
		s.Push(i*4);

	while(!s.Empty())
	{
		cout<<s.Top()<<" ";
		s.Pop();
	}

	cout<<endl;
	return 0;
}