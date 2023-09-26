//139. Word Break


#include<bits/stdc++.h>
using namespace std;

//codestorywithMIK
class Solution 
{
public:
int n;
unordered_set <string> st;
int t[301];
    bool solve(int idx,string& s)
    {
        //base conditions
        if(t[idx]!=-1) return t[idx];
        if(idx==n)
        {
            return t[idx]=true;
        }
        if(st.find(s)!=st.end())
        {
            return t[idx]=true;
        }

        for(int l=1;l<=n;l++)
        {
            string temp=s.substr(idx,l);
            if(st.find(temp)!=st.end() && solve(idx+l,s))
            {
                return t[idx]=true;
            }
        }
        return t[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        n=s.length();
        memset(t,-1,sizeof(t));
        for(const string& x:wordDict)
        {
            st.insert(x);
        }
        return solve(0,s);
    }
};


/*
class Solution 
{
public:
    map<string,int>m;
    bool help(int i,string &s,vector<int>&dp)
    {
        if(i==s.size())return true;
        if(dp[i]!=-1)return dp[i];
        bool ans = false;
        string a = "";
        for(int k=i;k<s.size();k++){
            a += s[k];
            if(m[a]){
                ans |= help(k+1,s,dp);
            }
        }
        return  dp[i] = ans;
    }
    bool wordBreak(string s, vector<string>& w) 
    {
        for(auto i:w)
        {
            m[i]++;
        }
        vector<int>dp(s.size(),-1);
        return help(0,s,dp);
    }
};
*/