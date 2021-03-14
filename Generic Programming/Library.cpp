#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


class BOOK
{
	string name;
	int price;

public:

	BOOK(string name, int price)
	{
		this->name = name;
		this->price = price;
	}

	string GetName()
	{
		return name;
	}

	int GetPrice()
	{
		return price;
	}
};


class Compare
{
public:

	bool operator()(BOOK a, BOOK b)	//Functional Operator (Functor)
	{
		return (GetName(a)==GetName(b));
	}
};


template<class ite, class t, class b>
ite LinearSearch(ite beg, ite end, t key, b cmp)
{
	for(auto it=beg; it!=end; it++)
		if(cmp(*it, key))
			return it;

	return end;
}


int main()
{
	BOOK b1("C", 100), b2("C#", 110), b3("C++", 120), b4("JAVA", 130), b5("PYTHON", 140), b6(b4), b7("C++", 150);
	vector<BOOK> v;
	v.push_back(b1);
	v.push_back(b2);
	v.push_back(b3);
	v.push_back(b4);
	v.push_back(b5);
	v.push_back(b6);

	Compare C;
	auto it=LinearSearch(v.begin(), v.end(), b7, C);

	if(it==v.end())
		cout<<"-1"<<endl;

	else 
		cout<<it-v.begin()<<endl;

	return 0;
}