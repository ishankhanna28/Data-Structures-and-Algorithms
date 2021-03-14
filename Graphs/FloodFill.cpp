#include <iostream>
#include <vector>
using namespace std;


void FloodFill(vector<vector<char>> &mat, int r, int c, int i, int j, char ch, char color)	//DFS 
{
	if(i<0 or j<0 or i>=r or j>=c)
		return;

	if(mat[i][j]!=ch)
		return;

	mat[i][j]=color;
	int dx[] = {0, 0,-1, 1};
	int dy[] = {-1,1, 0, 0};

	for(int k=0; k<4; k++)
		FloodFill(mat, r, c, i+dx[k], j+dy[k], ch, color);
}


int main()
{
	int r, c;
	cin>>r>>c;
	vector<vector<char>> mat;
    
    mat.reserve(r);
    for(int i=0; i<r; i++)
        mat[i].reserve(c);

	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			cin>>mat[i][j];

	FloodFill(mat, r, c, 3, 4, '.', 'r');
    FloodFill(mat, r, c, 0, 0, '.', '!');

	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}


/*
INPUT:
10 10
. . . # # # . . . . 
. . # . . . # . . . 
. . # . . . . # . . 
. # . . . . . . # . 
. # . . . . . . # . 
. . # . . . . . # . 
. . # . . # . # . . 
. . # . # . # . . . 
. . . # . . . . . . 
. . . . . . . . . . 


OUTPUT:
! ! ! # # # ! ! ! ! 
! ! # r r r # ! ! ! 
! ! # r r r r # ! ! 
! # r r r r r r # ! 
! # r r r r r r # ! 
! ! # r r r r r # ! 
! ! # r r # r # ! ! 
! ! # r # ! # ! ! ! 
! ! ! # ! ! ! ! ! ! 
! ! ! ! ! ! ! ! ! ! 
*/