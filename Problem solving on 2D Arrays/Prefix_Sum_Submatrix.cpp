#define pii pair<int,int>
#define x first
#define y second

#include<iostream>
using namespace std;
int R,C;


int Sub_Mat(int **A, int m, int n)
{	
	int r, c, i, j, sum=0;
	pii tl, br;

	for(r=0; r<m; r++)
	{
		tl.x=r;

		for(c=0; c<n; c++)
		{
			tl.y=c;

			for(i=r; i<m; i++)
			{	
				br.x=i;

				for(j=c; j<n; j++)
				{
					br.y=j;
					sum+= (A[br.x][br.y] + A[tl.x-1][tl.y-1]) - (A[tl.x-1][br.y] + A[br.x][tl.y-1]);
				}
			}
		}

	}

	return sum;
}


int main()
{
	int M, N;
	cout<<"How many rows do you want in the matrix?"<<endl;
	cin>>M;
	cout<<"How many columns do you want in the matrix?"<<endl;
	cin>>N;
	cout<<endl<<"Input matrix elements...";

	int **a = new int*[M];
	for(R=0; R<M; R++)
		a[M]=new int[N]; 
		

	for(R=0; R<M; R++)
	{
		cout<<endl<<R+1<<"th Row: Input "<<N<<" integers..."<<endl;
		for(C=0; C<N; C++)
			cin>>a[R][C];
	}


	for(R=0; R<M; R++)
		for(C=1; C<N; C++)
			a[R][C]+=a[R][C-1];

	for(C=0; C<N; C++)
		for(R=1; R<M; R++)
			a[R][C]+=a[R-1][C];


	cout<<endl<<endl<<"Total sum of the sum of all submatrices of the given matrix = "<<Sub_Mat(a,M,N);
	for(R=0; R<M; R++)
		delete[] a[R];
	delete[] a;
	return 0;
}
