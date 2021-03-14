//WAP to reverse a STACK using "another STACK".
//Time O(N^2)
//Space O(N)

#include <iostream>
#include <stack>
#define si stack<int>
using namespace std;


void Transfer(si &s1, si &s2, int n)
{
	while(n--)
	{
		s2.push(s1.top());
		s1.pop();
	}
}


void RevStack(si &s1, int n)
{
	si s2;
	int temp;

	for(int i=1; i<n; i++)
	{
		temp=s1.top();
		s1.pop();

		Transfer(s1, s2, n-i);
		s1.push(temp);
		Transfer(s2, s1, n-i);
	}	
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

	RevStack(S, N);

	while(!S.empty())
	{
		cout<<S.top()<<endl;
		S.pop();
	}

	return 0;
}