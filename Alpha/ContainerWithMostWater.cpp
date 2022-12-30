#include<bits/stdc++.h>
using namespace std;
int solve2(vector<int> v)
{
    int leftPointer=0,MaxWater=0;
    int rightPointer=v.size()-1;
    while(leftPointer<rightPointer)
    {
        int height=min(v[leftPointer],v[rightPointer]);//Dono mein se jo kam rahega utna tk hi paani rahega
        int width=rightPointer-leftPointer;//ek height se dusre height tak ka distance
        int currentWaterlevel=width*height;
        MaxWater=max(MaxWater,currentWaterlevel);
        if(v[leftPointer]<v[rightPointer])
        leftPointer++;//Agar left wala height chota hai to saara cheez nikalne ke baad aage dekhenge koi bada height shyd mil jaaye joki zada paani store kar paaye same in else block alos
        else
        rightPointer--;
    }
    return MaxWater;
}
int solve(vector<int> v)
{
    int n=v.size(),ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int waterLevel_height=min(v[i],v[j]);//Dono mein se jo kam rahega utna tk hi paani rahega
            int width=j-i;//ek height se dusre height tak ka distance
            ans=max(waterLevel_height*width,ans);//maximum paani kaha occupy hora hai
        }
    }
        return ans;
}
int main()
{
    vector<int> v{1,8,6,2,5,4,8,3,4};
    cout<<solve(v)<<endl;//Brute force o(n^2);
    cout<<solve2(v)<<endl;//2 pointer approch o(n);
    return 0;
}