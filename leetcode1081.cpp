//1081. Smallest Subsequence of Distinct Characters

//codestorywithMIK
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    //we have indirectly been using monotonicstack using string
    string smallestSubsequence(string s) 
    {
        vector <bool> takenInAns(26,false);
        vector <int> lastindexofoccurrence(26);

        for(int i=0;i<s.length();i++)
        {
            lastindexofoccurrence[s[i]-'a']=i;
        }
        string ans;
        for(int i=0;i<s.length();i++)
        {
            if(takenInAns[s[i]-'a']==true) continue;

            //jab le rhe hain tab
            while(ans.length()!=0 && ans.back()>s[i] && lastindexofoccurrence[ans.back()-'a']>i )
            {
               
                takenInAns[ans.back()-'a']=false;
                 ans.pop_back();
            }

            takenInAns[s[i]-'a']=true;
            ans.push_back(s[i]);
            
        }
        return ans;
    }
};