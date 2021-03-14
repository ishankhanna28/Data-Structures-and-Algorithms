#include<iostream>
#include<cstdlib>
#include<math.h>
#include <utility>
using namespace std;

pair<float,float> random_point()	//Returns co-orinates of a random point from 0 to 1
{
	pair<float,float> p;
	p.first= static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	p.second=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	return p;
}


int check_circ(pair <float,float> p)	//Returns 1 if pt. lies in circle else returns 0
{
	if(sqrt(pow(p.first,2) + pow(p.second,2)) < 1) 
		return 1;
	else
		return 0;
}


float Calc_Pi(int N)
{
	int i, count=0;

	for(i=1; i<=N; i++)
		if(check_circ(random_point()))
			count++;

	return ((float)count/(float)N)*4.0;
}


int main()
{
	int n;
	do
	{
		cout<<endl<<"Enter no. of Pts. to be generated(to exit input 0)..."<<endl;
		cin>>n;
		cout<<"Aprox. value of Pi = "<<Calc_Pi(n)<<endl;
	}while(n);

	return 0;
}
