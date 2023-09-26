//46. Permutations


#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
vector<vector<int>> ans;
int n;

    void solve(int idx,vector<int>& nums)
    {
        //base condition
        if(idx==n)
        {
            ans.push_back(nums);
            return;
        }

        for(int i=idx;i<n;i++)
        {
            //swap
            int temp1=nums[idx];
            nums[idx]=nums[i];
            nums[i]=temp1;

            solve(idx+1,nums);

            //undo changes
            int temp2=nums[idx];
            nums[idx]=nums[i];
            nums[i]=temp2;

        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        
        n=nums.size();
        solve(0,nums);
        return ans;
    }
};


//TIME COMPLEXITY: O(N*N!)
//codestorywithmik
class Solution 
{
public:
    int n;
    vector<vector<int>> ans;
    unordered_set <int> st; //taking unordered_set and not a vector to mark what element has been taken as in unordered_set seraching is O(1) operation and in ordered_set O(logn) and in vector O(n) for each element.
    void solve(vector<int>& ds,vector<int>& nums)
    {
        //base condition
        if(ds.size()==n)
        {
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(st.find(nums[i])==st.end())
            {
                ds.push_back(nums[i]);
                st.insert(nums[i]);

                solve(ds,nums);

                ds.pop_back();
                st.erase(nums[i]);
                /*
                    Erase by value: This version takes the value of the element you want to delete as an argument and removes that element from the unordered_set.

Erase by iterator: This version takes an iterator pointing to the element you want to delete and removes that element from the unordered_set.
                */
          }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        n=nums.size();
        vector<int>ds;
        solve(ds,nums);
        return ans;
    }
};




/*
//TRIAL  (WRONG)
class Solution 
{
public:
    int n;
    void solve(int startidx,int n,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans,vector<bool>& v)
    {
        //base condition
        if(startidx>=n) 
        {
            ans.push_back(ds);
            return;
        }

    //take
        ds.push_back(nums[startidx]);
        v[startidx]=true;
        solve(startidx+1,n,nums,ds,ans,v);
    //not take
        ds.pop_back();
        solve(startidx+1,)    
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<bool>v(nums.size(),false);
        vector<vector<int>> ans;
        vector<int> ds;
        n=nums.size();
        solve(0,n,nums,ds,ans,v);
        return ans;
    }
};
*/