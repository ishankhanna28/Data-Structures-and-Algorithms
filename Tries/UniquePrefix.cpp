#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

class node
{
	public:
	char ch;
	int freq;
	bool terminal;
	unordered_map<char,node*> next;

	node(char ch='\0', bool terminal=false, int freq=0)
	{
		this->ch=ch;
		this->terminal=terminal;
		this->freq=freq;
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
		cnt=1;
	}


	void Insert(string s)		//O(1)
	{
		node* temp=root;

		for(int i=0; s[i]!='\0'; i++)
		{
			char ch=s[i];
			temp->freq++;

			if(temp->next.count(ch)==0)
				temp->next[ch]=new node(ch);

			temp=temp->next[ch];
		}

		temp->freq++;
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


	string PrintUnq(string s)
	{
		int i=0;
		node* temp=root;

		for(; s[i]!='\0'; i++)
		{
			char ch=s[i];
			temp=temp->next[ch];

			if(temp->freq==1)
				break;
		}

		if(s[i]=='\0')
			return "\0";		

		return s.substr(0,i+1);
	}
};


vector<string> UnqPre(vector<string> v)
{
	Trie t;
	vector<string> ans;
	ans.reserve(v.size());

	for(auto str:v)
		t.Insert(str);

	for(auto s:v)
		ans.push_back(t.PrintUnq(s));

	return ans;
}


int main()
{
	vector<string> v{"cobra", "dog", "dove", "duck", "not", "note"};
	vector<string> ans=UnqPre(v);

	for(auto s:ans)
		cout<<s<<endl;

	return 0;
}

