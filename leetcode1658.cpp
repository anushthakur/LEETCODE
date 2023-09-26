//1658. Minimum Operations to Reduce X to Zero

#include<bits/stdc++.h>
using namespace std;
//https://youtu.be/HddgLcq9Efs
//techdose

//APPROACH 1 RECURSION  (TLE)
//TC:O(2^N)

class Solution 
{
public:
  
  
    int solve(vector<int>& nums,int x,int i,int j,int count)
    {   //base cases
        if(i>j || x<0) return 1e6;
        if(x==0) 
        {
            return count;
        }
        //WRONG ANSWER 9/95
        //[8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309]
        //x:134365
        //output:-1
        //expected:16
        

        //take front
        int left=solve(nums,x-nums[i],i+1,j,count+1);
        //take back
        int right=solve(nums,x-nums[j],i,j-1,count+1);

        return min(left,right);

    }
    int minOperations(vector<int>& nums, int x) 
    {
       
        
         int ans=solve(nums,x,0,nums.size()-1,0);
         return (ans>=1e6)? -1:ans;

    }
};

//BASE CASE KO THODA OOPER NEECHE KIYA TOH ACCEPT HO RHA HAI
class Solution 
{
public:
  
  
    int solve(vector<int>& nums,int x,int i,int j,int count)
    {   //base cases
        if(x==0) 
        {
            return count;
        }
        if(i>j || x<0) return 1e6;
        
        

        //take front
        int left=solve(nums,x-nums[i],i+1,j,count+1);
        //take back
        int right=solve(nums,x-nums[j],i,j-1,count+1);

        return min(left,right);

    }
    int minOperations(vector<int>& nums, int x) 
    {
       
        
         int ans=solve(nums,x,0,nums.size()-1,0);
         return (ans>=1e6)? -1:ans;

    }
};


//APPROACH 2 DP (as there are repeating subproblems and optimal substructures) (recursion + memoization (i.e. top-down))  still TLE
//TC: polynomial
class Solution 
{
public:
    unordered_map <string,int> mp;
  //DP (top down)
    int solve(vector<int>& nums,int x,int i,int j,int count)
    {   //base cases
        if(x==0) 
        {
            return count;
        }
        if(i>j || x<0) return 1e6;
        string s=to_string(i) + "*" + to_string(j) + "*" + to_string(x);
        if(mp.find(s)!=mp.end()) return mp[s];
        
        

        //take front
        int left=solve(nums,x-nums[i],i+1,j,count+1);
        //take back
        int right=solve(nums,x-nums[j],i,j-1,count+1);

        return mp[s]=min(left,right);

    }
    int minOperations(vector<int>& nums, int x) 
    {
       
        
         int ans=solve(nums,x,0,nums.size()-1,0);

         return (ans>=1e6)? -1:ans;

    }
};


//APPROACH 3 
//TC:O(N)
// SC:O(N)
//codestorywithMIK
class Solution 
{
    //prefix sum + hashmap
public:
    int minOperations(vector<int>& nums, int x) 
    {
        unordered_map <int,int> mp; //<sum>,<index>
        mp[0]=-1; //incase we need to remove a subarray whose sum is 0 ,look at the constraints.
        //hashmap mein store kar liya prefix sum  particular indexes tak ke.
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            mp[sum]=i;
        }
         if(sum<x) return -1;
        int need=sum-x; //our task is to maximize the length of subarray whose sum is "need";
         sum=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int findsum=sum-need;
            if(mp.find(findsum)!=mp.end()) 
            {
                ans=max(ans,(i-mp[findsum]));
            }
        }
        return ans==INT_MIN?-1:nums.size()-ans;
    }
};
