#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> ans)
{
    int n=ans.size();
    int innerlength=ans[0].size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<innerlength;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
vector<vector<int>> PairSum2(vector<int> v,int target)
{
    vector<vector<int>> ans;
    vector<int> pair;
    int n=v.size(); 
    int pivot=0;
    //Finding Pivot;
    for(int i=1;i<n;i++)
    {
        if(v[i-1]>v[i])
        {
            pivot=i;
            break;
        }
    }
    int st=pivot;//Starting will be from smallesrt number which is ofcourse number at pivot
    int en=(n+pivot-1)%n;//ending will be just previous element than pivot which is pivot-1; but we wrote (n+pivot-1)%n because end-- hote hote 0 tak pahuchega usko hmlg ko last mein pahuchana hai to (n+pivot-1)%n aise likhenge to wo end mein pahuch jayega or 0 se peehce matlab -1 nai hoga
    while(st!=en)
    {
        int sum=v[st]+v[en];
        if(sum==target)
        {
            pair.push_back(v[st]);
            pair.push_back(v[en]);
            st=(st+1)%n;// this will make the iterator st rotate clockwise
            en=(n+en-1)%n;//this will make the iterator en rotate anit-clockwise
            ans.push_back(pair);
            pair.clear();//pair ko khali bhi karo dalne k baad 
        }
        if(sum<target)
         st=(st+1)%n;// this will make the iterator st rotate clockwise
        if(sum>target)
         en=(n+en-1)%n;//this will make the iterator en rotate anit-clockwise


    }
    return ans;
}
int main()
{
    vector<int> v{11,15,6,8,9,10};
    int target=17;
    vector<vector<int>> ans;
    ans=PairSum2(v,target);
    print(ans);
    return 0;
}