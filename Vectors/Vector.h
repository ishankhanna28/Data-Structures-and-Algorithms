#include<iostream>
using namespace std;

template<typename t>
class Vector
{
	public:
	int n=0, N=0;
	t *a;

	void Push_Back(const t data)
	{
		if(!N)
		{
			a = new t;
			*a = data;
			n++;
			N++;
		}


		else if(n==N)
		{
			t *old_arr = a;
			a = (t*)realloc(a, N*2*sizeof(t));

			for(int i=0; i<N; i++)
				a[i] = old_arr[i];

			N*=2;
			a[n++]=data;
			delete[] old_arr;
		}

		else
		{
			a[n++] = data;
		}
	}


	void Pop_Back()
	{
		a[--n] = 0;
	}


	void Reserve(const int num)
	{
		if(N!=num)
		{
			a= new t[N];
		}

		N=num;
	}


	void Resize(const int num)
	{
		if(N<num)
		{
			t *old_arr = a;
			a = (t*)realloc(a, num*sizeof(t));

			for(int i=0; i<N; i++)
				a[i] = old_arr[i];

			N=num;
			delete[] old_arr;
		}

		if(N>num)
		{
			for(int i=num; i<N; i++)
				a[i]=0;
		}

		n=num;
	}

	int Siz() const 
	{
		return n;
	}

	int Capacity() const 
	{
		return N;
	}

	bool Empty() const 
	{
		return n==0;
	}

	t Front() const 
	{
		return a[0];
	}

	t Back() const 
	{
		return a[n-1];
	}

	t* Begin() const 
	{
		return a;
	}

	t* End() const 
	{
		return a+n;
	}

	t operator[](int i)
	{
		cout<<"hi "<<endl;
		return a[i];
	}
};