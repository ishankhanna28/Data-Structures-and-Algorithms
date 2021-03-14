#include <iostream>
#include <vector>
using namespace std;


class node
{
	public:
	node* left;		// 0
	node* right;	// 1

	node(node* left=NULL, node* right=NULL)
	{
		this->left=left;
		this->right=right;
	}
};


class Trie
{
	node* root;
	public:

	Trie()
	{
		root=new node();
	}


	void Insert(int n)		//O(1), since 32 is constt.
	{
		node* temp=root;

		for(int i=31; i>=0; i--)
		{
			int bit = (n>>i)&1;

			if(bit==0)
			{
				if(temp->left==NULL)
					temp->left=new node();

				temp=temp->left;
			}
			
			else
			{
				if(temp->right==NULL)
					temp->right=new node();

				temp=temp->right;
			}
		}
	}


	int CurXor(int n)	//O(1)
	{
		int sum=0;
		node* temp=root;

		for(int i=31; i>=0; i--)
		{
			int bit = (n>>i)&1;

			if(bit==0)
			{
				if(temp->right!=NULL)
				{
					sum+= (1<<i);
					temp=temp->right;
				}

				else 
					temp=temp->left;
			}

			else
			{
				if(temp->left!=NULL)
				{
					sum+= (1<<i);
					temp=temp->left;
				}

				else 
					temp=temp->right;
			}
		}

		return sum;
	}
};


int MaxXor(vector<int> v)	//O(N)
{
	int maxor=0;
	Trie t;

	for(auto x:v)
	{
		t.Insert(x);
		maxor=max(maxor, t.CurXor(x));
	}

	return maxor;
}


int main()
{
	vector<int> v{3, 10, 5, 25, 2, 8};
	cout<<MaxXor(v)<<endl;
	return 0;
}