#include <iostream>
#include <list>
using namespace std;

//list -> Doubly Linked List
//forward list -> Singly Linked List

int main()
{
	list<string> l{"xiaomi", "oppo", "vivo"};

	l.push_back("redmi");	//Insertion at Tail
	l.push_front("realme");	//Insertion at Head
	
	for(auto x:l)
		cout<<x<<" -> ";

	cout<<endl<<l.back();
	l.pop_back();	//Delete Tail

	cout<<endl<<l.front()<<endl;
	l.pop_front();	//Delete Head

	auto it = l.begin();
	it++;
	l.insert(it, "oneplus");	//Insert at mid

	it++;
	l.insert(it, "oneplus");	

	l.remove("oneplus"); 	//Remove all occurences of element having value as that of arguement.

	l.push_back("samsung");
	l.push_front("asus");

	it=l.begin();
	it++;
	l.erase(it);

	l.sort();
	l.reverse();


	for(auto it=l.begin(); it!=l.end(); it++)
		cout<<*it<<" -> ";

	cout<<endl;
	return 0;
}