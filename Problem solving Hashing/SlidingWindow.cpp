#include <iostream>
#include <cstring>
using namespace std;

//WAP 2 find the shortest substring containing all characters in a given pattern

string SubString(string str, string pat)
{
	int sl = str.length();
	int pl = pat.length();

	if(pl>sl)
		return "\0";

	int P[256] = {0};
	int S[256] = {0};

	for(int i=0; i<pl; i++)
	{
		P[pat[i]]++;
	}


	int cnt=0, lb=0, ub, start=-1, min_len=sl+1;

	for(ub=0; ub<sl; ub++)
	{
		char ch = str[ub];
		S[ch]++;

		if(P[ch]>0 and S[ch]<=P[ch])
		{
			cnt++;
		}

		if(cnt==pl)
		{
			char temp = str[lb];

			while(S[temp]>P[temp] or P[temp]==0)
			{
				S[temp]--;
				lb++;
				temp=str[lb];
			}


			int cur_len = ub-lb+1;

			if(cur_len<min_len)
			{
				min_len=cur_len;
				start=lb;
			}
		}
	}

	if(start==-1)
			return "\0";

	return str.substr(start, min_len);
}


int main()
{
	cout<<SubString("heelleeoaeo world", "eelo")<<endl;
	return 0;
}