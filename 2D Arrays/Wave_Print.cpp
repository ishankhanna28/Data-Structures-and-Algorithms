#include<iostream>
using namespace std;
int R, C;

void Wave_Print(int **A, int M, int N)
{
//	cout<<endl<<endl<<"The Given Matrix in Wave Order is ..."<<endl;

	for(C=0; C<N; C++)
	{
		if(C%2==0)
		{
			for(R=0; R<M; R++)
				cout<<A[R][C]<<", ";
		}

		else 
		{
			for(R=M-1; R>=0; R--)
				cout<<A[R][C]<<", ";
		}
	}

	cout<<"END";
}


int main()
{
	int m, n;
//	cout<<"How many rows do you want in the matrix?"<<endl;
	cin>>m;
//	cout<<"How many columns do you want in the matrix?"<<endl;
	cin>>n;

	int **A = new int*[m];
	for(R=0; R<m; R++)
		A[R] = new int[n];

//	cout<<endl<<"Input matrix elements...";
	for(R=0; R<m; R++)
	{
//		cout<<endl<<R+1<<"th ROW. Input "<<n<<" integers..."<<endl;
		for(C=0; C<n; C++)
			cin>>A[R][C];
	}
	Wave_Print(A,m,n);

	for(R=0; R<m; R++)
		delete[] A[R];
	delete[] A;
	return 0;
}


/*
Take as input a two-d array. Wave print it column-wise.

Input Format
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints
Both M and N are between 1 to 10.

Output Format
All M * N integers seperated by commas with 'END' wriiten in the end(as shown in example).

Sample Input
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Sample Output
11, 21, 31, 41, 42, 32, 22, 12, 13, 23, 33, 43, 44, 34, 24, 14, END
*/