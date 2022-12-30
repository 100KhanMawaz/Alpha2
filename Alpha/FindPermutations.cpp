#include <bits/stdc++.h>
using namespace std;
void findPermutations(string s,int index,int n,string ans,vector<int> v);
void findPermutations(string s,int index,int n,string ans,vector<int> v){
    if(ans.size()==n)
    {
        cout<<ans<<endl;
        return;
    }
    // since we have n choices that's why loop
  
  for(int i=0;i<n;i++)
  {
    if(v[i]==0)
    {
        //if v[i] is empty then only enter other wise no
        v[i]=1;
        //ghuste sath rasta band kar do ith element k liye
        ans.push_back(s[i]);
        //ye eelement le lenge kam ka hai ye
        findPermutations(s,index+1,n,ans,v);//firse call lagao ek aage wale element k liye
        v[i]=0;// backtracking mein nikalte jayenge
        ans.pop_back();
    }
  }
}
int main() {
  string s="abc";
  vector<int> v(3,0);//This is an hash array
  findPermutations(s,0,3,"",v);
  return 0;
}