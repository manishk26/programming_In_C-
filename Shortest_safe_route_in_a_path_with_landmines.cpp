#include<bits/stdc++.h>
using namespace std;
#define R 12
#define C 10
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };
bool isValid(int i, int j){
    return (i<R && i>=0 && j<C && j>=0);
}
bool isSafe(int mat[][C],int visited[][C], int x, int y){
    if(mat[x][y]==0 || visited[x][y])
    return false;
    return true;
}
void markUnsafe(int mat[][C]){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(mat[i][j]==0){
                for(int k=0;k<4;k++){
                    if(isValid(i+rowNum[k],j+colNum[k]))
                    mat[i+rowNum[k]][j+colNum[k]]=-1;
                }
            }
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(mat[i][j]==-1)
            mat[i][j]=0;
        }
    }
}
void findShortestPathUtil(int mat[][C],int visited[][C],int i,int j,int  &minD,int dist){
    if(j==C-1){
        minD=min(minD,dist);
        return;
    }
    if(dist>minD)
    return;
    visited[i][j]=1;
    for(int k=0;k<4;k++){
        if(isValid(i+rowNum[k],j+colNum[k]) && isSafe(mat,visited,i+rowNum[k],j+colNum[k])){
            findShortestPathUtil(mat,visited,i+rowNum[k],j+colNum[k],minD,dist+1);
        }
    }
    visited[i][j]=0;
}

void findShortestPath(int mat[][C]){
    int visited[R][C];
                memset(visited,0,sizeof(visited));
    int min=INT_MAX;
    markUnsafe(mat);
    for(int i=0;i<R;i++){
        if(mat[i][0]==1){
            findShortestPathUtil(mat,visited,i,0,min,0);
            if(min==C-1)
            break;
        }
    }
    if(min!=INT_MAX){
        cout<<"min distance= "<<min<<endl;
        //print(visited);
    }
    else{
        cout<<"ther is no path"<<endl;
    }
}
int main()
{
    // input matrix with landmines shown with number 0
    int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
 
    // find shortest path
    findShortestPath(mat);
 
    return 0;
}