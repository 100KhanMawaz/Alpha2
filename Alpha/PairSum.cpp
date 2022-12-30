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
vector<vector<int>> PairSum(vector<int> v,int st,int en,int target)
{
    vector<vector<int>> ans;
    vector<int> pair; 
    while(st<en)
    {
        int sum=v[st]+v[en];
        if(sum==target)
        {
            pair.push_back(v[st]);
            pair.push_back(v[en]);
            st++;
            en--;
            ans.push_back(pair);
            pair.clear();
        }
        if(sum<target)
        st++;
        if(sum>target)
        en--;
    }
    return ans;
}
int main()
{
    vector<int> v{1,2,4,5,6};
    int st=0,en=v.size()-1;
    int target=7;
    vector<vector<int>> ans;
    ans=PairSum(v,st,en,target);
    print(ans);
    return 0;
}