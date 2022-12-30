#include<bits/stdc++.h>
using namespace std;
void KeyCombination(string &n,vector<string> &mapping,int index,string &str,vector<string> &output)
{
    if(index==n.length())
    {
        //jab length digit ke barabar ho jaaye to maximum length kisi combination of keypad characters utna hai ho sakta hai jaise length of the digit is 2 example "23" to isme 2 hi combination of characters aa sakta hai jaise ad,ae,bf,etc...to utna print karo then return maaro
        output.push_back(str);
        return;
    }
    int digit=n[index]-'0';//taking out each digit from givin number
    string StringCorrespondingToNumber=mapping[digit]; //AS the variable name suggest same thing

    // now in above variable we have a string it can be anny string so we will iterate to each character over the string and push it to str
    for(int i=0;i<StringCorrespondingToNumber.length();i++)
    {
        str.push_back(StringCorrespondingToNumber[i]); //push a character of the string in str
        KeyCombination(n,mapping,index+1,str,output);// now incrrase the index so that the character of next digit string get added to str matlb next digit ke corresponding jo string hai uska charachter utha kar str mein daalenge to jasie index badhaenge waise hi dusra string select hoga mapping array se fir uske characters ko push karenge str mein
        str.pop_back();//return hokar yaha aaygea  to last element nikalenge fir usi string mein koi character baaki hoga to usko push karenge agar khatam ho jaye wo string to usse pehle jo element hai usko nikalenge fir uska string mein koi char baaki hoga to usko push karenhge fir recursion and so onn
    }
}
int main()
{
    string str;
    vector<string> output;
    string n="92"; // string is wajah se liye hai qki question on leetcode is in string only and string se thoda asan bhi hai number ko break karna aage se warna sirf number mein peeche se hota hai separate
    if(n.length()==0)
    {
        cout<<"{}"<<endl;
        return 0;
    }
    //here we will 2 mapping as each digits of keypad as indeices of array;
    vector<string> mapping {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    KeyCombination(n,mapping,0,str,output);
    for(int i=0;i<output.size();i++)
    cout<<output[i]<<endl;
    return 0;
}