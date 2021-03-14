#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

class node
{
	public:
	char ch;
	bool terminal;
	unordered_map<char,node*> next;

	node(char ch='\0', bool terminal=false)
	{
		this->ch=ch;
		this->terminal=terminal;
	}

};


class Trie
{
	public:
	node* root;
	int cnt;

	Trie()
	{
		root=new node();
		cnt=0;
	}


	void Insert(string s)		//O(1)
	{
		node* temp=root;

		for(int i=0; s[i]!='\0'; i++)
		{
			char ch=s[i];

			if(temp->next.count(ch)==0)
				temp->next[ch]=new node(ch);

			temp=temp->next[ch];
		}

		temp->terminal=true;
		cnt++;
	}


	bool Find(string s)		//O(1)
	{
		node* temp=root;

		for(int i=0; s[i]!='\0'; i++)
		{
			char ch=s[i];

			if(temp->next.count(ch)==0)
				return false;

			temp=temp->next[ch];
		}

		return temp->terminal;
	}
};


int main()
{
	vector<string> v{"yes", "no", "a", "hello", "not", "news", "apple", "ape"};
	string str = "not";
	Trie t;

	for(auto s:v)
		t.Insert(s);

	if(t.Find(str))
		cout<<"Present"<<endl;

	else
		cout<<"Absent"<<endl;

	return 0;
}