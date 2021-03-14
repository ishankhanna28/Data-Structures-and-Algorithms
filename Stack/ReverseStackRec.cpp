//WAP to reverse a STACK using recursion (without use of any other data structure).
//Time O(N^2)
//Space O(N)


#include <iostream>
#include <stack>
using namespace std;
#define si stack<int>


void InsertAtBottom(si &s, int num)
{
	if(s.empty())
	{
		s.push(num);
		return;
	}

	int temp = s.top();
	s.pop();
	InsertAtBottom(s, num);
	s.push(temp);
}


void RevStackRec(si &s, int n)
{
	if(!n)
		return;

	int temp=s.top();
	s.pop();
	RevStackRec(s, n-1);
	InsertAtBottom(s, temp);
}


int main()
{
	si S;
	int N, x;
	cin>>N;

	for(int i=1; i<=N; i++)
	{
		cin>>x;
		S.push(x);
	}

	RevStackRec(S, N);

	while(!S.empty())
	{
		cout<<S.top()<<endl;
		S.pop();
	}

	return 0;
}