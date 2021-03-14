#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<utility>	//for pair
using namespace std;


string Get_Key(string s, int k)
{
	char *ptr = strtok((char*)s.c_str()," ");

	while(k>1)
	{
		ptr=strtok(NULL," ");
		k--;
	}

	return (string) ptr;
}


int convert2int(string Str)
{
	int sum=0;
	for(int i=Str.length()-1, t=1; i>=0; i++, t*=10)
		sum+=(Str[i]-'0')*t;
	return sum;
}


bool lexi_cmp(pair<string,string> a, pair<string,string> b) 
{	
	return b.second>a.second;
}


bool num_cmp(pair<string,string> a, pair<string,string> b) 
{	
	return convert2int(b.second)>convert2int(a.second);
}


int main()
{
	int i, n, key;
	bool reversed;
	cin>>n;
	cin.get();

	string cmp_type, *str = new string[n];

	for(i=0; i<n; i++)
		getline(cin,str[i]);

	cin>>key>>reversed>>cmp_type;


	const int N=n;

	pair<string,string> S[N];
	for(i=0; i<n; i++)
	{
		S[i].first=str[i];
		S[i].second=Get_Key(str[i],key);
	}


	if(!cmp_type.compare("numeric"))
		sort(S,S+n,num_cmp);

	else if(!cmp_type.compare("lexicographical"))
		sort(S,S+n,lexi_cmp);


	if(reversed)
		for(i=0; i<n/2; i++)
			swap(S[i],S[n-1-i]);


	for(i=0; i<n; i++)
		cout<<S[i].first<<endl;

	delete[] str;
	return 0;
}