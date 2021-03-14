#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int freq[26]={0};
	queue<char> q;
	char ch='a';

	while(ch!='.')
	{
		cin>>ch;

		freq[ch-'a']++;
		q.push(ch);

		while(!q.empty())
		{
			if( freq[q.front()-'a']==1 )
			{
				cout<<q.front()<<endl;
				break;
			}

			else
			{
				q.pop();
			}
		}

		if(q.empty())
			cout<<"-1 "<<endl;
	}

	return 0;
}