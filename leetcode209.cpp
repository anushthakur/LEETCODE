//209. Minimum Size Subarray Sum

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std; 
/*
//Sliding window
//TC:O(N)
//SC:O(1)
class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int i=0;
        int j=0;
        int sum=0;
        int ans=INT_MAX;
        while(j<nums.size())
        {
            sum+=nums[j];
            while(sum>=target) //window ko chota karke dekh rhe
            {
                ans=min(ans,(j-i+1));
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return ans==INT_MAX?0:ans;
    }
};

*/

//https://youtu.be/X8IyQRiDvLw
//TC:O(NLOG(N))
//SC:O(N)
class Solution 
{
public:
//prefix sum + binary search
//techcoder avi
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        
       vector<int> presum(nums.size()+1,0); //0th index par 0 rakha rahega
      
       for(int i=0;i<nums.size();i++)
       {
           presum[i+1] +=presum[i] + nums[i];
       }

       
        
       
        int ans=INT_MAX;
         //binary search on presum array for each value of i
        for(int i=1;i<presum.size();i++)
        {
            int l=i;
            int r=presum.size()-1;
            while(l<=r)
            {
                int mid=l + (r-l)/2;
                if(presum[mid]-presum[i-1]>=target)
                {
                    ans=min(ans,mid-(i-1));
                    r=mid-1;
                }
                else l=mid+1;
            }

        }
        if(ans==INT_MAX) return 0;
        else return ans;

    }
};



