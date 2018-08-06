// A Backtracking program in C++ to solve Sudoku problem
#include <stdio.h>
#include<iostream>
using namespace std;
#define N 9

void printGrid(int grid[N][N])
{
	for (int row = 0; row < N; row++)
	{
	for (int col = 0; col < N; col++)
			printf("%2d", grid[row][col]);
		printf("\n");
	}
}
bool anyUnassignValue(int grid[][N], int &row, int &col){
    for(row=0;row<N;row++){
        for(col=0;col<N;col++){
            if(grid[row][col]==0){
                return true;
            }
        }
    }
    return false;
}
bool usedInRow(int grid[][N], int row, int num){
    for(int col=0;col<N;col++)
    {
        if(grid[row][col]==num)
        return true;
    }
    return false;
}
bool usedInCol(int grid[][N], int col, int num){
    for(int row=0;row<N;row++)
    {
        if(grid[row][col]==num)
        return true;
    }
    return false;
}
bool usedInBox(int grid[][N], int bsrow, int bscol, int num){
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++){
            if(grid[row+bsrow][col+bscol]==num)
            return true;
        }
    }
    return false;
}
bool isSafe(int grid[][N], int row, int col, int num){
    return !usedInRow(grid,row,num) && !usedInCol(grid,col,num) &&
    !usedInBox(grid,row-row%3,col-col%3,num);
}
bool SolveSudoku(int grid[][N]){
    int row, col;
    if(!anyUnassignValue(grid,row,col))
    return true;
    for(int num=1;num<=9;num++){
        if(isSafe(grid, row, col, num)){
            grid[row][col]=num;
            if(SolveSudoku(grid))
            return true;
            grid[row][col]=0;
        }
    }
    return false;
    
}
int main()
{
	// 0 means unassigned cells
	int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
					{5, 2, 0, 0, 0, 0, 0, 0, 0},
					{0, 8, 7, 0, 0, 0, 0, 3, 1},
					{0, 0, 3, 0, 1, 0, 0, 8, 0},
					{9, 0, 0, 8, 6, 3, 0, 0, 5},
					{0, 5, 0, 0, 9, 0, 6, 0, 0},
					{1, 3, 0, 0, 0, 0, 2, 5, 0},
					{0, 0, 0, 0, 0, 0, 0, 7, 4},
					{0, 0, 5, 2, 0, 6, 3, 0, 0}};
	if (SolveSudoku(grid) == true)
		printGrid(grid);
	else
		cout<<"no solution";

	return 0;
}
