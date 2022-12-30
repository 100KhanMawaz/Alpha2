#include<bits/stdc++.h>
using namespace std;
bool isSafe(int x,int row,int col,vector<vector<int>> &board)
{
for(int i=0;i<9;i++)
{
   if(board[i][col]==x)
   return false;

   if(board[row][i]==x)
   return false;

   if(board[3*(row/3) + i/3][3*(col/3) + i%3]==x)
    return false;
}
   return true;
}
bool SudokuSolver(vector<vector<int>> &board,int row,int col)
{
    if(row==9)
    {
        return true;
    }
    int nextRow=row,nextCol=col+1;
    if(col+1==9)
    {
        nextRow=row+1;
        nextCol=0;
    }
 if(board[row][col]!=0)
     return SudokuSolver(board,nextRow,nextCol);
    
        for(int i=1;i<=9;i++)
        {
            if(isSafe(i,row,col,board))
            {
            board[row][col]=i;
            if(SudokuSolver(board,nextRow,nextCol)==true)
                return true;
                //False hua ab uu number ko wapas zero karo usme dusra number daala jayega qki loop abhi khatam ni hua hai or agar khatm ho bhi gaya hai to firse last mein false return hoga and then usse pehle waala check hoga
               board[row][col]=0;
            }
        }
        //pura loop khatam ho gaya kahi nai mila safe wala to false return kro
        return false;
    
    
}
int main()
{
    vector<vector<int>> board
    {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
    };
   vector<vector<int>> ans;
   if(SudokuSolver(board,0,0)){
   for(int i=0;i<9;i++)
   {
    for(int j=0;j<9;j++)
    {
        cout<<board[i][j]<<",";
    }
    cout<<endl;
   }
   }
   else
   cout<<"No Solution exists";
    return 0;
}