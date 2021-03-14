#include<iostream>
using namespace std;
int R, C;

void Spiral_Print(int **A, int M, int N)
{
	int SR=0, SC=0, ER=M-1, EC=N-1;

	while(SR<=ER && SC<=EC)
	{
		for(C=SC; C<=EC; C++)
			cout<<A[SR][C]<<" ";
		SR++;

		for(R=SR; R<=ER; R++)
			cout<<A[R][EC]<<" ";
		EC--;

		if(ER>SR) 
		{
			for(C=EC; C>=SC; C--)
				cout<<A[ER][C]<<" ";
			ER--;
		}

		if(EC>SC)
		{
			for(R=ER; R>=SR; R--)
				cout<<A[R][SC]<<" ";
			SC++;
		}
	}
}


int main()
{
	int m, n;
	cout<<"How many rows do you want in the matrix?"<<endl;
	cin>>m;
	cout<<"How many columns do you want in the matrix?"<<endl;
	cin>>n;

	int **A = new int*[m];
	for(R=0; R<m; R++)
		A[R] = new int[n];

	cout<<endl<<"Input matrix elements...";
	for(R=0; R<m; R++)
	{cout<<endl<<R+1<<"th ROW. Input "<<n<<" integers..."<<endl;
		for(C=0; C<n; C++)
			cin>>A[R][C];
	}
	Spiral_Print(A,m,n);

	for(R=0; R<m; R++)
		delete[] A[R];
	delete[] A;
	return 0;
}
