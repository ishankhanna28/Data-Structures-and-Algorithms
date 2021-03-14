#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
If even one of the data members is dynamic, we need to overwrite the inbuily copy constructor(shallow copy)
so that we can make deep copy.
*/


class CAR
{
	int model_no;
	float price;

public:

	char *name;

	CAR()
	{
		name = NULL;
	}

	CAR(int m, float p, char n[])
	{
		model_no=m;
		price=p;
		name = new char[strlen(n)+1];
		strcpy(name, n);
	}

	CAR(CAR &c)	//arguement of copy constructor is always passed by reference.
	{
		model_no = c.model_no;
		price = c.price;

		name = new char[strlen(c.name)+1];
		strcpy(name, c.name);
	}

	void operator=(CAR &c)
	{
		model_no = c.model_no;
		price = c.price;

		name = new char[strlen(c.name)+1];
		strcpy(name, c.name);
	}


	void DispData()
	{
		cout<<"Car Name = "<<name<<endl;
		cout<<"Model no. = "<<model_no<<endl;
		cout<<"Price = "<<price<<endl<<endl;
	}

	void SetPrice(int p)
	{
		price = p;
	}

	void SetName(char n[])
	{
		name = new char[80];
		strcpy(name, n);
	}

	~CAR()
	{
		cout<<"Object "<<name<<" Deallocated"<<endl;

	if(name!=NULL)
		delete[] name;
	}
};


int main()
{
	char str[]="BMW";
	char s[]  ="AMW";
	CAR C(1234, 125, str), D=C; //D is calling copy constructor (initialisation happens).
								//i.e. when declaration and assignment take place simultaneously

	CAR *E = new CAR;	
	*E=C;	//Copy Assignment Operator (first declared then assigned value)

	D.SetPrice(150);
	D.name[0]='A';

	(*E).SetPrice(175);
	E->name[0]='C';

	C.DispData();
	D.DispData();
	E->DispData();
	delete[] E;

	return 0;
}