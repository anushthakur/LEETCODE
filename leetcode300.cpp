//300. Longest Increasing Subsequence

#include<bits/stdc++.h>
using namespace std;

//codestorywithMIK ***********************

//DP
//TC:O(N^2)
class Solution 
{
public:
    int n;
    int t[2501][2501]; //2501 * 2501 unique states now,and only these have to be calculated,otherwise without memoization 2^N states were being calculated among which many were repeating,which is sheer waste of time.
    //2D array as index and previous (i.e. 2 variables were changing throughout)

    int solve(int i,int p,vector<int>& nums)
    {
        //base case
        if(i>=n) return 0;
        if(p!=-1 && t[i][p]!=-1) return t[i][p];

        //take
        int take=0;
        if(p==-1 || nums[p]<nums[i])
        {
            take =1 + solve(i+1,i,nums);
        }
        //not take
            int not_take =solve(i+1,p,nums);

            if(p!=-1) t[i][p]=max(take,not_take);
            return max(take,not_take);
    }

    int lengthOfLIS(vector<int>& nums) 
    {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,-1,nums);
    }
};