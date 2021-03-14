#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define pss pair<string, string>
#define int long long


int Str2Int(string s)
{
	int sum=0;

	for(int i=s.length(), t=1; i>=0; i--, t*=10)
		sum+= (s[i]- '0')*t;

	return sum;
}


bool LexiCmp(pss a, pss b)
{
	return b.second > a.second;
}

bool NumCmp(pss a, pss b)
{
	return Str2Int(b.second) > Str2Int(a.second);
}


string Extract_Token(string str, int k)
{
	char *s = strtok((char*)str.c_str(), " ");

	while(--k)
		s= strtok(NULL, " ");

    return (string) s;
}


int32_t main()
{
	int n, key;
	cin>>n;
	cin.get();

	const int K1=n;
	pss sp[K1];

	for(int i=0; i<n; i++)
		getline(cin, sp[i].first);

	string cmptyp, reversed;
	cin>>key>>reversed>>cmptyp;

	for(int i=0; i<n; i++)
		sp[i].second = Extract_Token(sp[i].first, key);


	if(cmptyp=="numeric")
		sort(sp, sp+n, NumCmp);

	else
		sort(sp, sp+n, LexiCmp);

	if(reversed=="true")
		for(int i=0; i<n/2; i++)
			swap(sp[i], sp[n-1-i]);

	for(int i=0; i<n; i++)
		cout<<sp[i].first<<endl;

	return 0;
}