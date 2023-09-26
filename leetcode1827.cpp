//1827. Minimum Operations to Make the Array Increasing

#include<bits/stdc++.h>
using namespace std;

//TRIAL
class Solution 
{
public:
    int minOperations(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1) return 0;
        int count=0;

        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1])
            {
                int x=abs(nums[i]-nums[i-1]);
                nums[i]+=x+1;
                count+=x+1;
            }
        }
        return count;
    }
};