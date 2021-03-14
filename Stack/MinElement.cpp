//WAP to find minnimum element in stack using O(1) complexity

#include <iostream>
#include <stack>
using namespace std;


void INSERT(stack<int> &s, int &mini, int num)
{
	if(s.empty())
	{
		mini=num;
		s.push(num);
		return;
	}

	if(num < mini)
	{
		int temp=mini;
		mini = num;
		num = 2*num - temp;
	}

	s.push(num);
}


void DELETE(stack<int> &s, int &mini)
{
	int num = s.top();
	s.pop();

	if(num < mini)
		mini = 2*mini - num;
}


int main()
{
	stack<int> s;
	int min=0;
	INSERT(s, min, 3);
	INSERT(s, min, 5);
	cout<<min<<endl;
	INSERT(s, min, 2);
	INSERT(s, min, 1);
	cout<<min<<endl;
	DELETE(s,min);
	cout<<min<<endl;
	DELETE(s,min);
	cout<<min<<endl;
	return 0;
}