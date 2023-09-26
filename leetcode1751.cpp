//1751. Maximum Number of Events That Can Be Attended II

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//https://youtu.be/OuIjDrFA9_M
//DeepCodes

//Time complexity: O(n log n) + O(nk)
//Space Complexity: O(n) + O(nk) + recursive stack

class Solution 
{
public:
//binary search to find next index
    vector <int> dpIdx;
    vector<vector<int>> dp;
    int findNxt(vector<vector<int>>& events,int idx)
    {
        if(dpIdx[idx]!=-1) 
        {
            return dpIdx[idx];
        }
        int l=idx+1;
        int r=events.size()-1;
        int end=events[idx][1];
        int ans=r+1;

        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(events[mid][0]>end)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return dpIdx[idx]=ans;

    }

    int solve(vector<vector<int>>& events,int k,int idx)
    {
        if(idx>=events.size() || k==0)
        {
            return 0;
        }

        if(dp[idx][k]!=-1)
        {
            return dp[idx][k];
        }

        int op1=0;
        int op2=0;
        int nxtIdx = findNxt(events,idx);
        op1=events[idx][2] + solve(events,k-1,nxtIdx);

        op2=solve(events,k,idx+1);

        return dp[idx][k]=max(op1,op2);
    }

    int maxValue(vector<vector<int>>& events, int k) 
    {
        sort(events.begin(),events.end());
        int n=events.size();
        dpIdx.resize(n+1,-1);
        dp.resize(n+1,vector<int>(k+1,-1));
        return solve(events,k,0);
    }
};