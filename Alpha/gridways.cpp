#include<bits/stdc++.h>
using namespace std;
int gridways(int i,int j,int row,int col)
{
    if(i==row-1 && j==col-1)
    {
        return 1;
    }
    if(i>=row || j>=col)
    {
        return 0;
    }
    return gridways(i+1,j,row,col)+gridways(i,j+1,row,col);
}
int main()
{
    cout<<"Number of ways is "<<gridways(0,0,1,1)<<endl;
    return 0;
}