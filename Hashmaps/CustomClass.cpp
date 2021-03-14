#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
//use custom class as key instead of string
//key is student class and value is marks


class student
{
	public:
	string f, l, r;		//key is first name, last name and roll no.

	student(string f, string l, string r)
	{
		this->f=f;
		this->l=l;
		this->r=r;
	}


	bool operator==(const student &s) const
	{
		return r==s.r;
	}
};


class HashFn
{
	public:

	size_t operator()(const student &s) const		//size_t is unsigned int
	{
		return s.f.length() + s.l.length();
	}
};


int main()
{
	unordered_map<student,int,HashFn> student_map;

	student s1("Prateek","Narang","010");
	student s2("Rahul","Kumar","023");
	student s3("Prateek","Gupta","030");

	student s4("Rahul","Kumar","120");
	student_map[s1]=100;		//direct access operator
	student_map[s2]=120;
	student_map[s3]=11;
	student_map[s4]=45;

	cout<<student_map[s2]<<endl;

	for(auto p:student_map)
		cout<<p.first.r<<" "<<p.first.f<<" "<<p.first.l<<" : "<<p.second<<endl;

	return 0;
}

