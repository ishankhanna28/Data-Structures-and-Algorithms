#define pii pair<int,int>
#define x first
#define y second

#include<iostream>
using namespace std;
int R,C;


int Sum_Mat(int arr[][3], pii TL, pii BR)
{	
	int SUM=0;

	for(R=TL.x; R<=BR.x; R++)
		for(C=TL.y; C<=BR.y; C++)
			SUM+=arr[R][C];

	return SUM;
}


int Sub_Mat(int A[][3], int m, int n)
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
//					cout<<endl<<tl.x<<"/"<<tl.y<<" "<<br.x<<"/"<<br.y<<endl;
					sum+=Sum_Mat(A,tl,br);
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

/*	int **b = new int*[M];
	for(R=0; R<M; R++)
		b[M]=new int[N];*/
	int b[3][3];

	for(R=0; R<M; R++)
	{
		cout<<endl<<R+1<<"th Row: Input "<<N<<" integers..."<<endl;
		for(C=0; C<N; C++)
			cin>>b[R][C];
	}

	cout<<endl<<endl<<"Total sum of the sum of all submatrices of the given matrix = "<<Sub_Mat(b,M,N);
/*	for(R=0; R<M; R++)
		delete[] b[R];
	delete[] b;*/
	return 0;
}
