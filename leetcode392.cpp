//392. Is Subsequence


#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    //trial
    bool isSubsequence(string s, string t) 
    {
        int n=s.length();
        int count=0;
        int lastindex=-1;

        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<t.length();j++)
            {
                if(s[i]==t[j] && j>lastindex)
                {
                    count++;
                    lastindex=j;
                     break;
                } 
               
            }
        }
        if(count==n) return true;
        else return false;
    }
};