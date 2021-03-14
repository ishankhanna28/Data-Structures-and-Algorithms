#include <iostream>
#include <cstring>
#include "hashtable.h"
using namespace std;

int main()
{
	Hashtable<int> menu;

	menu.Insert("Burger", 120);
	menu.Insert("Pepsi", 20);
	menu.Insert("BurgerPizza", 150);
	menu.Insert("Noodles", 25);
	menu.Insert("Coke", 40);

	/*
	int* price=menu.search("Noodle");

	if(price==NULL)
		cout<<"Not Found"<<endl;

	else
		cout<<*price<<endl;
	*/

	menu["Dosa"]=60;			//Insertion
	menu["Dosa"]+=10;			//Update
	cout<<menu["Dosa"]<<endl;	//Get 

	menu.Print();
	return 0;
}