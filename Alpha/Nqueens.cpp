//In Below code we will solve Nqueen by placing queens in column after column matlab ek column mein dalenge fir uske baad wale column mein fir uske baad wale column mein
#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<char>> chess,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"------ChessBoard-----"<<endl;
}
bool isSafe(vector<vector<char>> chess,int row,int col,int n)
{
    //since everytime we are putting element in next row then we have to check only for 3 direction top-left,top,top-right]

    int trow=row;
    int tcol=col;
    
    while(tcol>=0)
    {
        if(chess[trow][tcol]=='Q')
        return false;
        tcol--;
    }

     trow=row;
     tcol=col;
    
    while(tcol>=0 && trow>=0)
    {
        if(chess[trow][tcol]=='Q')
        return false;
        tcol--;
        trow--;
    }

     trow=row;
     tcol=col;
    
    while(tcol>=0 && trow<n)
    {
        if(chess[trow][tcol]=='Q')
        return false;
        tcol--;
        trow++;
    }
return true;
}
void Nqueen(vector<vector<char>> chess,int n,int col){
    if(col==n)
    {
        print(chess,n);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(isSafe(chess,row,col,n))
        {
            chess[row][col]='Q';
            Nqueen(chess,n,col+1);
            chess[row][col]='.';
        }
    }
    
}
void Nqueen2(vector<vector<char>> chess,int n,int col,vector<int> rowHash,vector<int> LeftUpperDiagonalHash,vector<int> LeftLowerDiagonalHash)
{
    if(col==n)
    {
        print(chess,n);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(rowHash[row]==0 && LeftUpperDiagonalHash[(n-1)+(col-row)]==0 && LeftLowerDiagonalHash[row+col]==0)
        {
            rowHash[row]=1;
            LeftUpperDiagonalHash[(n-1)+(col-row)]=1;
            LeftLowerDiagonalHash[row+col]=1;
            chess[row][col]='Q';
            Nqueen2(chess,n,col+1,rowHash,LeftUpperDiagonalHash,LeftLowerDiagonalHash);
            chess[row][col]='.';
            rowHash[row]=0;
            LeftUpperDiagonalHash[(n-1)+(col-row)]=0;
            LeftLowerDiagonalHash[row+col]=0;
        }
    }
    
}
int main()
{
    int n=6;
    vector<vector<char>> chess(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            chess[i].push_back('.');
        }
    }
    vector<int> rowHash(n,0);
    vector<int> LeftUpperDiagonalHash(2*n-1,0);
    vector<int> LeftLowerDiagonalHash(2*n-1,0);
  Nqueen(chess,n,0);
   // Nqueen2(chess,n,0,rowHash,LeftUpperDiagonalHash,LeftLowerDiagonalHash);
    return 0;
}
