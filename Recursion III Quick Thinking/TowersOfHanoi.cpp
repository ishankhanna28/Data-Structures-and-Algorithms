#include <iostream>
using namespace std;


void MOVE(int n, char src, char hlp, char dst)
{
	if(!n)
		return;

	MOVE(n-1, src, dst, hlp);
	cout<<"Moving ring "<<n<<" from "<<src<<" to "<<dst<<endl;
	MOVE(n-1, hlp, src, dst);
}


int main()
{
	int N;
	cin>>N;
	MOVE(N, 'A', 'C', 'B');
	return 0;
}