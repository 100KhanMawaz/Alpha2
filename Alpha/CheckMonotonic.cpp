#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> v)
{
    bool inc=true;
    bool dec=true;
    int n=v.size();
    
        for(int i=1;i<n;i++)
        {
            //in this array we will check that if the given array's element are in ascending order i.e v[i-1]<v[i] throughout the array then true hi rahgea but if the condition is reversed for any 2 elements then it is not incrementing monotonically so make increment(inc) as false
            if(v[i-1]>v[i])
             inc=false;
        }
    
    
        for(int i=1;i<n;i++)
        {
            //in this array we will check that if the given array's element are in descending order i.e v[i-1]>v[i] throughout the array then true hi rahgea but if the condition is reversed for any 2 elements then it is not decrementing monotonically so make decrement(dec) as false
            if(v[i-1]<v[i])
            dec =false;
        }
    
return inc||dec; //Any Function can be ascending or descending or nothing but cannot be both ascending and descending toghether so her if the array is ascending or descending of the value among inc and dec will be 1 and or boolean rule is if any input is 1 then output is 1 so it will return 1 if any on of the inc or dec is 1..next thing is if the function is neither asecing nor descending then for sure it will make both of them 0,0 so in or gate 0,0 ka output 0 hi return jayega
}
int main()
{
    vector<int> v{8,4,5,2,1};
    cout<<check(v)<<endl;
    return 0;
}