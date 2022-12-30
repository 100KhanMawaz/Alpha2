/*
Youaregivenanintegerarraylistnums.Anumberxislonelywhenitappearsonlyonce,andno adjacent numbers (i.e. x + 1 and x - 1) appear in the arraylist.Return all lonely numbers in nums. You may return the answer in any order.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> LonelyNumbers2(vector<int> v)
{
    int n=v.size();
    vector<int> ans;
    bool flag=false;
    sort(v.begin(),v.end());
    for(int i=0;i<n-1;i++)
    {
        if((v[i]!=v[i+1] || v[i]!=v[i-1]) && (v[i+1]!=(v[i]+1) || v[i-1]!=(v[i]-1)))
        ans.push_back(v[i]);
    }
    return ans;

}
vector<int> LonelyNumbers(vector<int> v)
{
    //Brute Force Solution o(N^2) Working Alhamdulillah;
    int n=v.size();
    vector<int> ans;
    bool flag=true;
    for(int i=1;i<n;i++)
    {
        flag=true;
        for(int j=0;j<n;j++)
        {
            if(i==j)
            continue;
            if(v[i]==v[j] || (v[i]-1)==v[j] || (v[i]+1)==v[j])
            flag=false;      
        }
        if(flag)
        ans.push_back(v[i]);
    }
    return ans;
}
int main()
{
    vector<int> v{10,6,5,8};
    vector<int> ans;
   // ans=LonelyNumbers(v);
    ans=LonelyNumbers2(v);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<endl;
    return 0;
}