//316. Remove Duplicate Letters
#include<bits/stdc++.h>
using namespace std;

//codestorywithMIK
class Solution 
{
public:
    //we have indirectly been using monotonicstack using string
    string removeDuplicateLetters(string s) 
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



/*
class Solution 
{
public:
    //wrong trial because you didn't understand the ques. correctly. 
        //Input: s = "cbacdcbc"
        //Output: "acdb" and not "abcd"
        //that is appearance ka order change nhi karna hai***
    
    string removeDuplicateLetters(string s) 
    {
        vector<bool>v(26,false);
        for(int i=0;i<s.length();i++)
        {
            v[s[i]-'a']=true;
        }
        string ans;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==true)
            {
                char x= i + 'a';
                ans+=x;
            }
        }
        return ans;
    }
};
*/
