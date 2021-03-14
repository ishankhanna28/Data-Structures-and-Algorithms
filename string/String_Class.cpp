#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
	string str, s2;
	string s1("Hello");
	s2=s1;
	s2.append(" World"); 
	cout<<s1<<endl;
	cout<<s2<<endl;

	s1.clear();
	if(s1.empty())
		cout<<"S1 is an empty string"<<endl;

	s1=s2;
	if(!s1.compare(s2)) //if(s1.compare(s2)==0)
		cout<<"Strings match"<<endl;

	str = "I love dynamic programming";
	char a[] = {'d','y','n','a','m','i','c','\0'};
	string word(a);
	str.erase(str.find(word), word.length()+1);
	cout<<str<<endl;

	s1 = "Man";
	s2 = "Orange";

	s1+="go";

	if(s1>s2)
		cout<<s1<<" is lexiographically greater than "<<s2<<endl;
	else
		cout<<s2<<"is lexiographically greater than "<<s1<<endl;

	string s;
	getline(cin,s);
	for(string::iterator it=s.begin(); it!=s.end(); it++)
		cout<<*it<<", ";
	cout<<endl;
	//'string::iterator' above and 'char' below may be replaced with 'auto'

	for(char ch:word)
		cout<<ch<<", ";
	cout<<endl;




	return 0;
}