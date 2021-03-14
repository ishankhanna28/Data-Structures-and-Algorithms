#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compare(string a, string b)
{
	return a>b;
}


bool cmp(string a, string b)
{	
	if(a.length()==b.length())
		return b>a;			//If string lengths are equal they will be printed in lexiographic order.
	else
		return b.length()>a.length();
}


int main()
{
	int N, i;
	cout<<"How many strings would you like to enter ?"<<endl;
	cin>>N;
	cin.get();

	string *s = new string[N];
	for(i=0; i<N; i++)
	{	
		cout<<endl<<"Input string #"<<i+1<<"..."<<endl;
		getline(cin,s[i]);
	}

	sort(s, s+N, compare); 
	cout<<endl<<"Strings in descending lexiographic (opposite of dictionary) order are..."<<endl;
	for(i=0; i<N; i++)
		cout<<s[i]<<endl;

	sort(s, s+N, cmp); 
	cout<<endl<<"Strings in ascending order of their no. of characters..."<<endl;
	for(i=0; i<N; i++)
		cout<<s[i]<<endl;

	delete[] s;
	return 0;
}
