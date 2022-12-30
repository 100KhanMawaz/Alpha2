#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &ans,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"------ChessBoard-----"<<endl;
}
void RatInAMaze(vector<vector<int>> &maze,vector<vector<int>> &visited,int row,int col,vector<vector<int>> &ans,int n)
{
    if(row==(n-1) && col==(n-1))
    {
        print(ans,n);
        return;
    }
    //DOWN
    if((row+1)<n && !visited[row+1][col] && maze[row+1][col]==1)
    {
        visited[row+1][col]=1;
        ans[row+1][col]=1;
        RatInAMaze(maze,visited,row+1,col,ans,n);
        ans[row+1][col]=0;
        visited[row+1][col]=0;
    }
    //LEFT
   if((col-1)>=0 && !visited[row][col-1] && maze[row][col-1]==1)
    {
        visited[row][col-1]=1;
        ans[row][col-1]=1;
        RatInAMaze(maze,visited,row,col-1,ans,n);
        ans[row][col-1]=0;
        visited[row][col-1]=0;
    }
    //RIGHT
    if((col+1)<n && !visited[row][col+1] && maze[row][col+1]==1)
    {
        visited[row][col+1]=1;
        ans[row][col+1]=1;
        RatInAMaze(maze,visited,row,col+1,ans,n);
        ans[row][col+1]=0;
        visited[row][col+1]=0;
    }
    //UP
    if((row-1)>=0 && !visited[row-1][col] && maze[row-1][col]==1)
    {
        visited[row-1][col]=1;
        ans[row-1][col]=1;
        RatInAMaze(maze,visited,row-1,col,ans,n);
        ans[row-1][col]=0;
        visited[row-1][col]=0;
    }
}
int main()
{
    int n=4;
    vector<vector<int>> visited (n,vector<int>(n,0));
    //  {
    //  { 0, 0, 0, 0 },
    //  { 0, 0, 0, 0 },
    //  { 0, 0, 0, 0 },
    //  { 0, 0, 0, 0 }
    //   };

    vector<vector<int>> ans(n,vector<int>(n,0));
    //  {
    //  { 0, 0, 0, 0 },
    //  { 0, 0, 0, 0 },
    //  { 0, 0, 0, 0 },
    //  { 0, 0, 0, 0 }
    //   };
   
    vector<vector<int>> maze
     {
     { 1, 0, 0, 0 },
     { 1, 1, 0, 1 },
     { 1, 1, 0, 0 },
     { 1, 1, 1, 1 }
      };

      if(maze[0][0]==1){
          ans[0][0]=1;
        RatInAMaze(maze,visited,0,0,ans,4);
      }
    else
        cout<<"No Routes Exist"<<endl;
     // print(ans,4);
    return 0;
}