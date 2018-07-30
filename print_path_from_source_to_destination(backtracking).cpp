#include <bits/stdc++.h>
using namespace std;
#define N 5
void print(int sol[][N]){
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool solveMazeUtil(char maze[][N],int x, int y, int sol[][N]){
    if(maze[x][y]=='e'){
        sol[x][y]=1;
        return true;
    }
    if(maze[x][y]=='1')
    {
        sol[x][y]=0;
        return false;
    }
    sol[x][y]=1;
    if(x+1<N && sol[x+1][y]==0){
        sol[x+1][y]=1;
        if(solveMazeUtil(maze,x+1,y,sol))
        return true;
    }
    if(y+1<N && sol[x][y+1]==0){
        sol[x][y+1]=1;
        if(solveMazeUtil(maze,x,y+1,sol))
        return true;
    }
    if(y-1>=0 && sol[x][y-1]==0){
        sol[x][y-1]=1;
        if(solveMazeUtil(maze,x,y-1,sol))
        return true;
    }
    if(x-1>=0 && sol[x-1][y]==0){
        sol[x-1][y]=1;
        if(solveMazeUtil(maze,x-1,y,sol))
        return true;
    }
    sol[x][y]=0;
    return false;
}
void  solveMaze(char maze[][N],int x,int y){
    int sol[N][N]={
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    if(solveMazeUtil(maze,x,y,sol)==false){
        cout<<"SORRY NO SOLUTIONS"<<endl;
    }
    else{
        print(sol);
        cout<<endl;
    }
}

int main() {
	char maze[N][N]={
	    {'1','1','0','0','0'},
	    {'0','0','0','1','0'},
	    {'1','0','1','e','0'},
	    {'0','0','0','1','1'},
	    {'r','1','0','0','1'}
	};
	int p,q,f=0;
	for(int i=0;i<N;i++){
	    for(int j=0;j<N;j++){
	        if(maze[i][j]=='r'){
	            p=i;
	            q=j;
	            f=1;
	            break;
	        }
	    }
	    if(f==1)
	    break;
	}
	solveMaze(maze,p,q);
	return 0;
}