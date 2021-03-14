#include <iostream>
#include <vector>
using namespace std;

template<typename t1, typename t2>
class STACK
{
	vector<t1> v1;
	vector<t2> v2;
	public:

	bool isEmpty()
	{
		if(v1.empty())
			return true;

		else
			return false;
	}


	void PUSH(t1 d1, t2 d2)
	{
		v1.push_back(d1);
		v2.push_back(d2);
	}


	void POP()
	{
		v1.pop_back();
		v2.pop_back();
	}


	void DISPLAY()
	{
		for(auto it1=(v1.end()-1), it2=(v2.end()-1); it1!=(v1.begin()-1); it1--, it2--)
			cout<<*it1<<" : "<<*it2<<endl;
	}


	t1 Get_Top1()
	{
		return v1[v1.size()-1];
	}

	t2 Get_Top2()
	{
		return v2[v2.size()-1];
	}

};


int main()
{
	STACK<string, float> S;
	S.PUSH("PocoX2", 17.5);
	S.PUSH("GalaxyS10Lite", 43.0);
	S.PUSH("VivoU10", 10.9);
	S.PUSH("Honor9X", 16.0);
	S.PUSH("RealmeX2Pro", 31.9);

	S.POP();
	S.POP();
	S.DISPLAY();
	return 0;
}
