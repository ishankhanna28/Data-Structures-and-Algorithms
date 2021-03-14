#include<iostream>
#include<algorithm>
using namespace std;

//WAP which will input a sum of money in INR and print the no. of coins/notes of each denomination which are required 
//to pay that sum using least no. of coins/notes.

int main()
{			 //0, 1, 2,  3,  4,  5,   6,   7,   8,    9
	int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int cash, ub, n=sizeof(a)/sizeof(int), i;
	int b[10] = {0};
	cout<<"How much money do you have to pay"<<endl;
	cin>>cash; //168

	/*
	Find in array the largest no. <= 168
	168 - 100 = 68
	68 - 50 = 18
	18 - 10 = 8
	8 - 5 = 3
	3 - 2 = 1
	1 - 1 =0
	*/

	while(cash)
	{
		ub = upper_bound(a,a+n,cash) - a -1;	//return index of first element >= cash
		b[ub]++;
		cash-= a[ub];
	}

	cout<<endl<<"The way in which the given sum can be payed using least items of curreny is using..."<<endl;

	for(i=0; i<n; i++)
	{
		if(b[i]==1)
		{
			if(a[i]<=2)
				cout<<"1 coin of Rs."<<a[i]<<endl;
			else if(a[i]<=10)
				cout<<"1 note/coin of Rs."<<a[i]<<endl;
			else
				cout<<"1 note of Rs."<<a[i]<<endl;
		}

		else if(b[i])
		{
			if(a[i]<=2)
				cout<<b[i]<<" coins of Rs."<<a[i]<<endl;
			else if(a[i]<=10)
				cout<<b[i]<<" notes/coins of Rs."<<a[i]<<endl;
			else
				cout<<b[i]<<" notes of Rs."<<a[i]<<endl;
		}
	}	

	return 0;
}