#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main()
{
	map<string,int> m;
	m.insert(make_pair("pizza",150));
	m["burger"]=85;

	string str="burger";
	auto it = m.find(str);		//map<string,int>::iterator is auto

	m["burger"]+= 10;

	if(it==m.end())
		cout<<"Not present"<<endl;

	else
		cout<<it->second<<endl;

	m.erase(str);

	if(m.count(str))	//returns 0 or 1 integer not pointer/iterator like find
		cout<<"present"<<endl;
	else
		cout<<"absent"<<endl;

	cout<<endl;
	m["vada"]=200;
	m["dosa"]=250;
	m["idli"]=300;

	for(auto it=m.begin(); it!=m.end(); it++)
		cout<<it->first<<" "<<it->second<<endl;

	cout<<endl;

	for(auto p:m)		//auto is pair<string,int> or key-value pair
		cout<<p.first<<" : "<<p.second<<endl;

	//since it is ordered map, output keys will be lexiographically sorted
	//nodes are stored in a self-ballnaced BST
	return 0;

}