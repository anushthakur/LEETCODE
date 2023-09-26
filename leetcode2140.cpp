
//2140. Solving Questions With Brainpower


#include<bits/stdc++.h>
using namespace std;

//TRIAL
//RECURSION GIVING TIME LIMIT EXCEEDED
class Solution 
{
 public:

 int fun(vector<vector<int>>& questions,int idx,int n,int s)
 {
     if(idx>=n) return s;

    s+=questions[idx][0];
    int l=fun(questions,idx+questions[idx][1]+1,n,s);

    s-=questions[idx][0];
    int r=fun(questions,idx+1,n,s);
    

    return max(l,r);
     
 }

    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n=questions.size();
        long long ans=fun(questions,0,n,0);

        return ans;
    }
};


//ERROR IN MEMOIZATION AND CHECK RECURSION
//TRIAL

class Solution 
{
 public:
 
 
 long long fun(vector<vector<int>>& questions,int idx,int n,int s, vector<long long>& t)
 {
     if(idx>=n) return s;

    if(t[idx]!=-1) return t[idx];

    s+=questions[idx][0];
    long long l=fun(questions,idx+questions[idx][1]+1,n,s,t);
    
  

    s-=questions[idx][0];
    long long r=fun(questions,idx+1,n,s,t);
    
    

    return t[idx]= max(l,r);
     
 }

    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n=questions.size();
       vector<long long> t(n+1,-1);
        long long ans=fun(questions,0,n,0,t);

        return ans;
    }
};

//********************************************************************************************


//DYNAMIC PROGRAMMING:RECURSION + MEMOIZATION(YOUTUBE CodestorywithMIK)
//https://youtu.be/NcC8lo7nLCE

//TIME COMPLEXITY:O(n) ,(going to every i exactly once due to t vector)
//SPACE COMPLEXITY:O(n) ,(for t vector)

class Solution 
{
 public:
 
 
 long long fun(vector<vector<int>>& questions,int idx,int n, vector<long long>& t)
 {
     if(idx>=n) return 0;

    if(t[idx]!=-1) return t[idx];

    
    long long l=questions[idx][0] + fun(questions,idx+questions[idx][1]+1,n,t);
    
  
    long long r=fun(questions,idx+1,n,t);
    
    

    return t[idx]= max(l,r);
     
 }

    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n=questions.size();
       vector<long long> t(n+1,-1);
        long long ans=fun(questions,0,n,t);

        return ans;
    }
};