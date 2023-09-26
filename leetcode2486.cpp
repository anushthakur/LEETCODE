//2486. Append Characters to String to Make Subsequence

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    
    int appendCharacters(string s, string t) 
    {
             int m=s.length();
             int n=t.length();

             int i=0;
             int j=0;

             while(i<m && j<n)
             {
                 if(s[i]==t[j])
                 {
                     j++;
                 }
                 i++;
             }
             return n-j;
    }
};

/*
class Solution 
{
public:
    //trial
    int appendCharacters(string s, string t) 
    {
        vector <char> v;
        for(int i=0;i<t.length();i++)
        {
            v.push_back(t[i]);
        }
        int j=0;
        for(int i=0;i<s.length() && j<t.length();i++)
        {
            if(v[j]==s[i])
            {
                j++;
            }
        }
        if(j==t.length()) return 0;
        else return t.length()-j;
    }
};
*/

/*
class Solution 
{
public://TRIAL (SOLVING TRIAL LIKE 792) //wrong,somewhere some mistake???
    int appendCharacters(string s, string t) 
    {
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]].push_back(i);
        }
        int lastindex=-1;
        int countcharacters=0;
        
        for(int i=0;i<t.length();i++)
        {   
            bool flag=true;
            for(int j=0;j<s.length();j++)
            {
                vector<int>::iterator it=upper_bound(mp[j].begin(),mp[j].end(),lastindex);
                if(it==mp[j].end())
                {
                    flag=false;
                    break;
                }
                countcharacters++;

            }
            if(flag==false) break;
        }
        return t.length()-countcharacters;
    }
};
*/