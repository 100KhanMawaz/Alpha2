//In Below code we solved NQueen with increasing row order mtlb row mein place karke aage badh rhe hai
#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<char>> &chess,int n)
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
bool isSafe(vector<vector<char>> &chess,int row,int col,int n)
{
    //since everytime we are putting element in next row then we have to check only for 3 direction top-left,top,top-right]

    int trow=row;
    int tcol=col;
    while(trow>=0)
    {
        if(chess[trow][tcol]=='Q')
        return false;
        trow--;
    }

     trow=row;
     tcol=col;
    while(trow>=0 && tcol>=0)
    {
        if(chess[trow][tcol]=='Q')
        return false;
        trow--;
        tcol--;
    }

     trow=row;
     tcol=col;
    while(trow>=0 && tcol<n)
    {
        if(chess[trow][tcol]=='Q')
        return false;
        trow--;
        tcol++;
    }
    return true;
}
bool Nqueen(vector<vector<char>> &chess,int n,int row){
    if(row==n)
    {
        print(chess,n);
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(chess,row,i,n))
        {
            chess[row][i]='Q';
            if(Nqueen(chess,n,row+1));
                {
                    return true;
                    //idhar kya hoga baar if staatement check krega or recursive call mein chal jayega and finally jab Nqueen place ho jaygea to row==n ho jayega waha se return true aaygea yaha
                }
            chess[row][i]='.';
        }
    }
    //last tak nai mila tab false;
    return false;
}
void Nqueen2(vector<vector<char>> chess,int n,int row,vector<int> colHash,vector<int> LeftUpperDiagonalHash,vector<int> RightUpperDiagonalHash)
{
    if(row==n)
    {
        print(chess,n);
        return;
    }
    for(int col=0;col<n;col++)
    {
        if(colHash[col]==0 && LeftUpperDiagonalHash[(n-1)+(col-row)]==0 && RightUpperDiagonalHash[row+col]==0)
        {
            colHash[col]=1,
            LeftUpperDiagonalHash[(n-1)+(col-row)]=1,
            RightUpperDiagonalHash[row+col]=1;
            chess[row][col]='Q';
            Nqueen2(chess,n,row+1,colHash,LeftUpperDiagonalHash,RightUpperDiagonalHash);
            chess[row][col]='.';
            colHash[col]=0,
            LeftUpperDiagonalHash[(n-1)+(col-row)]=0,
            RightUpperDiagonalHash[row+col]=0;
        }
    }
}
int main()
{
    int n=4;
    vector<vector<char>> chess(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            chess[i].push_back('.');
        }
    }
    vector<int> colHash(n,0);
    vector<int> LeftUpperDiagonalHash(2*n-1,0);
    vector<int> RightUpperDiagonalHash(2*n-1,0);
   if(Nqueen(chess,n,0))
   print(chess,n);
   // Nqueen2(chess,n,0,colHash,LeftUpperDiagonalHash,RightUpperDiagonalHash);
    return 0;
}
