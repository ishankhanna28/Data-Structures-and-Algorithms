#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
using namespace std;


int main()
{
	unordered_map<string, vector<string>> phonebook;

	phonebook["rahul"].push_back("9110");
	phonebook["rahul"].push_back("9112");
	phonebook["rahul"].push_back("9113");
	phonebook["rahul"].push_back("9114");

	phonebook["kajal"].push_back("8112");
	phonebook["kajal"].push_back("8113");
	phonebook["kajal"].push_back("8114");


	for(auto p:phonebook)
	{
		cout<<p.first<<" -> ";

		for(auto s:phonebook[p.first])
			cout<<s<<", ";

		cout<<endl;
	}

	return 0;
}