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
	static int count;	//In OOPs Initialization is not possible. Have to declare and assign in separate steps.
	int model_no;
	float price;
	const float msp;	//minnimum selling price.


public:

	char *name;

	CAR() : msp(100)
	{
		cout<<"Object No. "<<++count<<endl;
		name = NULL;
	}


	CAR(int m, float p, char n[]) : msp(100), model_no(1001)	//initialization list
	{
		cout<<"Object No. "<<++count<<endl;
		model_no=m;

		if(p>msp)
			price = p;

		else
			price = msp;

		name = new char[strlen(n)+1];
		strcpy(name, n);
	}


	CAR(CAR &c)	: msp(c.msp) //arguement of copy constructor is always passed by reference.
	{
		cout<<"Object No. "<<++count<<endl;
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


	void DispData()	const 	//This is a constant function. i.e. Value of all data members remains constant.
	{
		cout<<endl<<"Car Name = "<<name<<endl;
		cout<<"Model no. = "<<model_no<<endl;
		cout<<"Price = "<<price<<endl;
	}


	void SetPrice(const int p)	//p is a constant parameter. i.e it's value is not changed in the function.
	{
		if(p>msp)
			price = p;

		else
			price = msp;
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

int CAR::count = 0;


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
//	delete[] E;

	return 0;
}