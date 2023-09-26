//77. Combinations

//this below ques. is something else,please figure out what follow up is this 
//Ques)Given an integer array that may contain duplicates, return all possible subsets(the power set).The solution set must not contain duplicate subsets. Return the solution in any order.



/*
//bhavesh
class Solution 
{
public:

void solve(int n, int k, int num, vector<int> &sub_ans, vector<vector<int>> &ans)
{
        if(k==0)
        {
            ans.push_back(sub_ans);
            return;
        }
        if(num == n+1) return;
        
        
        solve(n,k,num+1,sub_ans,ans);
        
        sub_ans.push_back(num);
        solve(n,k-1,num+1,sub_ans,ans);
        sub_ans.pop_back();
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> sub_ans;
        
        solve(n,k,1,sub_ans,ans);
        
        return ans;
    }

     
};
*/






/*
//codestorywithMIK METHOD1
//backtracking

class Solution 
{
public:

    vector<vector<int>> ans;

    void solve(int idx,int n,int k,vector<int>& ds)
    {
        //base conditions
        if(k==0)
        {
            ans.push_back(ds);
            return;
        }

        if(idx>n) return;

        ds.push_back(idx);
        solve(idx+1,n,k-1,ds);

        ds.pop_back();
        solve(idx+1,n,k,ds);


    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int>ds;
        solve(1,n,k,ds);

        return ans;
    }
};



//codestorywithMIK METHOD2
class Solution 
{
public:

    vector<vector<int>> ans;

    void solve(int idx,int n,int k,vector<int>& ds)
    {
        if(k==0)
        {
            ans.push_back(ds);
            return;
        }

        for(int i=idx;i<=n;i++)
        {
            ds.push_back(i);
            solve(i+1,n,k-1,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int>ds;
        solve(1,n,k,ds);

        return ans;
    }
};
*/


//trial error (figure out what is the mistake??)
class Solution 
{
public:
    vector<vector<int>> ans;

    void solve(int idx,int opt,int n,int k,vector<int>& ds)
    {   /* //initially
        //base condition
        if(idx>=k)
        {
            if(opt<=n)
            {
                ans.push_back(ds);
            }
            return;
        }
        */

        
/*
        //changed base case1 (still wrong)
          if(opt>n) return;
            if(idx>=k)
            {
            ans.push_back(ds);
            return;
            }
*/
        


        //changed base case 2 (correct)
        
        if(idx>=k)
        {
            ans.push_back(ds);
            return;
        }
        if(opt>n) return;
        
        
        //take
        ds.push_back(opt);
        solve(idx+1,opt+1,n,k,ds);
        //not take
        ds.pop_back();
        solve(idx,opt+1,n,k,ds);

    }

    vector<vector<int>> combine(int n, int k) 
    {
        vector<int>ds;
        solve(0,1,n,k,ds);
        return ans;
    }
};








 //=====================================================================================

 //BHAVESH's APPROACH
 /*
class Solution 
{
public:

void solve(int n, int k, int num, vector<int> &sub_ans, vector<vector<int>> &ans)
{
        if(k==0)
        {
            ans.push_back(sub_ans);
            return;
        }
        if(num == n+1) return;
        
        
        solve(n,k,num+1,sub_ans,ans);
        
        sub_ans.push_back(num);
        solve(n,k-1,num+1,sub_ans,ans);
        sub_ans.pop_back();
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> sub_ans;
        
        solve(n,k,1,sub_ans,ans);
        
        return ans;
    }

     
};
*/


#include<bits/stdc++.h>
using namespace std;
 //codestorywithMIK METHOD1
//backtracking

class Solution 
{
public:

    vector<vector<int>> ans;

    void solve(int idx,int n,int k,vector<int>& ds)
    {
        //base conditions
        if(k==0)
        {
            ans.push_back(ds);
            return;
        }

        if(idx>n) return;

        ds.push_back(idx);
        solve(idx+1,n,k-1,ds);

        ds.pop_back();
        solve(idx+1,n,k,ds);


    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int>ds;
        solve(1,n,k,ds);

        return ans;
    }
};


/*
//codestorywithMIK METHOD2
class Solution 
{
public:

    vector<vector<int>> ans;

    void solve(int idx,int n,int k,vector<int>& ds)
    {
        if(k==0)
        {
            ans.push_back(ds);
            return;
        }

        for(int i=idx;i<=n;i++)
        {
            ds.push_back(i);
            solve(i+1,n,k-1,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int>ds;
        solve(1,n,k,ds);

        return ans;
    }
};
*/

/*
//trial error (figure out what is the mistake??)
class Solution 
{
public:
    vector<vector<int>> ans;

    void solve(int idx,int opt,int n,int k,vector<int>& ds)
    {
        //base condition
        if(idx>=k)
        {
            if(opt<=n)
            {
                ans.push_back(ds);
            }
            return;
        }

        ds.push_back(opt);
        solve(idx+1,opt+1,n,k,ds);

        ds.pop_back();
        solve(idx,opt+1,n,k,ds);

    }

    vector<vector<int>> combine(int n, int k) 
    {
        vector<int>ds;
        solve(0,1,n,k,ds);
        return ans;
    }
};
*/