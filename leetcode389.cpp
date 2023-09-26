//389. Find the Difference

#include<bits/stdc++.h>
using namespace std;
//trial
class Solution 
{
public:
    char findTheDifference(string s, string t) 
    {
        if(s.length()==0) return t[0];
        unordered_map <char,int> mp;
        for(int i=0;i<t.length();i++)
        {
            mp[t[i]]++;
        }
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]--;
        }
        char ans;
        for(const auto& x:mp)
        {
            if(x.second>0) ans= x.first;
          
        }
        return ans;
    }
};


class Solution 
{
public:
//trial bit manipulation
    char findTheDifference(string s, string t) 
    {
        int a=0;
        for(int i=0;i<s.length();i++)
        {
            a+=s[i];
        }
        int b=0;
        for(int i=0;i<t.length();i++)
        {
            b+=t[i];
        }
        return b-a; //difference gives extra character
    }
};


class Solution 
{
public:
    //trail using sorting
    char findTheDifference(string s, string t) 
    {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<s.length();i++)
        {
            if(t[i]!=s[i]) return t[i];
        }
        return t[t.length()-1];
    }
};