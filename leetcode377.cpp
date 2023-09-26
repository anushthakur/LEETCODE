//377. Combination Sum IV
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:

    int n;
    int dp[201][1001]; //jitne variables mein change ho raha hai utne dimension ki dp array. Here target variable and idx variable were changing.

    int solve(int idx,int end,vector<int>& nums, int target)
    {
        //base cases
        if(target==0) return 1;
        if(idx>end || target<0) return 0;
        if(dp[idx][target]!=-1) return dp[idx][target];

        //take

        //int take_idx because har ek recursion call bhale hi uske within kitne hi call stacks ho,uske liye apna ek alag variable hona chahiye,naaki har recursion call ke liye ek hi.

       int take_idx= solve(0,end,nums,target-nums[idx]);


        //not take
        int reject_idx=solve(idx+1,end,nums,target);

        return dp[idx][target]=take_idx+reject_idx; //take karke kitne tareeke mile plus reject karke kitne tareeke mile vo total count return kar denge.
    }

    int combinationSum4(vector<int>& nums, int target) 
    {
        n=nums.size()-1;
        memset(dp,-1,sizeof(dp));
        return solve(0,n,nums,target);
        
    }
};

//THIS SAME CAN BE DONE USING A FOR LOOP WHERE WE JUST NEED TO WRITE THE TAKE CASE WITHIN THE LOOP AND THE REJECTION CASE IS AUTOMATICALLY PERFORMED BY THE FOR LOOP ITSELF.(not written the code for that here yet.)
//refer codestorywithMIK for best understanding.


/*
class Solution 
{
public:
//TRIAL TLE for only recursion/backtracking(as time complexity is exponential,so trying DP)
    int ans=0;
    

    void solve(int index,int end,vector<int>& nums,int target,int count)
    {
        //base conditions
        if(count>=target)
        {
            if(count==target)
            {
                ans++;
            }
            return;
        }
        if(index>end) return;
        


        //take
        // solve(index,end,nums,target,count+nums[index]);
        solve(0,end,nums,target,count+nums[index]); //0 because  fir se starting index vala element bhi option mein aana chaiye.

        //not take
        solve(index+1,end,nums,target,count);
    }

    int combinationSum4(vector<int>& nums, int target) 
    {
        
        int n=nums.size()-1;
         solve(0,n,nums,target,0);
         return ans;
    }
};
*/

