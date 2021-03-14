#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class node
{
	public:
	string key;
	T val;
	node<T>* next;

	node(string key="\0", T val=0, node<T>* next=NULL)
	{
		this->key=key;
		this->val=val;
		this->next=next;
	}

	~node()
	{
		if(next!=NULL)
			delete next;
	}
};


template<typename T>
class Hashtable
{
	node<T>** table;
	int cursize;
	int tabsize;


	int hashFn(string key)
	{
		int idx=0, mult=27;

		for(int i=0, p=1; i<key.length(); i++, p=(p*mult)%tabsize)
		{
			idx+= (key[i]*p)%tabsize;
			idx%= tabsize;
		}

		return idx;
	}


	void rehash()	
	{
		node<T>** oldtable=table;
		int oldsize=tabsize;

		tabsize*=2;		//aproximation; should find next highest prime 
		cursize=0;
		table=new node<T>*[tabsize];

		for(int i=0; i<tabsize; i++)
			table[i]=NULL;

		for(int i=0; i<oldsize; i++)
		{
			node<T>* temp=oldtable[i];

			while(temp!=NULL)
			{
				Insert(temp->key, temp->val);
				temp=temp->next;
			}

			if(oldtable[i]!=NULL)
				delete oldtable[i];		//Recursive destructor call
		}
	}

	public:

	Hashtable(int tabsize=7)
	{
		this->tabsize=tabsize;
		cursize=0;
		table=new node<T>*[tabsize];

		for(int i=0; i<tabsize; i++)
			table[i]=NULL;
	}


	void Insert(string key, T val)
	{
		int idx = hashFn(key);
		//Insertion at Head
		node<T>* temp=new node<T>(key, val, table[idx]);
		table[idx]=temp;

		cursize++;
		float lf = (1.0*cursize)/(1.0*tabsize);

		if(lf>0.7)
			rehash();		//O(N)
	}


	void Print()	//O(N)
	{
		for(int i=0; i<tabsize; i++)
		{
			node<T>* temp=table[i];
			cout<<"Bucket "<<i<<" -> ";

			while(temp!=NULL)
			{
				cout<<temp->key<<" "<<temp->val<<" -> ";
				temp=temp->next;
			}

			cout<<endl;
		}
	}


	T* search(string key)
	{
		for(int i=0; i<tabsize; i++)
		{
			node<T>* temp=table[i];

			while(temp!=NULL)
			{
				if(temp->key==key)
					return &temp->val;

				temp=temp->next;
			}
		}

		return NULL;
	}


	void Delete(string key)
	{
		for(int i=0; i<tabsize; i++)
		{
			T garbage;
			node<T>* temp=new node<T>("temp", garbage, table[i]);

			while(temp->next!=NULL)
			{
				if(temp->next->key==key)
				{
					node<T>* del=temp->next;
					
					if(table[i]==del)
						table[i]=table[i]->next;

					temp->next=del->next;
					del->next=NULL;
					delete del;
					return;
				}

				temp=temp->next;
			}
		}
	}


	T& operator[](string key)		//T& indicates call by reference so that no copy is created
	{
		T* f=search(key);

		if(f==NULL)
		{
			T garbage;
			Insert(key,garbage);
			f=search(key);
		}

		return *f;	//returning value bucket
	}

};