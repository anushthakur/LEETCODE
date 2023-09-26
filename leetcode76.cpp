//76. Minimum Window Substring
//IMP*****************

//codestorywithMIK
#include<iostream>
#include<string>
#include<unordered_map>
#include<limits.h>
using namespace std;
class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        int n=s.length();

       //edge case
        if(t.length()>n) return "";

        //storing
        unordered_map <char,int> mp;

        for(const auto& x:t)
        {
            mp[x]++;
        }
        int reqCount=t.length();
        int start_i=0;
        int minWindowSize=INT_MAX;
        int i=0,j=0;

        while(j<n)
        {
            if(mp[s[j]]>0)
            {
                reqCount--;
            }
                mp[s[j]]--;

                while(reqCount==0) //start shrinking the window
                {
                    int currWindow=j-i+1;
                    if(currWindow<minWindowSize)
                    {
                        minWindowSize=currWindow;
                        start_i=i;
                    }
                    mp[s[i]]++;
                    
                    
                    //matlab vo character chahiye hoga par humne usko window se nikal diya
                    if(mp[s[i]]>0) 
                    {
                        reqCount++;
                    }
                    i++;
                }
            
               j++;
            
        }
        return (minWindowSize==INT_MAX)?"":s.substr(start_i,minWindowSize);
    }
};

/*
//trial (WRONG)
class Solution 
{
public:
    int ans=INT_MAX;    
   string result;
    string minWindow(string s, string t) 
    {
        unordered_map <char,int> mp;
        for(int i=0;i<t.length();i++)
        {
            mp[t[i]]++;
        }
        int count=0;

        int i=0;
        int j=0;
        bool flag=false;
        while(j<s.length())
        {
            if(mp.empty()==true)
            {
                i=j;
                for(int i=0;i<t.length();i++)
                {
                     mp[t[i]]++;
                }
                count=j;
                if(count<ans)
                {
                    ans=count;
                     string res;
                    for(int k=i;k<=ans-i;k++)
                    {
                    res.push_back(s[k]);
                    }
                    result=res;
                }
                //ans=min(count,ans);
                
                
                count=0;
                flag=true;
            }

            if(mp.find(s[j])!=mp.end())
            {
                if(flag==true)
                {
                    i=j;
                    flag=false;
                } 

                mp.erase(t[j]);
                j++;
                count++;
            }
            else 
            {
                if(count !=0)
                {
                     j++;
                     count++;
                }

            }
           
            
        }

        return result;
    }
};
*/